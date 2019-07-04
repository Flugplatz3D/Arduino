#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7); // 0x27 suele ser la dirección I2C
bool Luz = HIGH;
unsigned long cuenta = 0;

void setup() {
  // initialize the LCD
  lcd.begin(16, 2);                  // LCD 16x2
  lcd.setBacklightPin(3, POSITIVE);  // POSITIVE = enum definido en LCD.h
  lcd.setBacklight(Luz);
  lcd.home();
  //lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print(cuenta);
  cuenta++;
  delay(50);
}
