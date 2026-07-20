/*  Ultrasonic distance meter on a 16x2 LCD (parallel)
 *  Shows distance in centimetres and inches, live.
 *  (This matches the Tinkercad simulation screenshot in this folder.)
 *  Wiring:
 *    HC-SR04: VCC->5V, GND->GND, TRIG->pin 9, ECHO->pin 10
 *    LCD (parallel): RS->12, E->11, D4->5, D5->4, D6->3, D7->2,
 *                    VSS->GND, VDD->5V, RW->GND, contrast pot on V0,
 *                    A->5V (via 220R), K->GND
 */
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int TRIG = 9, ECHO = 10;

long readCM() {
  digitalWrite(TRIG, LOW);  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long us = pulseIn(ECHO, HIGH, 30000);   // timeout 30 ms
  return us / 58;                          // us -> cm
}
void setup() {
  pinMode(TRIG, OUTPUT); pinMode(ECHO, INPUT);
  lcd.begin(16, 2);
}
void loop() {
  long cm = readCM();
  long in = cm / 2.54;
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("Distance: "); lcd.print(cm); lcd.print(" cm");
  lcd.setCursor(0,1); lcd.print("Distance: "); lcd.print(in); lcd.print(" in");
  delay(300);
}
