#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

SSD1306AsciiWire oled;

void setup () {
  Wire.begin();
  Wire.setClock(400000L);
  //  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.begin(&SH1106_128x64, I2C_ADDRESS);
  oled.setFont(lcd5x7);
  oled.clear();
  oled.print("Test SH1106");
  delay(3000);
  oled.clear();
}

void loop () {
  oled.setRow(0);
  oled.setCol(0);
  oled.print(millis());
  oled.clearToEOL();
}
