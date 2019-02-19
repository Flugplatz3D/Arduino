
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7); // 0x27 suele ser la dirección I2C
unsigned long time1 = 0;
bool Luz = HIGH;

void setup() {
  // initialize the LCD
  lcd.begin(16, 2);                  // LCD 16x2
  lcd.setBacklightPin(3, POSITIVE);  // POSITIVE = enum definido en LCD.h
  lcd.setBacklight(Luz);
  lcd.home();
  //lcd.clear();
  time1 = millis();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print(millis());
//  if (millis() - time1 > 60000)
//  {
    time1 = millis();
    //Luz = !Luz;
    //lcd.setBacklight(Luz);
//  }
}
