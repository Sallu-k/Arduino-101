/*  Traffic-light sequence — 3 LEDs
 *  Red -> Green -> Yellow -> repeat, with realistic timing.
 *  Wiring (each LED: anode -> 220R -> pin, cathode -> GND):
 *    Red -> pin 8, Yellow -> pin 9, Green -> pin 10
 */
const int RED = 8, YEL = 9, GRN = 10;
void setup() {
  pinMode(RED, OUTPUT); pinMode(YEL, OUTPUT); pinMode(GRN, OUTPUT);
}
void set(bool r, bool y, bool g) {
  digitalWrite(RED, r); digitalWrite(YEL, y); digitalWrite(GRN, g);
}
void loop() {
  set(1,0,0); delay(4000);   // RED
  set(0,0,1); delay(4000);   // GREEN
  set(0,1,0); delay(1500);   // YELLOW
}
