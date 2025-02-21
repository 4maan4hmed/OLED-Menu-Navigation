# OLED Menu Navigation System with PID Control

This project showcases an intuitive OLED-based menu navigation system utilizing an Adafruit SSD1306 display and PID control parameters. The system enables users to navigate through menus and fine-tune settings like PID values and LED brightness using physical buttons.

---

## 🔥 Features

- 📟 **OLED Display:** Clear and structured menu navigation.
- 🎛 **Adjustable PID Control:** Fine-tune `kp`, `ki`, and `kd` values.
- 💡 **LED Brightness Control:** Modify LED intensity for visual feedback.
- 🎮 **Button-Based Navigation:** Simple navigation with Up, Down, Select, and Back buttons.

---

## 🛠 Hardware Requirements

- **Microcontroller:** ESP32 (or compatible)
- **Display:** Adafruit SSD1306 OLED
- **Buttons:** Up, Down, Select, Back
- **LED & Resistors** for brightness control

### 📌 Pin Configuration

| Component         | GPIO Pin |
| ----------------- | -------- |
| `buttonUpPin`     | 15       |
| `buttonDownPin`   | 16       |
| `buttonSelectPin` | 17       |
| `buttonBackPin`   | 18       |
| `ledPin`          | 12       |

---

## 📥 Installation & Setup

1. Clone the repository or download the ZIP file.
2. Open the project in your preferred IDE (e.g., Arduino IDE).
3. Install required libraries:
   - `Wire`
   - `Adafruit_GFX`
   - `Adafruit_SSD1306`
4. Upload the code to your ESP32.

---

## 🖥 Simulation in Wokwi

Want to try it without hardware? You can simulate it on Wokwi!

🔗 [Wokwi Simulator](https://wokwi.com/projects/402098435518944257)

1. Click **Start Simulation**.
2. Use virtual buttons or keyboard keys (Arrow keys, Enter, Backspace) to navigate.

### 📸 Screenshots


![alt text](https://github.com/4maan4hmed/OLED-Menu-Navigation/blob/main/Menu_System/Screenshot%202025-02-21%20104257.png) 
![alt text](https://github.com/4maan4hmed/OLED-Menu-Navigation/blob/main/Menu_System/Screenshot%202025-02-21%20104311.png)
![alt text](https://github.com/4maan4hmed/OLED-Menu-Navigation/blob/main/Menu_System/Screenshot%202025-02-21%20104332.png)
![alt text](https://github.com/4maan4hmed/OLED-Menu-Navigation/blob/main/Menu_System/Screenshot%202025-02-21%20102015.png)

---

## 🔌 Running on Real Hardware

1. Connect components as per the **Pin Configuration**.
2. Power up your ESP32.
3. Use buttons to navigate:
   - 🔼 **Up/Down:** Scroll menu items.
   - ✅ **Select:** Choose an option.
   - ⬅️ **Back:** Return to the previous menu.
4. Adjust **PID values** and **LED brightness** dynamically.

---

## 📜 Menu Structure

- **Main Menu**

  - 🚀 **Bot Mode**
  - 🔧 **Hardware Check**
  - 🔋 **Battery Status**
  - 🔄 **Restart**
  - 🎯 **Calibration**

- **Bot Mode Menu**

  - 🔲 **Line Follower Mode**
  - 🧩 **Maze Solver Mode**

- **Line Follower Menu**

  - ▶ **Start**
  - 📊 **Check all values**
  - ⚙ **Settings**

- **Maze Solver Menu**

  - ▶ **Start**
  - 📊 **Check all values**
  - ⚙ **Settings**

- **Settings Menu**

  - 🔄 **PID Values**
  - 🏎 **Initial Speed**
  - ⏳ **Delay Before Start**
  - 🚀 **Max Speed**
  - 💡 **LED Brightness**

- **PID Menu**

  - 🔼 **Adjust kp**
  - 🔼 **Adjust ki**
  - 🔼 **Adjust kd**

- **Brightness Menu**

  - 🌟 **Adjust LED brightness**

---

## 🚀 Future Enhancements

- 📡 **WiFi Connectivity:** Modify settings via a web interface.
- 🎨 **Customizable UI:** Improve menu aesthetics.
- 🎯 **Save Settings:** Store user preferences in EEPROM.
- 🎙 **Voice Commands:** Integrate voice-controlled navigation.

This project is open for improvements and contributions. Happy coding! 🚀

