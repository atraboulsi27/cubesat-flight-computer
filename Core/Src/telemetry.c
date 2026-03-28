#include "telemetry.h"
#include "uart.h"
#include <stdio.h>

extern UART_HandleTypeDef huart2; // ensure the UART handle is visible

void telemetry_send(void)
{
    char buffer[64];
    int light = 123; // to be replaced
    const char* mode = "NOMINAL"; //to be replaced

    snprintf(buffer, sizeof(buffer), "MODE:%s", mode);
    uart_send_line(&huart2, buffer);

    snprintf(buffer, sizeof(buffer), "LIGHT:%d", light);
    uart_send_line(&huart2, buffer);

    uart_send_line(&huart2, "EVENT:NONE");
}
