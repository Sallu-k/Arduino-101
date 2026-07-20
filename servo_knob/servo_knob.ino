/*  Servo controlled by a potentiometer
 *  Knob position -> servo angle (0..180).
 *  Wiring:
 *    Servo: signal->pin 9, VCC->5V, GND->GND
 *    Pot:   ends->5V/GND, wiper->A0
 */
#include <Servo.h>
Servo s;
const int POT = A0;
void setup() { s.attach(9); }
void loop() {
  int angle = map(analogRead(POT), 0, 1023, 0, 180);
  s.write(angle);
  delay(15);
}
