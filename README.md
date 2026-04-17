# Smart-access-system-arduino
Arduino-based smart access and safety system using ultrasonic sensor, servo motor, relay, and LEDs


## Project Overview

This project presents a smart embedded system that automatically controls access based on distance measurement using an ultrasonic sensor. The system simulates a smart door combined with a safety alert mechanism.

## Objective

To design and implement an intelligent system that detects object proximity and responds by controlling a servo motor, activating a relay, and providing visual feedback using LEDs.


## Components Used

* Arduino Uno R3
* Ultrasonic Sensor (HC-SR04)
* Micro Servo Motor
* Relay Module (5V)
* LEDs (Red & Green)
* buzzer
* Resistors
* Breadboard & Jumper Wires


## System Operation

The system continuously measures distance using the ultrasonic sensor and reacts based on predefined thresholds:

 **Distance > 20 cm**

  * Door remains closed
  * Green LED ON

 **Distance between 10 cm and 20 cm**

  * Servo motor opens the door

 **Distance < 10 cm (Alert Condition)**

  * Red LED ON
  * Relay activated (alarm/light)



## System Modules

1. Distance Measurement Module (Ultrasonic Sensor)
2. Control Module (Arduino)
3. Actuator Module (Servo Motor)
4. Alert Module (Relay)
5. Feedback Module (LED Indicators, Buzzer)


##  Working Principle

The ultrasonic sensor calculates distance using the time of flight of sound waves:

Distance = (Speed of Sound × Time) / 2

The Arduino processes this data and executes control actions accordingly.



## Repository Structure

* `code/` → Arduino source code
* `circuit/` → Hardware wiring images
* `proteus/` → Simulation files
* `docs/` → Additional documentation



## Project Status

Initial setup completed. System implementation in progress.



## Author

Mouad Hnini
