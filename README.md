# 🚗 MechaRush – ESP32 RC Car

**MechaRush** is a fully functional, custom-built **Remote-Controlled Car** powered by an **ESP32 microcontroller** and driven by **BTS7960B motor drivers**. Designed by **Team Trace X**, it combines powerful Johnson motors, wireless control via FS-i4X, and safety features such as soft-start and overcurrent protection using ESC.

---

## 👨‍💻 Developed by: MECHA RUSH

---

## 🧰 Components Used

### 1. ESP32
- **Specs**:
  - Dual-Core 32-bit microcontroller @240 MHz
  - 4MB Flash, 520KB SRAM
  - WiFi + Bluetooth (BLE + Classic)
  - 34 GPIO pins (ADC, PWM, I2C, SPI, UART)
- **Purpose**: Central controller – processes receiver signals and drives the motor controller (BTS7960B).

---

### 2. BTS7960B Motor Driver
- **Specs**:
  - Operating Voltage: 6V–27V
  - Continuous Current: 43A, Peak: 100A
  - PWM up to 25kHz, 3.3V/5V logic compatible
  - Built-in protection: Overcurrent, Overheat
- **Purpose**: Drives high-current Johnson motors based on PWM signals from the ESP32.

---

### 3. FS-i4X Transmitter and Receiver
- **Specs**:
  - Frequency: 2.4 GHz (AFHDS 2A)
  - Channels: 4, Range: ~500 meters
- **Purpose**: Wireless control interface for user input; sends PWM to ESP32 for throttle/steering decisions.

---

### 4. Johnson Motor
- **Specs**:
  - Operating Voltage: 12V
  - RPM: ~900 RPM
  - High torque, 0.5A–5A current draw
- **Purpose**: Primary drive motor of the RC car.

---

### 5. ESC (Electronic Speed Controller)
- **Specs**:
  - Input: 6V–12V, Max Current: ~30A
  - PWM Signal Range: 1ms–2ms
  - Includes BEC (5V/2A), soft start, overcurrent protection
- **Purpose**: Regulates voltage/current to the motors; ensures smooth acceleration and safe operation.

---

### 6. Miscellaneous Components
- Jumper & connecting wires
- DPDT switch
- Rechargeable Li-ion battery
- Breadboard
- Wooden chassis
- Tyres
- Controller circuit (custom)

---

## 📸 Car Photos

### 🔹 Front View
[Front View](https://drive.google.com/file/d/19jljPlk8WBF_GioKqOr9s1AMIoOlHF-R/view?usp=sharing)

### 🔹 Video ofTesting
[Video ofTesting](https://drive.google.com/file/d/1aOlnP6JRYill2XN-uYrrgurGtVWJKbTY/view?usp=sharing)

### 🔹 Video on Track
[Video on Track](https://drive.google.com/file/d/1etKoNyxB2WZiymCuDd_KvrEQ01WJm5cv/view?usp=sharing)

---

## 🧠 Project Highlights

- 🚀 High-speed, low-latency control via FS-i4X radio
- 🔁 Real-time PWM motor control from ESP32
- 🔋 Efficient power delivery with Johnson motors + BTS7960B
- 🛡️ Safety-focused ESC protection (soft-start, overcurrent)
- 🛠️ Modular chassis with plug-and-play electronics

---

## 📎 License

This project is licensed under the **MIT License** – feel free to use, modify, and share.

---

## 🙌 Special Thanks

- Open-source community (Arduino, Espressif, Pololu)
- Team collaboration from all contributors
- Inspiration from hobby-grade and competition RC platforms

---

Want to make your car smarter? Consider adding:
- Speed sensing with encoders
- WiFi app control
- Obstacle avoidance with ultrasonic sensors
