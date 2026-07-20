/*  Blink — the "hello world" of Arduino
 *  Turns the on-board LED on for 1 s, off for 1 s, forever.
 *  Wiring: none (uses the built-in LED on pin 13 / LED_BUILTIN).
 *  Tinkercad: drop an Arduino Uno, no extra parts, run.
 */
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
