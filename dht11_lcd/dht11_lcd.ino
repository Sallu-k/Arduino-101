/*  Temperature & humidity meter — DHT11 on a 16x2 I2C LCD
 *  Needs libraries: "DHT sensor library" (Adafruit) + "LiquidCrystal I2C".
 *  Wiring:
 *    DHT11: VCC->5V, GND->GND, DATA->pin 7 (10k pull-up DATA->5V)
 *    LCD I2C: VCC->5V, GND->GND, SDA->A4, SCL->A5  (addr 0x27)
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(7, DHT11);
void setup() {
  lcd.init(); lcd.backlight();
  dht.begin();
}
void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("Temp: "); lcd.print(t,1); lcd.print((char)223); lcd.print("C");
  lcd.setCursor(0,1); lcd.print("Humidity: "); lcd.print(h,0); lcd.print("%");
  delay(1000);
}
