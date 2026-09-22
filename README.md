# Temperature & Humidity Pet Crate Monitor

This project monitors temperature and humidity inside a pet crate using an Arduino and a DHT11 sensor. It displays real-time readings on an LCD screen and can be used to ensure a safe and comfortable environment for pets.

## Features

- Real-time temperature and humidity monitoring
- LCD display for instant readings
- DHT11 sensor for environmental data
- Arduino-based control system
- Suitable for pet crate or small enclosure monitoring

## Hardware Components

- Arduino board (e.g., Arduino Uno)
- DHT11 Temperature & Humidity Sensor
- LCD Display (e.g., 16x2 with I2C module)
- Breadboard and jumper wires
- Power supply (USB or battery)

## Circuit Diagram

This project includes Fritzing diagrams:

- `MiniProject(temperature display).fzz` – Full circuit design
- `MiniProject(temperature display)_bb.png` – Breadboard view
- `MiniProject(temperature display)_schem.png` – Schematic view

Refer to these images when wiring your components.

## Code Overview

Two Arduino sketches are provided:

- `MiniProjectArduinocode.ino` – Main project code
- `Mini_project_DHT11_coding.ino` – Alternative DHT11 implementation

The code:

- Reads temperature and humidity from the DHT11 sensor
- Displays values on the LCD screen
- Updates readings at regular intervals

## Setup Instructions

1. **Install Arduino IDE**  
   Download and install from https://www.arduino.cc/en/software

2. **Install Required Libraries**  
   In Arduino IDE:
   - Go to **Sketch → Include Library → Manage Libraries**
   - Install:
     - `DHT sensor library` (by Adafruit)
     - `LiquidCrystal I2C` (or your LCD library)

3. **Wire the Circuit**  
   Follow the Fritzing diagrams in this repository to connect:
   - DHT11 sensor to Arduino
   - LCD display to Arduino

4. **Upload the Code**  
   - Open `MiniProjectArduinocode.ino` in Arduino IDE
   - Select your board and port under **Tools**
   - Click **Upload**

5. **Test the System**  
   - Power the Arduino
   - Check that the LCD displays temperature and humidity values
   - Verify readings are reasonable for your environment

## Usage

Place the sensor inside the pet crate and ensure the LCD is visible. Monitor the displayed values to ensure the environment remains within a safe range for your pet.

## License

This project is provided as-is for educational and personal use.
