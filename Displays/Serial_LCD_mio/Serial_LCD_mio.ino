#include <LiquidCrystal.h>

#define Luz_ON 134
#define Luz_OFF 135
#define Gotoxy 138
#define Cls 12

// --- ARDUINO PIN DEFINITIONS
uint8_t RSPin = 2;
uint8_t RWPin = 3;
uint8_t ENPin = 4;
uint8_t D4Pin = 5;
uint8_t D5Pin = 6;
uint8_t D6Pin = 7;
uint8_t D7Pin = 8;
uint8_t BLPin = 9;

byte inKey;  // Character received from serial input
byte Col;
byte Fila;

// initialize the LCD at pins defined above
LiquidCrystal lcd(RSPin, RWPin, ENPin, D4Pin, D5Pin, D6Pin, D7Pin);

void setup() {
  // initialize the serial communications:
  Serial.begin(9600);

  // set up the LCD's number of rows and columns:
  lcd.begin(16, 2);

  // Set up the backlight
  pinMode(BLPin, OUTPUT);
  lcd.clear();
}

void loop()
{
  while (Serial.available() > 0) {
    inKey = Serial.read();
    switch (inKey)
    {
      case Cls:
        {
          lcd.clear();
          break;
        }
      case Luz_ON:
        {
          digitalWrite(BLPin, HIGH);
          break;
        }
      case Luz_OFF:
        {
          digitalWrite(BLPin, LOW);
          break;
        }
      case Gotoxy:
        {
          while (Serial.available() == 0);
          Fila = Serial.read();
          while (Serial.available() == 0);
          Col = Serial.read();
          lcd.setCursor(Col, Fila);
          break;
        }
      default:
        {
          lcd.write(inKey);
          break;
        }
    }
  }
}

