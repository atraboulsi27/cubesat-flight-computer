#ifndef UART_H
#define UART_H

#include "stm32f4xx_hal.h"
#include <stdbool.h>

void uart_send(UART_HandleTypeDef *huart, const char *msg);
bool uart_is_busy(void);

#endif
