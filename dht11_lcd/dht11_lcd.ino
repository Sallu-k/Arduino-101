/*  Temperature & humidity meter — DHT11 on a 16x2 I2C LCD
 *  Needs libraries: "DHT sensor library" (Adafruit) + "LiquidCrystal I2C".
 *  Wiring:
 *    DHT11: VCC->5V, GND->GND, DATA->pin 7 (10k pull-up DATA->5V)
 *    LCD I2C: VCC->5V, GND->GND, SDA->A4, SCL->A5  (addr 0x27)
 *
 *  Two things worth noticing in this one:
 *
 *  1. readTemperature() returns NaN when the sensor doesn't respond.
 *     Printing it straight to the LCD shows "nan", which looks like a
 *     code bug but is actually the sensor telling you it failed. Always
 *     check with isnan() before using a sensor reading.
 *
 *  2. The DHT11 can only be sampled about once per second — it is a slow
 *     part. Polling it faster just returns the last value it had.
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(7, DHT11);

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  lcd.setCursor(0, 0);
  if (isnan(t)) {
    lcd.print("Temp: --        ");
  } else {
    lcd.print("Temp: ");
    lcd.print(t, 1);
    lcd.print((char)223);      // degree symbol in the HD44780 font
    lcd.print("C   ");
  }

  lcd.setCursor(0, 1);
  if (isnan(h)) {
    lcd.print("Humidity: --    ");
  } else {
    lcd.print("Humidity: ");
    lcd.print(h, 0);
    lcd.print("%    ");
  }

  // No lcd.clear() here on purpose: clearing and redrawing every second
  // makes the display flicker. Padding each line with trailing spaces
  // overwrites the old text instead.
  delay(2000);
}
