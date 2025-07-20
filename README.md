# Arduino Password Lock Projects with LCD and Keypad

This repository contains two related Arduino-based projects demonstrating the use of a keypad and LCD for password input and verification. One project uses a basic parallel LCD display, while the other uses an I2C LCD and incorporates buzzer output, analog reading, and SIM800L integration.

---

## 🔐 Project 1: Password Lock with Parallel LCD & Keypad

### 📄 Overview

This project implements a password entry system using:

* 4x3 matrix keypad
* 16x2 parallel LCD
* Hardcoded password validation

On successful entry, a success message is shown. Incorrect entries trigger an error message.

### 🔧 Hardware Components

| Component        | Quantity |
| ---------------- | -------- |
| Arduino UNO/Nano | 1        |
| 4x3 Keypad       | 1        |
| 16x2 LCD         | 1        |
| Jumper wires     | Several  |

### 💻 Features

* Masked input (asterisks)
* Success and error messages
* Resets after each entry attempt

---

## 🔐 Project 2: Password System with I2C LCD, Keypad, SIM800L & Analog Sensor

### 📄 Overview

This advanced version expands the functionality:

* Uses a 4x4 keypad
* I2C-based 16x2 LCD
* Reads analog values periodically
* Optional support for SIM800L (SMS trigger capability)
* Buzzer pin (placeholder, can be used for alerts)

### 🔧 Hardware Components

| Component           | Quantity     |
| ------------------- | ------------ |
| Arduino UNO/Nano    | 1            |
| 4x4 Keypad          | 1            |
| I2C 16x2 LCD (0x27) | 1            |
| SIM800L Module      | 1 (optional) |
| Buzzer              | 1            |
| Analog Sensor       | 1            |
| Jumper wires        | Several      |

### 💡 Key Features

* Password input with live LCD update
* Supports delete character using `*`
* `#` used to submit password for validation
* Displays success or error message based on hardcoded string
* Continuously prints analog sensor data to Serial Monitor

### 🔁 System Behavior

| Key Pressed | Action                          |
| ----------- | ------------------------------- |
| Number keys | Appended to password            |
| `*`         | Deletes last character          |
| `#`         | Validates password and responds |

---

## 🧪 How to Use

1. Upload respective `.ino` file to your Arduino board.
2. Connect components as per keypad/LCD type.
3. Open Serial Monitor for analog data logs (Project 2).
4. Enter password via keypad and press `#` to validate.

---

## 📁 File Structure

```
Password-LCD-Keypad-Projects/
├── parallel-lcd-password/
│   └── parallel_lcd_password.ino
├── i2c-lcd-password/
│   └── i2c_lcd_password.ino
└── README.md
```

---

## 📌 Notes

* Default password is `12345` in both sketches
* SIM800L logic is included as a placeholder (add trigger as needed)
* Debouncing and security enhancements can be added for real-world use

---

> *Simple password systems like this can form the base for electronic door locks, access control, or alert systems.*
