/*  Buzzer melody — tone() and a simple note table
 *  Plays a short tune on a piezo buzzer.
 *  Wiring: buzzer + -> pin 8, - -> GND
 */
const int BUZZ = 8;
int melody[]   = {262,294,330,349,392,440,494,523}; // C major scale
int durations[]= {300,300,300,300,300,300,300,500};
void setup() {}
void loop() {
  for (int i = 0; i < 8; i++) {
    tone(BUZZ, melody[i], durations[i]);
    delay(durations[i] * 1.3);
  }
  noTone(BUZZ);
  delay(1500);
}
