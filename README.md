# The Sentinel: A Context-Aware Automated Desk Lamp

![The Sentinel Lamp in Action](https://img.youtube.com/vi/YOUR_VIDEO_ID_HERE/maxresdefault.jpg)
[Watch the Demo Video](https://youtube.com/watch?v=YOUR_VIDEO_ID_HERE)

## 🌟 Overview

The Sentinel is an intelligent desk lamp that automatically illuminates your workspace only when needed - when it's dark AND you're present. This Arduino-based project demonstrates practical sensor fusion, combining input from light and proximity sensors to create an energy-efficient automation system that seamlessly bridges hardware and software.

**Key Features:**
- **Dual-Sensor Intelligence:** Uses ambient light detection and proximity sensing
- **Graceful Transitions:** Smooth PWM fading for pleasant user experience
- **Energy Efficient:** Only activates when both conditions are met
- **Non-Blocking Design:** Responsive operation without delays

## 🛠 Hardware Components

| Component | Specification |
|-----------|---------------|
| Microcontroller | Arduino Uno R3 |
| Light Sensor | LDR Module (HW-072) |
| Proximity Sensor | IR Obstacle Sensor (HW-477) |
| Output | 5mm LED (or 5V Relay Module for actual lamp) |
| Resistor | 220Ω for LED current limiting |
| Power | USB or 7-12V DC power supply |

## 🔌 Circuit Wiring

| Arduino Pin | Component Connection |
|-------------|----------------------|
| 5V | LDR (+) & IR Sensor (VCC) |
| GND | LDR (-) & IR Sensor (GND) & LED Cathode |
| A0 | LDR Module (S) |
| Digital 2 | IR Sensor (OUT) |
| Digital 9 | LED Anode (through 220Ω resistor) |

**Optional Relay Wiring (for actual lamp):**
- Arduino D9 → Relay IN
- Relay COM → AC power source
- Relay NO → Lamp wire
- Relay VCC → Arduino 5V
- Relay GND → Arduino GND

![Wiring Diagram](images/wiring_diagram.png)

## 💻 Software Implementation

### Key Libraries
This project uses native Arduino functions with no external dependencies, making it easy to deploy.

### Core Logic
The system implements a state machine that evaluates two environmental conditions:

```cpp
if (isDark && isPersonPresent) {
  targetBrightness = 255; // Fade ON
} else {
  targetBrightness = 0;   // Fade OFF
}
```

### Non-Blocking Fade Algorithm
Instead of using `delay()`, which halts program execution, the code employs `millis()` for time management, allowing the Arduino to remain responsive to sensor inputs during fading sequences.

## 📁 Project Structure

```
The-Sentinel-Lamp/
├── src/
│   └── sentinel_desk_lamp.ino  # Main Arduino sketch
├── docs/
│   ├── wiring_diagram.fzz      # Fritzing diagram source
│   └── schematic.pdf           # Circuit schematic
├── images/                     # Project photos and diagrams
├── README.md                   # This file
└── LICENSE                     # MIT License
```

## 🚀 Installation & Setup

1. **Hardware Assembly**
   - Connect components according to the wiring table above
   - Ensure proper orientation of LED (long leg to Arduino, short to ground)
   - Place IR sensor where it can detect approach to workspace

2. **Software Setup**
   - Install [Arduino IDE](https://www.arduino.cc/en/software)
   - Connect Arduino Uno via USB
   - Open `sentinel_desk_lamp.ino` in Arduino IDE
   - Select board type: Arduino Uno
   - Select correct port from Tools menu
   - Upload sketch to board

3. **Calibration**
   - Open Serial Monitor (Tools → Serial Monitor, 9600 baud)
   - Note LDR values in light and dark environments
   - Adjust `darkThreshold` value in code (line ~20) accordingly
   - Test IR sensor range and adjust potentiometer on module if needed

## 🎛 Customization

### Adjusting Sensitivity
Modify these constants in the code:

```cpp
const int darkThreshold = 700;    // Higher = more sensitive to darkness
const unsigned long fadeDuration = 1500; // Time for full fade in milliseconds
```

### Adding Manual Override
Extend functionality by adding a pushbutton to toggle between automatic and manual modes.

### Remote Control Integration
To add IR remote functionality, incorporate an IR receiver (like VS1838B) and the IRremote.h library.

## 📊 Technical Details

### Sensor Specifications
- **LDR (HW-072):** Analog output, resistance decreases with light intensity
- **IR Sensor (HW-477):** Digital output, active-low (LOW when obstacle detected)
- **Detection Range:** Adjustable via onboard potentiometer (typically 2-30cm)

### Power Consumption
- Arduino Uno: ~45mA (50mA with LED at full brightness)
- Standby current: ~45mA
- Peak current: ~95mA (with LED and both sensors active)

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to check [issues page](https://github.com/yourusername/The-Sentinel-Lamp/issues).

1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
---

**⭐️ If you found this project helpful, please give it a star on GitHub!**# automatic-context-aware-desk-lamp-on-audrino
