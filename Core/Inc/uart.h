#ifndef UART_H
#define UART_H

#include "stm32f4xx_hal.h"

void uart_send(UART_HandleTypeDef *huart, const char *msg);
void uart_send_line(UART_HandleTypeDef *huart, const char *msg);

#endif
