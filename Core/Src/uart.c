#include "uart.h"
#include <string.h>

#define UART_TX_BUFFER_SIZE 128

static uint8_t tx_buffer[UART_TX_BUFFER_SIZE];
static volatile bool tx_busy = false;

bool uart_is_busy(void)
{
    return tx_busy;
}


void uart_send(UART_HandleTypeDef *huart, const char *msg){

	if (tx_busy || msg == NULL) {
		return;
	}

    size_t msg_len = strlen(msg);
    memcpy(tx_buffer, msg, msg_len);
    tx_buffer[msg_len] = '\r';
    tx_buffer[msg_len + 1] = '\n';

    tx_busy = true;


    if (HAL_UART_Transmit_IT(huart, tx_buffer, msg_len + 2) != HAL_OK)
    {
        tx_busy = false;
    }
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART2)
    {
        tx_busy = false;
    }
}
