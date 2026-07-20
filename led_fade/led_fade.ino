/*  LED fade — PWM with analogWrite()
 *  Smoothly ramps an LED up and down in brightness.
 *  Wiring: LED anode -> 220R -> pin 9 (PWM ~), cathode -> GND
 */
const int LED = 9;      // must be a PWM pin (~)
void setup() { pinMode(LED, OUTPUT); }
void loop() {
  for (int b = 0; b <= 255; b++) { analogWrite(LED, b); delay(6); }
  for (int b = 255; b >= 0; b--) { analogWrite(LED, b); delay(6); }
}
