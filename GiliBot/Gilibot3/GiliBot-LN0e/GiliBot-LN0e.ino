#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
#include "MedianFilterLib.h"

SSD1306AsciiWire oled;

#define Ventana 60
MedianFilter<int> medianFilterLeft(Ventana);
MedianFilter<int> medianFilterFront(Ventana);
MedianFilter<int> medianFilterRight(Ventana);

int sensorPinRight = A0;
int sensorPinFront = A1;
int sensorPinLeft = A2;
int sensorLeft = 0;
int sensorFront = 0;
int sensorRight = 0;
int sensorLeftMF = 0;
int sensorFrontMF = 0;
int sensorRightMF = 0;

void setup() {
  Wire.begin();
  Wire.setClock(400000L);
  oled.begin(&Adafruit128x32, 0x3C);
  oled.setFont(lcd5x7);
  oled.clear();
  oled.setRow(0);
  oled.setCol(24);
  oled.set2X();
  oled.print("GiliBot");
  oled.set1X();
  oled.setRow(3);
  oled.setCol(38);
  oled.print("Vers.LN0e");
  delay(3000);
  oled.clear();
}

void loop() {
  sensorRight = analogRead(sensorPinRight);
  sensorRightMF = medianFilterRight.AddValue(sensorRight);
  sensorFront = analogRead(sensorPinFront);
  sensorFrontMF = medianFilterFront.AddValue(sensorFront);
  sensorLeft = analogRead(sensorPinLeft);
  sensorLeftMF = medianFilterLeft.AddValue(sensorLeft);
  oled.setRow(0);
  oled.setCol(0);
  oled.print("R - ");
  oled.print(sensorRightMF);
  oled.print("  ");
  oled.setCol(64);
  oled.print(sensorRight);
  oled.print("  ");
  oled.setRow(1);
  oled.setCol(0);
  oled.print("F - ");
  oled.print(sensorFrontMF);
  oled.print("  ");
  oled.setCol(64);
  oled.print(sensorFront);
  oled.print("  ");
  oled.setRow(2);
  oled.setCol(0);
  oled.print("L - ");
  oled.print(sensorLeftMF);
  oled.print("  ");
  oled.setCol(64);
  oled.print(sensorLeft);
  oled.print("  ");
}
