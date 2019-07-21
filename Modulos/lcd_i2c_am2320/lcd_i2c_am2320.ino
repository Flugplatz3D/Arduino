#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <AM2320.h>

AM2320 th;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7); // 0x27 suele ser la dirección I2C
bool Luz = HIGH;
unsigned long cuenta = 0;

void setup() {
  lcd.begin(16, 2);                  // LCD 16x2
  lcd.setBacklightPin(3, POSITIVE);  // POSITIVE = enum definido en LCD.h
  lcd.setBacklight(Luz);
  lcd.home();
}

void loop() {
  switch (th.Read()) {
    case 2:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("CRC failed");
      break;
    case 1:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Sensor offline");
      break;
    case 0:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temp.: ");
      lcd.print(th.t);
      lcd.setCursor(0, 1);
      lcd.print("Humedad: ");
      lcd.print(th.h);
      break;
  }
  delay(2000);
}
