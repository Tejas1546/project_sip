# IoT-Based Smart Irrigation System

## Overview
This project is an IoT-based smart irrigation system that utilizes local weather measurements and forecasting to optimize water usage for agricultural or garden irrigation. The system is built using ESP microcontrollers and integrates with the Blynk API for remote monitoring and control.

## Features
- **Automated Irrigation:** Controls water flow based on soil moisture levels and weather forecasts.
- **Weather Forecast Integration:** Uses real-time weather data to prevent over-irrigation.
- **Remote Monitoring:** Allows users to monitor and control irrigation via the Blynk mobile app.
- **ESP Microcontroller-Based:** Uses ESP8266/ESP32 for IoT connectivity.
- **Efficient Water Usage:** Reduces water wastage by optimizing irrigation schedules.

## Hardware Requirements
- ESP8266/ESP32 Microcontroller
- Soil Moisture Sensor
- DHT11/DHT22 Temperature & Humidity Sensor
- Water Pump & Relay Module
- Power Supply (5V/12V as needed)
- Wi-Fi Connectivity

## Software Requirements
- Arduino IDE with ESP board support
- Blynk Library
- Weather API for forecast data
- MQTT
  
## Installation & Setup
1. **Set up your ESP microcontroller:**
   - Install the ESP8266/ESP32 board package in Arduino IDE.
   - Connect the ESP to your Wi-Fi network.
2. **Install required libraries:**
   - Install the Blynk library.
   - Install DHT sensor and other necessary libraries.
3. **Configure the Blynk App:**
   - Create a new project in Blynk.
   - Add widgets for monitoring temperature, humidity, and soil moisture.
   - Generate and use your Blynk Auth Token.
4. **Flash the Code:**
   - Upload the Arduino sketch to the ESP microcontroller.
   - Ensure proper connections between sensors and microcontroller.
5. **Run & Monitor:**
   - Open the Blynk app and monitor the irrigation system remotely.

## Future Enhancements
- Integration with AI-based predictive analytics for better forecasting.
- Solar-powered operation for sustainable energy use.
- Expansion to support multiple irrigation zones.
