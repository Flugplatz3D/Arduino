#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

SSD1306AsciiWire oled;
unsigned long cuenta = 0;

void setup () {
  Wire.begin();
  Wire.setClock(400000L);
  //  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.begin(&SH1106_128x64, I2C_ADDRESS);
  //  oled.setFont(lcd5x7);
  //    oled.setFont(Verdana12);
  //  oled.setFont(Verdana_digits_24);
  //  oled.setFont(lcdnums14x24);
  //  oled.setFont(Cooper26);
  //  oled.setFont(Cooper26);
  oled.clear();
  oled.setFont(Callibri15);
  oled.print("Test SH1106");
  //  oled.print("Test");
  delay(3000);
//  oled.setFont(lcdnums14x24);
  oled.clear();
  //  oled.set2X();
}

void loop () {
  cuenta++;
  oled.setFont(Adafruit5x7);
  oled.setRow(0);
  oled.setCol(0);
  oled.print(cuenta);
  oled.clearToEOL();
  oled.setFont(lcdnums14x24);
  oled.setRow(4);
  oled.setCol(0);
  oled.print(cuenta / 10);
//  oled.print(":");
//  oled.print("0");
  oled.clearToEOL();
  delay(100);
}
