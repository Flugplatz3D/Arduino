#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3

#define TEST_DELAY 100

TM1637Display tm1637(CLK, DIO);

void setup() {
  Serial.begin(9600);
  tm1637.setBrightness(0x0f);
}

void loop() {
  tm1637.showNumberDec(millis()/250, true);
  Serial.println(millis());
}
