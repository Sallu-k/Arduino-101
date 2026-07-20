/*  LM35 thermometer -> Serial Monitor
 *  Reads the LM35 analog temperature sensor and prints degC.
 *  Wiring: LM35 +Vs->5V, GND->GND, Vout->A0
 *  (LM35 outputs 10 mV per degC)
 */
const int SENSOR = A0;
void setup() { Serial.begin(9600); }
void loop() {
  int raw = analogRead(SENSOR);
  float volts = raw * (5.0 / 1023.0);
  float tempC = volts * 100.0;          // 10 mV/degC
  Serial.print("Temperature: "); Serial.print(tempC, 1); Serial.println(" C");
  delay(1000);
}
