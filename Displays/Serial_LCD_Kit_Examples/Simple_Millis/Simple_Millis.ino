#include <LiquidCrystal.h>

// --- ARDUINO PIN DEFINITIONS
uint8_t RSPin = 2;
uint8_t RWPin = 3;
uint8_t ENPin = 4;
uint8_t D4Pin = 5;
uint8_t D5Pin = 6;
uint8_t D6Pin = 7;
uint8_t D7Pin = 8;
uint8_t BLPin = 9;

//Interface pins for the SparkFun Serial LCD Kit
//LiquidCrystal lcd(2, 3, 4, 5, 6, 7, 8);
LiquidCrystal lcd(RSPin, RWPin, ENPin, D4Pin, D5Pin, D6Pin, D7Pin);


void setup() {

  //LCD Backlight
  pinMode(BLPin, OUTPUT);
  digitalWrite(BLPin, LOW);
  lcd.begin(16, 2);
  lcd.print("Hola Mundo");
  delay(3000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print(millis());

}
