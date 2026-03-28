#include "uart.h"

#include <string.h>

void uart_send(const UART_HandleTypeDef huart, const char *msg){
    HAL_UART_Transmit(&huart, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
}
