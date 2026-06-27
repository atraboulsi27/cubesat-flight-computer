#include "telemetry.h"
#include "i2c.h"
#include "uart.h"
#include <stdio.h>
#include <stdint.h>

extern UART_HandleTypeDef huart2; // ensure the UART handle is visible

/**
 * LOW_POWER means the spacecraft is in a dim-light or eclipse-like condition.
 * CRUISE means normal operating light levels.
 * SCIENCE means bright conditions where the payload is actively collecting data.
 */
static const char *select_mode(uint8_t light)
{
    if (light < 20) {
        return "LOW_POWER";
    }

    if (light < 30) {
        return "CRUISE";
    }

    return "SCIENCE";
}

void telemetry_send(void)
{
    char buffer[64];
    static uint32_t sequence = 0;
    uint8_t light = 0;

    if (request_light_value(&light)) {
        const char *mode = select_mode(light);

        snprintf(buffer, sizeof(buffer), "SEQ:%lu MODE:%s LIGHT:%u",
                 (unsigned long)sequence++, mode, (unsigned int)light);
    } else {
        snprintf(buffer, sizeof(buffer), "SEQ:%lu MODE:%s EVENT:NONE",
                 (unsigned long)sequence++, "UNKNOWN");
    }

    uart_send_line(&huart2, buffer);
}
