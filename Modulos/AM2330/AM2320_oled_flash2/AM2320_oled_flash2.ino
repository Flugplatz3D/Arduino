#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C
#include <AM2320.h>

#define LED 17

AM2320 th;

SSD1306AsciiWire oled;

void setup() {
  pinMode(LED, OUTPUT);
  Wire.begin();
  Wire.setClock(400000L);
  //oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.begin(&SH1106_128x64, I2C_ADDRESS);
  oled.setFont(lcd5x7);
  oled.clear();
  oled.set2X();
  oled.println("AM2320");
  oled.println();
  oled.set1X();
  oled.print("Arduino");
  delay(3000);
  oled.clear();
}

void loop() {
  switch (th.Read()) {
    case 2:
      oled.setFont(lcd5x7);
      oled.set1X();
      oled.clear();
      oled.setRow(0);
      oled.setCol(0);
      oled.print("CRC failed");
      break;
    case 1:
      oled.setFont(lcd5x7);
      oled.set1X();
      oled.clear();
      oled.setRow(0);
      oled.setCol(0);
      oled.print("Sensor offline");
      break;
    case 0:
      oled.setFont(lcd5x7);
      oled.setRow(0);
      oled.setCol(0);
      oled.print("Temp:  ");
//      oled.setFont(Verdana_digits_24);
      oled.setFont(lcdnums14x24);
      oled.print(th.t);
      oled.clearToEOL();
      oled.setFont(lcd5x7);
      oled.setRow(4);
      oled.setCol(0);
      oled.print("Humid: ");
//      oled.setFont(Verdana_digits_24);
      oled.setFont(lcdnums14x24);
      oled.print(th.h);
      oled.clearToEOL();
      break;
  }
  oled.setFont(lcd5x7);
  oled.setRow(7);
  oled.setCol(0);
  oled.print((millis()/1000)/60);
  oled.clearToEOL();
  digitalWrite(LED, LOW );
  delay(1);
  digitalWrite(LED, HIGH );
  delay(5000);
}
