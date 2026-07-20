/*  Potentiometer -> LED brightness (analogRead + PWM + map)
 *  Turn the knob to dim/brighten the LED.
 *  Wiring:
 *    Pot: ends -> 5V and GND, wiper -> A0
 *    LED: anode -> 220R -> pin 9 (~), cathode -> GND
 */
const int POT = A0, LED = 9;
void setup() { pinMode(LED, OUTPUT); }
void loop() {
  int raw = analogRead(POT);            // 0..1023
  int pwm = map(raw, 0, 1023, 0, 255);  // 0..255
  analogWrite(LED, pwm);
}
