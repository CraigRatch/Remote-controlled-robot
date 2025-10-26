# Remote-controlled-robot
Remote-controlled robot using Arduino and L298N motor driver, controlled via app commands.

# Remote Control Robot using App
**Author:** Craig Ratchford

## Overview
This project implements a remote-controlled robot using an Arduino and L298N motor driver. The robot receives single-character commands from an app (via Serial/Bluetooth) to move forward, backward, turn left, turn right, or stop. It demonstrates motor control, serial communication, and basic robotics navigation. This was all part of my testing phase for my final year project studying Electronic Engineering. 

---

## Features
- Move forward, backward, turn left, turn right, and stop
- Controlled via an app sending single-character commands
- Real-time command feedback via Serial Monitor
- Uses L298N motor driver for dual DC motors

---

## Hardware Required
- Arduino (e.g., Uno, Mega)
- L298N Motor Driver
- 2 DC Motors
- Power supply for motors
- Bluetooth module (optional, e.g., HC-05/HC-06)
- Jumper wires and breadboard

---

## Software / Libraries
- Arduino IDE
- Built-in `Arduino.h` library

---

## Wiring / Pin Configuration
| Component          | Arduino Pin |
|-------------------|-------------|
| Motor IN1 (M1A)    | 11          |
| Motor IN2 (M1B)    | 7           |
| Motor IN3 (M2A)    | 8           |
| Motor IN4 (M2B)    | 9           |
| Motor ENA          | 10          |
| Motor ENB          | 11          |
| Built-in LED       | 13          |
| Serial Input       | Serial1 (RX/TX via Bluetooth) |

---

## App Commands
| Command | Action         |
|---------|----------------|
| `f`     | Move forward   |
| `b`     | Move backward  |
| `r`     | Turn right     |
| `z`     | Turn left      |
| `s`     | Stop motors    |

---

## How It Works
1. The Arduino continuously listens for commands from the app over Serial1.
2. When a command is received, the corresponding motor function is executed:
   - `moveForward()`, `back()`, `turnRight()`, `turnLeft()`, or `stopMotors()`.
3. The Serial Monitor prints the received command for debugging.
4. Motor speeds are controlled via PWM using the ENA and ENB pins.

---

## Usage
1. Connect your motors, motor driver, and Bluetooth module according to the wiring table.
2. Upload the code to your Arduino using the Arduino IDE.
3. Open the app and send commands to control the robot.
4. Monitor the Serial Monitor for feedback.

---

## Notes
- Ensure the Bluetooth module and motors share a common ground with Arduino.
- Adjust PWM values in the code for smoother movement depending on motor specifications.

---

## License
This project is open-source and free to use for educational purposes.

