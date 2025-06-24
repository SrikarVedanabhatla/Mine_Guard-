# 🌡️ Environmental Monitoring System using Arduino

This project uses an Arduino Uno to monitor **temperature**, **humidity**, **gas presence**, and **compass heading** using the following sensors:
- **DHT11** for temperature & humidity
- **MQ2** for gas detection
- **HMC5883L** for compass/magnetic heading
- **SSD1306 OLED Display** to show readings

---

## 🔧 Hardware Components

| Component              | Quantity |
|------------------------|----------|
| Arduino Uno            | 1        |
| DHT11 Sensor           | 1        |
| MQ2 Gas Sensor         | 1        |
| HMC5883L Magnetometer  | 1        |
| SSD1306 OLED Display   | 1        |
| Jumper Wires           | As needed |
| Breadboard (optional)  | 1        |

---

## 🔌 Wiring Diagram

| Module         | Arduino Pin |
|----------------|-------------|
| **DHT11**      | D2          |
| **MQ2 (DO pin)** | D3        |
| **SSD1306 OLED** | I2C (SDA - A4, SCL - A5) |
| **HMC5883L**   | I2C (SDA - A4, SCL - A5) |
| **VCC/GND**    | 5V / GND    |

---

## 📦 Required Libraries

Install the following libraries in the Arduino IDE via **Library Manager**:

1. **Adafruit GFX Library**
2. **Adafruit SSD1306**
3. **SimpleDHT**
4. **Adafruit Sensor**
5. **Adafruit HMC5883 Unified**

---

## 🚀 Setup and Usage

1. Connect the hardware components as per the wiring diagram.
2. Upload the `main.ino` code to your Arduino Uno.
3. Open the **Serial Monitor** (baud rate: `9600`) to see sensor logs.
4. The OLED display will cycle through:
   - Temperature (°C)
   - Humidity (%)
   - Gas Status (detected or not)
   - Magnetic Compass Heading (degrees)

---

## ⏱️ Sensor Warm-up

- The **MQ2 sensor** requires a warm-up time of **70 seconds** on first use for stable gas readings.

---

## 📸 Screenshots

| Display | Example Output |
|---------|----------------|
| Temp    | `Temp: 27 C`   |
| Humidity| `Humidity: 56 %` |
| Gas     | `Gas: No gas detected` |
| Compass | `Heading: 123.45 deg` |

---

## 💡 Future Improvements

- Add support for analog gas concentration reading (MQ2 AO pin).
- Integrate buzzer or LED alerts for gas detection.
- Include SD card logging for historical data.
- Optimize screen transitions for smoother UX.

---

## 🤝 Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

---

## 🧑‍💻 Author

**Srikar Vedanabhatla**  


---

