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
      oled.set1X();
      oled.clear();
      oled.setRow(0);
      oled.setCol(0);
      oled.print("CRC failed");
      break;
    case 1:
      oled.set1X();
      oled.clear();
      oled.setRow(0);
      oled.setCol(0);
      oled.print("Sensor offline");
      break;
    case 0:
      oled.set1X();
      oled.setRow(0);
      oled.setCol(0);
      oled.print("Temp:  ");
      oled.set2X();
      oled.print(th.t);
      oled.clearToEOL();
      oled.set1X();
      oled.setRow(3);
      oled.setCol(0);
      oled.print("Humid: ");
      oled.set2X();
      oled.print(th.h);
      oled.clearToEOL();
      break;
  }
  oled.set1X();
  oled.setRow(7);
  oled.setCol(0);
  oled.print(millis());
  oled.clearToEOL();
  digitalWrite(LED, LOW );
  delay(5);
  digitalWrite(LED, HIGH );
  delay(5000);
}
