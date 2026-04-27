# Smart Human-Aware Access and Safety System Using Arduino

##  Project Overview

This project presents an advanced embedded system designed to simulate intelligent human-aware access control through hybrid sensing and behavioral analysis. The system combines PIR-based thermal motion detection, ultrasonic distance measurement, and Arduino-based decision-making to approximate person detection more effectively than a basic single-sensor system.

Unlike traditional object detection systems, this project integrates multiple sensing layers and software logic to improve reliability, reduce false activation, and create a more realistic smart security and access platform.


##  Project Objective

The objective of this project is to design and implement a smart embedded system capable of detecting human-like presence using sensor fusion and behavioral logic.

The system aims to:

* Detect motion through thermal sensing (PIR)
* Measure precise object distance (Ultrasonic Sensor)
* Analyze interaction patterns over time
* Control automated access using a servo motor
* Activate safety alerts using relay and buzzer
* Provide real-time visual system feedback


##  Components Used

* Arduino Uno R3
* PIR Motion Sensor
* Ultrasonic Sensor (HC-SR04)
* Micro Servo Motor
* Relay Module (5V)
* Buzzer
* LEDs (Red & Green)
* Resistors
* Breadboard
* Jumper Wires

##  Core System Concept

The system uses a hybrid detection strategy:

### 1. PIR Sensor

Detects motion based on infrared radiation (body heat), improving human-oriented detection.

### 2. Ultrasonic Sensor

Measures proximity and validates distance thresholds.

### 3. Behavioral Logic

The Arduino analyzes:

* Gradual approach
* Presence duration
* Distance stability
* Multi-condition validation

This allows the system to respond more intelligently than a simple sensor trigger.


##  System Operation

###  Normal State

* No valid human-like presence detected
* Green LED ON
* Door closed

###  Access State

* PIR detects motion
* Ultrasonic confirms valid distance
* Behavioral conditions satisfied
* Servo motor opens door

###  Alert State

* Critical proximity or abnormal condition detected
* Red LED ON
* Relay activated
* Buzzer ON


##  System Modules

### 1. Thermal Motion Detection Module

* PIR Sensor

### 2. Distance Measurement Module

* Ultrasonic Sensor (HC-SR04)

### 3. Control & Decision Module

* Arduino Uno R3

### 4. Access Control Module

* Micro Servo Motor

### 5. Alert & Safety Module

* Relay Module
* Buzzer

### 6. Feedback Module

* LEDs


##  Working Principle

The system uses sensor fusion, meaning activation depends on multiple validated conditions rather than a single trigger.

### Ultrasonic Distance Formula:

Distance = (Speed of Sound × Time) / 2

### Activation Logic Example:

* PIR = Motion detected
* Ultrasonic = Distance within threshold
* Behavior = Stable presence

Only when all required conditions are satisfied does the system grant access.


##  Engineering Domain

This project primarily belongs to:

* Embedded Systems
* Control Systems
* Smart Automation

It demonstrates hardware/software integration, real-time decision-making, and intelligent automation.


##  Technical Significance

This project goes beyond a simple automatic sensor system by implementing:

* Dual-sensor integration
* Sensor fusion
* Human-aware logic
* Real-time control
* Safety system design


##  Repository Structure

* `code/` → Arduino source code
* `circuit/` → Wiring diagrams and hardware images
* `proteus/` → Simulation files
* `docs/` → Reports and documentation


##  Project Status

Project proposal upgraded and approved conceptually for advanced implementation. Hardware integration and software development in progress.


##  Author

**Mouad Hnini**


