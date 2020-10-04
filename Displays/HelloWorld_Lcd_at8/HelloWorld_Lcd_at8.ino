// include the library code:
#include <LiquidCrystal.h>
#define LED 13

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 8, d4 = 12, d5 = 11, d6 = 10, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
unsigned long segundo = 0;
unsigned long minuto = 0;
unsigned long hora = 0;
unsigned long segundot = 0;
unsigned long minutot = 0;

unsigned long time1 = 0;
char output[12];

void setup() {
  pinMode(LED, OUTPUT);
  lcd.begin(16, 2);
  //  lcd.begin(20, 4);
  delay(500);
  lcd.clear();
}

void loop() {
  time1 = millis();
  segundo = time1 / 1000;
  minuto = segundo / 60;
  hora = minuto / 60;
  minutot = minuto - (hora * 60);
  segundot = segundo - (minuto * 60);
  sprintf(output, "%02d:%02d:%02d", (int)hora, (int)minutot, (int)segundot);
  lcd.setCursor(0, 0);
  lcd.print(output);
  lcd.setCursor(0, 1);
  lcd.print(time1);
  //  delay(50);
  //  digitalWrite(LED, !digitalRead(LED));
  digitalWrite(LED, bitRead(millis(), 13));
}
