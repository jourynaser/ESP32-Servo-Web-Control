# ESP32 Servo Web Control

## Project Description

This project is a simple simulation using an ESP32 to control a servo motor through a web page.

The ESP32 creates its own Wi-Fi Access Point and runs a small web server. From the web page, the user can open or close the servo motor.

Two LEDs are also used to show the current state of the servo. The green LED turns on when the servo is open, and the red LED turns on when it is closed.

The project was created and tested using Wokwi.

## Components

- ESP32
- Servo Motor
- Green LED
- Red LED
- 2 Resistors
- Jumper Wires

## Connections

| Component | ESP32 Pin |
|-----------|-----------|
| Servo Motor | GPIO 13 |
| Green LED | GPIO 26 |
| Red LED | GPIO 27 |

The servo motor is also connected to power and ground.

## How It Works

When the simulation starts, the ESP32 creates a Wi-Fi network called:

`ESP32-Servo-Control`

The ESP32 also starts a web server.

The web page has controls for opening and closing the servo motor.

When **Open** is selected:

- The servo moves to the open position.
- The green LED turns on.
- The red LED turns off.

When **Close** is selected:

- The servo moves to the closed position.
- The red LED turns on.
- The green LED turns off.

The Serial Monitor also displays the commands received by the ESP32.

## Files

- `sketch.ino` - ESP32 code and web page
- `diagram.json` - Wokwi circuit connections
- `libraries.txt` - Required library information
- `demo.mp4` - Video showing the project working
- `README.md` - Project documentation

## Library

The project uses the ESP32Servo library to control the servo motor.

## Simulation

The project can be tested using Wokwi:

https://wokwi.com/projects/471788416421634049

## Demo Video

A short video showing the project simulation and how the servo motor responds to the Open and Close commands.

[Watch the Demo Video](demo.mp4)

