#include <Wire.h>
#include <Arduino.h>

#define SLAVE_ADDR 0x08
uint8_t lightValue = 123;

void setup() {
    Serial.begin(9600);  // open Serial monitor
    Wire.begin(SLAVE_ADDR);
    Wire.onRequest([]() {
        Wire.write(lightValue);
        // Serial.println("Sent 123 over I2C");  // debug
    });
}

void loop() {
    // nothing needed
}