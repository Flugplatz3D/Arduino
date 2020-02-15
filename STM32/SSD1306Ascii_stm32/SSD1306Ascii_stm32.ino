#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

SSD1306AsciiWire oled;
unsigned long cuenta = 0;
unsigned long timeFlash = 0;

#define LED PB1
//#define LED PC13

void setup () {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  Wire.begin();
  Wire.setClock(400000L);
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  //  oled.begin(&SH1106_128x64, I2C_ADDRESS);
  oled.setFont(lcd5x7);
  oled.clear();
  oled.print("SSD1306Ascii");
  delay(3000);
  oled.clear();
  oled.set2X();
  timeFlash = millis();
}

void loop () {
  oled.setRow(0);
  oled.setCol(0);
  cuenta++;
  oled.print(cuenta);
  oled.clearToEOL();
  //delay(50);
  Serial.println(cuenta);
  //Flash sin delay
  if (millis() - timeFlash > 2000)
  {
    digitalWrite(LED, HIGH );
    delay(2);
    digitalWrite(LED, LOW );
    timeFlash = millis();
  }
}
