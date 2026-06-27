#include "i2c.h"
#include <stdint.h>

#define ARDUINO_ADDR 0x08
extern I2C_HandleTypeDef hi2c1;

bool request_light_value(uint8_t *value)
{
    if (value == NULL) {
        return false;
    }

    return HAL_I2C_Master_Receive(&hi2c1, ARDUINO_ADDR << 1, value, 1, 100) == HAL_OK;
}
