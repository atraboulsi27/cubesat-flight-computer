# cubesat-flight-computer
This project is implementing a minimal version of a CubeSat-inspired onboard computer (OBC) using an STM32 microcontroller, with an Arduino-based subsystem communicating over I2C. This project demonstrates reading light data from a **photoresistor** connected to an **Arduino Uno** and sending it to an **STM32 Nucleo board** via **I2C**. The STM32 then outputs the readings over **UART** for monitoring.

## Hardware

- **STM32 Nucleo** (master)
- **Arduino Uno** (slave)
- **Photoresistor** (connected to Arduino A0)
- **10kΩ resistor** (voltage divider with photoresistor)
- Breadboard and connecting wires

### Connections

**I2C:**

| STM32 Pin | Arduino Pin |
|-----------|-------------|
| D14 / PB8 (SCL) | A5 |
| D15 / PB9 (SDA) | A4 |
| GND | GND |

**Photoresistor circuit on Arduino:**
5V --- Photoresistor ---+--- A0 (Arduino)
|
10kΩ
|
GND

## Software

- **STM32:** STM32CubeIDE / HAL, reads I2C from Arduino and outputs via UART.
- **Arduino:** PlatformIO / Arduino framework, reads photoresistor and responds to I2C requests.

### Arduino Code

- Sets up I2C slave at address `0x08`.
- Sends photoresistor reading to STM32 when requested.
- Optional `Serial.println()` for debugging.

### STM32 Code

- I2C master configured on `hi2c1`.
- Requests 1 byte from Arduino every second.
- Sends result over UART (`LIGHT:<value>`).
- Handles errors with `EVENT:NONE`.

## Usage

1. Connect hardware as shown.
2. Upload Arduino code via PlatformIO.
3. Flash STM32 firmware.
4. Open STM32 UART monitor to see light readings.
5. Adjust lighting and observe changes in `LIGHT:<value>`.

## Circuit Figure
 <img width="600" height="300" alt="circuit" src="https://github.com/user-attachments/assets/2dcf916c-9575-49ba-a241-b2fbae94348b" />

