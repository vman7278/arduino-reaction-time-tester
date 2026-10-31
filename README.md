# Arduino Reaction-Time Tester

An Arduino-based reaction-time game that measures how quickly a user responds to a visual stimulus. Built using an Arduino UNO R3, an LED, and a tactile pushbutton.

## Features

- **Reaction-Time Measurement:** Calculates response time in milliseconds using Arduino's `millis()` function.
- **Randomized LED Trigger:** Introduces a random 1–4 second delay to reduce anticipation.
- **False-Start Detection:** Detects button presses before the LED activates.
- **Three-Second Countdown:** Displays a countdown through the Serial Monitor before each round.
- **Personal-Best Tracking:** Records the fastest successful reaction time during the current session.
- **Serial Monitor Interface:** Displays results, countdowns, and feedback at 9600 baud.

## Hardware

- Arduino UNO R3
- Breadboard
- LED
- 220 Ω or 330 Ω resistor
- Tactile pushbutton
- Jumper wires
- USB cable

## Circuit Connections

| Component | Connection |
|---|---|
| LED anode (+) | Digital pin 8 through a current-limiting resistor |
| LED cathode (−) | GND |
| Pushbutton | Digital pin 2 and GND |

The pushbutton uses Arduino's internal pull-up resistor (`INPUT_PULLUP`), eliminating the need for an external button resistor.

## How It Works

1. The Arduino displays a three-second countdown.
2. A randomized waiting period begins.
3. Pressing the button prematurely triggers a false start.
4. The LED illuminates, signaling the user to react.
5. The Arduino measures the elapsed time between LED activation and button detection.
6. The reaction time and current personal best appear in the Serial Monitor.

## Engineering Concepts

This project demonstrates digital input/output, pull-up resistors, current limiting, pseudorandom timing, and elapsed-time measurement.

During prototyping, LED brightness was improved by adjusting the current-limiting resistance based on Ohm's law. Breadboard connection issues were also diagnosed and corrected through iterative testing.

## Software

Developed using Arduino IDE and the Arduino programming language (C/C++).

**Source code:** `ReactionTimeTester.ino`

## Future Improvements

- Button debouncing
- Reaction-time statistics across multiple rounds
- LCD/OLED display integration
- More advanced scoring and game modes
