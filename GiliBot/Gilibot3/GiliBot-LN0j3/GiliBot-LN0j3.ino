#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
#include "MedianFilter.h"
#include "Motors.h"

SSD1306AsciiWire oled;
Motors Motores;

#define Ventana 100

MedianFilter medianFilterLeft(Ventana, 0);
MedianFilter medianFilterFront(Ventana, 0);
MedianFilter medianFilterRight(Ventana, 0);

int sensorPinRight = A0;
int sensorPinFront = A1;
int sensorPinLeft = A2;

int sensorLeft, sensorFront, sensorRight;
int sensorLeftMF, sensorFrontMF, sensorRightMF;
int diferencial;

void setup() {
  Serial.begin(9600);
  Motores.Stop();
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
  oled.setCol(36);
  oled.print("Vers.LN0j3");
  delay(3000);
  oled.clear();
//  Motores.Move(100, 100);
//  delay(2000);
//  Motores.Stop();
}

void loop() {
  sensorLeftMF = ReadSensor(sensorLeft, medianFilterLeft, sensorPinLeft);
  sensorFrontMF = ReadSensor(sensorFront, medianFilterFront, sensorPinFront);
  sensorRightMF = ReadSensor(sensorRight, medianFilterRight, sensorPinRight);
  oled.setRow(0);
  oled.setCol(0);
  oled.print(sensorLeft);
  oled.print("  ");
  oled.print(sensorFront);
  oled.print("  ");
  oled.print(sensorRight);
  oled.print("  ");
  oled.setRow(2);
  oled.setCol(0);
  oled.print(sensorLeftMF);
  oled.print("  ");
  oled.print(sensorFrontMF);
  oled.print("  ");
  oled.print(sensorRightMF);
  oled.print("  ");
  oled.setRow(4);
  oled.setCol(0);
  diferencial = (sensorLeftMF - sensorRightMF) + 105;
  oled.print(diferencial);
  oled.print("  ");
}

int ReadSensor(int &sensor, MedianFilter &Filtro, int pin)
{
  sensor = analogRead(pin);
  Filtro.in(sensor);
  return Filtro.out();
}
