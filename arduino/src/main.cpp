#include <Wire.h>
#include <Arduino.h>

#define SLAVE_ADDR 0x08

void setup() {
    Serial.begin(9600);        // debug
    Wire.begin(SLAVE_ADDR);    // join I2C bus as slave

    Wire.onRequest([]() {
        int sensorValue = analogRead(A0);      // 0-1023
        uint8_t valueToSend = sensorValue >> 2; // scale to 0-255
        Wire.write(valueToSend);
        Serial.print("Sent over I2C: ");
        Serial.println(valueToSend);
    });
}

void loop() {
    // nothing needed, handled in onRequest
    delay(100);
}
