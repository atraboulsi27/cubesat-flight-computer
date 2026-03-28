#ifndef UART_H
#define UART_H

#include "stm32f4xx_hal.h"

void uart_send(const UART_HandleTypeDef huart, const char *msg);

#endif
