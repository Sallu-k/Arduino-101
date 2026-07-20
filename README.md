# Arduino-101

Basic Arduino projects I built while learning embedded — the fundamentals: digital I/O, PWM, analog sensors, LCDs, servos, and buzzers. Each folder is a self-contained sketch with the wiring in the header comment.

Nothing fancy here on purpose — this is the "learn the building blocks" repo. The bigger projects (robotic arm, grow-box, FPGA, etc.) live in my other repositories.

---

## Projects (rough learning order)

| # | Folder | What it does | Concept |
|---|--------|--------------|---------|
| 1 | `blink` | Blink the on-board LED | `digitalWrite`, `delay` |
| 2 | `button_led` | Button turns an LED on | digital input, `INPUT_PULLUP` |
| 3 | `led_fade` | LED fades up and down | PWM / `analogWrite` |
| 4 | `traffic_light` | Red → green → yellow cycle | sequencing, timing |
| 5 | `ldr_night_light` | LED turns on in the dark | analog input, threshold |
| 6 | `pot_brightness` | Knob controls LED brightness | `analogRead` + `map` + PWM |
| 7 | `ultrasonic_lcd` | Distance meter on a 16×2 LCD (cm + inches) | HC-SR04, `pulseIn`, LCD |
| 8 | `dht11_lcd` | Temperature + humidity on an I²C LCD | DHT11, I²C |
| 9 | `servo_knob` | Potentiometer moves a servo | Servo library |
| 10 | `pir_alarm` | Motion → buzzer + LED | PIR sensor, `tone` |
| 11 | `buzzer_melody` | Plays a tune on a piezo | `tone`, note tables |
| 12 | `lm35_thermometer` | Reads LM35 temp to Serial | analog sensor scaling |

Project 7 (`ultrasonic_lcd`) includes a Tinkercad simulation screenshot (`ultrasonic_lcd/simulation.jpeg`).

## How to run each one

**On real hardware:** open the folder's `.ino` in the Arduino IDE, wire it up per the header comment, select your board/port, and upload. Sketches 8 and 9 need libraries (DHT sensor library, LiquidCrystal I2C, Servo) — install them from the Library Manager.

**In simulation (no hardware needed):** every one of these runs in [Tinkercad Circuits](https://www.tinkercad.com/circuits) or [Wokwi](https://wokwi.com). Drop in an Arduino Uno + the parts listed in the header, paste the code, and hit Start Simulation.

## Adding your own simulation screenshots

Want a picture for each project? Build the circuit in Tinkercad (2 min each), run it, and screenshot it — then save it into that project's folder as `simulation.jpeg`. Those are real shots of your own circuit, so they'll always match the code. (There are two more screenshots in `_unsorted_screenshots/` — move them into whichever project folders they belong to and rename them `simulation.jpeg`.)

## Notes

Wiring is in each sketch's header comment. Resistor values are typical (220 Ω for LEDs, 10 kΩ for pull-ups/dividers) — adjust for your parts.
