#include <OrangutanLCD.h>
#include <OrangutanLEDs.h>

OrangutanLCD lcd;
OrangutanLEDs leds;

void setup() {
  leds.green(HIGH);
  lcd.gotoXY(0, 0);
  lcd.print("TestLCD");
  delay(2000);
  lcd.clear();
  leds.green(LOW);
}

void loop() {
  lcd.gotoXY(0, 0);
  lcd.print(millis());
  leds.red(bitRead(millis(), 10));
  delay(100);
}
