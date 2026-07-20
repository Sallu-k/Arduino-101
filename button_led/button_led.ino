/*  Button-controlled LED — digital input
 *  Press the button -> LED turns on. Uses the internal pull-up so the
 *  button reads LOW when pressed.
 *  Wiring:
 *    Button: one leg -> pin 2, opposite leg -> GND
 *    LED:    anode -> 220R -> pin 8, cathode -> GND
 */
const int BUTTON = 2;
const int LED    = 8;
void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}
void loop() {
  bool pressed = (digitalRead(BUTTON) == LOW);
  digitalWrite(LED, pressed ? HIGH : LOW);
}
