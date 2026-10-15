# Smart Parking Barrier System

A first-semester Arduino prototype demonstrating distance-based barrier control using an ultrasonic sensor and a servo motor.

## Overview

The HC-SR04 ultrasonic sensor measures the distance to an object. The Arduino UNO checks that measurement and commands a servo motor to open or close a small barrier.

This is an educational prototype, not a production-ready or safety-certified parking gate.

## Components

- Arduino UNO
- HC-SR04 ultrasonic sensor
- Servo motor (Wokwi model / small hobby servo)
- Jumper wires
- Breadboard and physical road/barrier model for the demonstration

## Pin connections

| Component pin | Arduino UNO |
|---|---|
| HC-SR04 VCC | 5V |
| HC-SR04 GND | GND |
| HC-SR04 TRIG | D9 |
| HC-SR04 ECHO | D10 |
| Servo V+ | 5V (simulation) |
| Servo GND | GND |
| Servo PWM / signal | D6 |

## Behaviour in the current code

- Starts with the barrier at 0° (closed).
- Opens to 90° when a valid distance measurement is below 20 cm.
- Closes after 2 seconds without another near-distance detection.
- Prints distance and state messages to the Serial Monitor.

## Files

- `SmartParkingBarrier.ino` — Arduino sketch.
- `diagram.json` — Wokwi circuit configuration.
- `Circuit-Diagram.png` — screenshot of the Wokwi circuit layout.
- `Circuit-Illustration-Concept.png` — AI-generated illustrative graphic; use as a concept visual only, not as a verified wiring reference.
- `Project-Demo.mp4` — physical prototype demonstration video, if included.

## Run in Wokwi

Open the project: https://wokwi.com/projects/477968862679671809

If importing manually, create an Arduino UNO project, then use the supplied sketch and diagram configuration.

## Limitations and safety note

This is a simple demonstration. The closing logic is based on the sensor's last near-distance detection; it does not independently confirm that a vehicle has fully cleared the barrier. A real installation would require additional clearance/obstruction detection and a suitable servo power supply. For physical hardware, avoid powering a servo from the Arduino 5V pin if its current draw causes instability; use a suitable regulated supply and common ground.

## Learning focus

- Ultrasonic sensor interfacing
- Distance measurement
- Servo control
- Arduino programming
- Basic hardware–software integration
