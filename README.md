# Drowsiness Monitor (IoT)

An IoT-based driver drowsiness monitoring system designed to enhance road safety. This project uses an Arduino Uno, an eye blink sensor, the Blynk cloud platform, and Python to monitor driver alertness and provide timely warnings in case of drowsiness.

## Features
- Monitors eye blink patterns to detect drowsiness.
- Alerts drivers when signs of drowsiness are detected.
- Real-time data visualization using the Blynk App.
- Cloud-based monitoring for remote safety checks.

Software Requirements Specification

**Arduino IDE**
Hardware Requirements Specification

**Ardino nano, Eye Blink Sensor, Relay module, 9v battery, Motor with Wheel, Breadboard, gogals**

## How It Works
1. The **eye blink sensor** detects the driver's eye blink frequency.
2. The sensor data is processed by the **Arduino Uno**.
3. If the blink frequency exceeds a threshold, the system classifies the driver as "Drowsy."
4. The **Blynk App** displays the status (`ALERT` or `DROWSY`) on a virtual pin.
5. The **Python script** triggers an alert or a warning message based on real-time data.

## Setting Up Blynk
1. Download the [Blynk App](https://blynk.io/) on your smartphone.
2. Create a new project and add a **Value Display** widget connected to `Virtual Pin V1`.
3. Note down the **Auth Token** from the app.
4. Replace the placeholder in the Arduino code with your **Auth Token**.

## Circuit Diagram
 circuit_daigram.webp

## Installation
1. Install the [Arduino IDE](https://www.arduino.cc/en/software/).
2. Install Python (version >= 3.7).
3. Test