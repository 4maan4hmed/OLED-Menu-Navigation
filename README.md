

---

# OLED Menu Navigation System with PID Control

This project demonstrates an OLED menu navigation system using an Adafruit SSD1306 display and PID control parameters. The system allows you to navigate through various menus and adjust settings such as PID values and LED brightness using buttons.

## Features

- OLED display for menu navigation
- Adjustable PID control parameters (kp, ki, kd)
- Adjustable LED brightness
- Button-based navigation and selection

## Hardware Requirements

- Adafruit SSD1306 OLED display
- ESP32 or compatible microcontroller
- Push buttons (Up, Down, Select, Back)
- LED
- Resistors for buttons and LED

## Pin Configuration

- `buttonUpPin`: GPIO 15
- `buttonDownPin`: GPIO 16
- `buttonSelectPin`: GPIO 17
- `buttonBackPin`: GPIO 18
- `ledPin`: GPIO 12

## Installation

1. Clone the repository or download the ZIP file.
2. Open the project in your preferred IDE (e.g., Arduino IDE).
3. Ensure you have the required libraries installed:
    - `Wire`
    - `Adafruit_GFX`
    - `Adafruit_SSD1306`
4. Upload the code to your microcontroller.

## Usage

### Simulation in Wokwi

1. Open [Wokwi Simulator](https://wokwi.com/projects/402098435518944257).
2. Click on the "Start Simulation" button.
3. Use the virtual buttons to navigate through the menu and adjust settings or you can use the arrow, Enter and Backspace keys for navigations as well.

### Real Hardware

1. Connect the hardware according to the pin configuration.
2. Power up the system.
3. Use the buttons to navigate through the menu:
    - Up and Down buttons to scroll through menu items.
    - Select button to choose a menu item.
    - Back button to return to the previous menu.
4. Adjust PID values and LED brightness through the respective menus.

## Menu Structure

- **Main Menu**
  - Bot Mode
  - Hardware Check
  - Battery Status
  - Restart
  - Calibration
- **Bot Mode Menu**
  - Line Follower Mode
  - Maze Solver Mode
- **Line Follower Menu**
  - Start
  - Check all values
  - Settings
- **Maze Solver Menu**
  - Start
  - Check all values
  - Settings
- **Settings Menu**
  - PID Values
  - Initial Speed
  - Delay Before Start
  - Max Speed
  - LED Brightness
- **PID Menu**
  - Adjust kp
  - Adjust ki
  - Adjust kd
- **Brightness Menu**
  - Adjust LED brightness

---
