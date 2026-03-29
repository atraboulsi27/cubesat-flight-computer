#include "i2c.h"
#include "uart.h"

#define ARDUINO_ADDR 0x08  // Arduino I2C address
extern I2C_HandleTypeDef hi2c1;
extern UART_HandleTypeDef huart2;


void request_light_value(void) {
    uint8_t value = 0;

    if(HAL_I2C_Master_Receive(&hi2c1, ARDUINO_ADDR << 1, &value, 1, 100) == HAL_OK) {
        char buf[32];
        sprintf(buf, "LIGHT:%d", value);
        uart_send_line(&huart2, buf);
    } else {
        uart_send_line(&huart2, "EVENT:NONE");
    }
}
