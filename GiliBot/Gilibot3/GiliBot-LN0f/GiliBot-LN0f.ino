#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
#include "MedianFilterLib.h"

SSD1306AsciiWire oled;

#define Ventana 75
MedianFilter<int> medianFilterLeft(Ventana);
MedianFilter<int> medianFilterFront(Ventana);
MedianFilter<int> medianFilterRight(Ventana);

int sensorPinRight = A0;
int sensorPinFront = A1;
int sensorPinLeft = A2;
int sensorLeft, sensorFront, sensorRight;

void setup() {
  Wire.begin();
  Wire.setClock(400000L);
  oled.begin(&Adafruit128x64, 0x3C);
  oled.setFont(lcd5x7);
  oled.clear();
  oled.setRow(0);
  oled.setCol(24);
  oled.set2X();
  oled.print("GiliBot");
  oled.set1X();
  oled.setRow(3);
  oled.setCol(38);
  oled.print("Vers.LN0f");
  delay(3000);
  oled.clear();
}

void loop() {
  oled.setRow(0);
  oled.setCol(0);
  oled.print(ReadSensor(sensorLeft, medianFilterLeft, sensorPinLeft));
  oled.print("  ");
  oled.print(ReadSensor(sensorFront, medianFilterFront, sensorPinFront));
  oled.print("  "); 
  oled.print(ReadSensor(sensorRight, medianFilterRight, sensorPinRight));
  oled.print("  ");
  oled.setRow(2);
  oled.setCol(0);
  oled.print(sensorLeft);
  oled.print("  ");
  oled.print(sensorFront);
  oled.print("  ");
  oled.print(sensorRight);
  oled.print("  ");
}

int ReadSensor(int &sensor, MedianFilter<int> &Filtro, int pin)
{
  sensor = analogRead(pin);
  return Filtro.AddValue(sensor);
}
