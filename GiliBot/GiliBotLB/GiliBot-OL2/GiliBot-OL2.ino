#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

SSD1306AsciiWire oled;

int sensorPinLeft = A0;
int sensorPinFront = A1;
int sensorPinRight = A2;
int sensorLeft = 0;
int sensorFront = 0;
int sensorRight = 0;
int ledPin = 13;

void setup() {
  //  Serial.begin(9600);
  Wire.begin();
  Wire.setClock(400000L);
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
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
}

void loop() {
  sensorLeft = analogRead(sensorPinLeft);
  sensorFront = analogRead(sensorPinFront);
  sensorRight = analogRead(sensorPinRight);
  oled.setRow(0);
  oled.setCol(0);
  oled.print("R - ");
  oled.setRow(0);
  oled.setCol(24);
  oled.print(sensorRight);
  oled.clearToEOL();
  oled.setRow(1);
  oled.setCol(0);
  oled.print("F - ");
  oled.setRow(1);
  oled.setCol(24);
  oled.print(sensorFront);
  oled.clearToEOL();
  oled.setRow(2);
  oled.setCol(0);
  oled.print("L - ");
  oled.setRow(2);
  oled.setCol(24);
  oled.print(sensorLeft);
  oled.clearToEOL();
}
