/*  Motion-detector alarm — PIR sensor + buzzer + LED
 *  Beeps and lights up when motion is detected.
 *  Wiring:
 *    PIR: VCC->5V, GND->GND, OUT->pin 2
 *    Buzzer: +->pin 8, -->GND      LED: 220R->pin 13, cathode->GND
 */
const int PIR = 2, BUZZ = 8, LED = 13;
void setup() {
  pinMode(PIR, INPUT); pinMode(BUZZ, OUTPUT); pinMode(LED, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  if (digitalRead(PIR) == HIGH) {
    digitalWrite(LED, HIGH); tone(BUZZ, 1000);
    Serial.println("Motion detected!");
  } else {
    digitalWrite(LED, LOW); noTone(BUZZ);
  }
  delay(100);
}
