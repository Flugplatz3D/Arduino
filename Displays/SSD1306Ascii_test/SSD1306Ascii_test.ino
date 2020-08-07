#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

SSD1306AsciiWire oled;

void setup () {
  Serial.begin(9600);
  Wire.begin();
  Wire.setClock(400000L);
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  //oled.begin(&SH1106_128x64, I2C_ADDRESS);
  oled.setFont(System5x7);
  oled.clear();
  oled.set2X();
  oled.println("Test");
  oled.println("SH1106");
  oled.set1X();
  oled.println("");
  oled.print("SSD1306Ascii lib");
  delay(4000);
  oled.clear();
  oled.set2X();
}
//------------------------------------------------------------------------------
void loop () {
  oled.setRow(0);
  oled.setCol(0);
  oled.print(millis());
  oled.clearToEOL();
  Serial.println(millis());
}
