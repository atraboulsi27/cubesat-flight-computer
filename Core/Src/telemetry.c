#include "telemetry.h"
#include "i2c.h"
#include "uart.h"
#include <stdio.h>
#include <stdint.h>

extern UART_HandleTypeDef huart2; // ensure the UART handle is visible

void telemetry_send(void)
{
    char buffer[64];
    static uint32_t sequence = 0;
    uint8_t light = 0;
    const char *mode = "NOMINAL";

    if (request_light_value(&light)) {
        snprintf(buffer, sizeof(buffer), "SEQ:%lu MODE:%s LIGHT:%u",
                 (unsigned long)sequence++, mode, (unsigned int)light);
    } else {
        snprintf(buffer, sizeof(buffer), "SEQ:%lu MODE:%s EVENT:NONE",
                 (unsigned long)sequence++, mode);
    }

    uart_send_line(&huart2, buffer);
}
