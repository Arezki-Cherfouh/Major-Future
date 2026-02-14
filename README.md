# OLED Major Selector with Sound

An interactive Arduino project that lets users browse academic majors on an OLED display and get humorous future predictions with sound effects.

## Features

- **OLED Menu**: Browse through 5 majors (Arts, Business, Engineering, CS, AI)
- **Button Controls**: Next, Previous, and Confirm buttons with pull-up resistors
- **Sound Feedback**:
  - Navigation beeps (1000Hz next / 800Hz prev)
  - Selection chirp (1500Hz)
  - "Thinking" ticks during prediction
  - Happy vs Sad sound effects based on major
- **Humorous Output**: Predictions with personality

## Hardware Required

- ESP32 or Arduino
- SSD1306 OLED (128x64, I2C)
- 3x Push buttons
- Passive buzzer
- Jumper wires

## Wiring Diagram

```
OLED      → ESP32
VCC       → 3.3V
GND       → GND
SDA       → D21
SCL       → D22

Buttons   → ESP32 (with INPUT_PULLUP)
NEXT_BTN  → D12
PREV_BTN  → D14
CONFIRM   → D13

Buzzer    → D25 & GND
```

## How It Works

1. **Navigation**: Next/Prev buttons cycle through majors with different beep tones
2. **Selection**: Confirm button triggers "prediction" sequence
3. **Animation**: Dots animate during "thinking" phase
4. **Result**: Shows prediction with appropriate sound effect
   - Arts/Business → Happy tune
   - Engineering/CS/AI → "Sad trombone" effect

## Customization

- Add more majors to the `majors[]` array
- Change prediction messages
- Modify tones and durations
- Adjust I2C address (default 0x3C)

## Installation

1. Install required libraries:
   - Adafruit GFX
   - Adafruit SSD1306
2. Upload code to your board
3. Navigate with buttons and enjoy!

## License

MIT

```

```
