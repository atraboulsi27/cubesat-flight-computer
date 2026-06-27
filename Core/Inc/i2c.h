#ifndef I2C_H
#define I2C_H

#include "stm32f4xx_hal.h"
#include <stdbool.h>

bool request_light_value(uint8_t *value);

#endif
