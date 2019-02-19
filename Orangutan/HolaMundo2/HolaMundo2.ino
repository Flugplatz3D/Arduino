#include <OrangutanLCD.h>
#include <OrangutanAnalog.h>

#define ECHOPIN 0                            // Pin to receive echo pulse
#define TRIGPIN 1                            // Pin to send trigger pulse

OrangutanLCD lcd;
OrangutanAnalog analog;
int pot = 0;

void setup() {
  lcd.gotoXY(0, 0);
  lcd.print("TestLCD");
  delay(2000);
  lcd.clear();
}

void loop() {
  lcd.gotoXY(0, 0);
  lcd.print(millis());
  pot = analog.readBatteryMillivolts();
  lcd.gotoXY(0, 1);
  lcd.print(pot);               // print the trim pot position (0 - 1023)
  lcd.print("   ");              // overwrite any left over digits
  delay(100);
}
