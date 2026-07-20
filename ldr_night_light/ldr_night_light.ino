/*  Automatic night light — LDR (analog input)
 *  When it gets dark, the LED turns on automatically.
 *  Wiring:
 *    LDR + 10k form a divider: 5V -> LDR -> A0 -> 10k -> GND
 *    LED: anode -> 220R -> pin 8, cathode -> GND
 *  Tune THRESHOLD from the Serial Monitor readings for your light level.
 */
const int LDR = A0, LED = 8;
const int THRESHOLD = 400;   // lower reading = darker
void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int light = analogRead(LDR);
  Serial.println(light);
  digitalWrite(LED, light < THRESHOLD ? HIGH : LOW);
  delay(200);
}
