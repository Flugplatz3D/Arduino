#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
#include "MedianFilter.h"

SSD1306AsciiWire oled;

#define Ventana 50

MedianFilter medianFilterLeft(Ventana, 0);
MedianFilter medianFilterFront(Ventana, 0);
MedianFilter medianFilterRight(Ventana, 0);

int sensorPinRight = A0;
int sensorPinFront = A1;
int sensorPinLeft = A2;

int sensorLeft, sensorFront, sensorRight;
int sensorLeftMF, sensorFrontMF, sensorRightMF;
//int diferencial;

void setup() {
  Serial.begin(9600);
  //  Wire.begin();
  //  Wire.setClock(400000L);
  //  oled.begin(&Adafruit128x64, 0x3C);
  //  oled.setFont(lcd5x7);
  //  oled.clear();
  //  oled.setRow(0);
  //  oled.setCol(24);
  //  oled.set2X();
  //  oled.print("GiliBot");
  //  oled.set1X();
  //  oled.setRow(3);
  //  oled.setCol(38);
  //  oled.print("Vers.LN0j");
  //  delay(3000);
  //  oled.clear();
}

void loop() {
  //  oled.setRow(0);
  //  oled.setCol(0);
  //  sensorLeftMF = ReadSensor(sensorLeft, medianFilterLeft, sensorPinLeft);
  //  oled.print(sensorLeftMF);
  //  oled.print("  ");
  //  sensorFrontMF = ReadSensor(sensorFront, medianFilterFront, sensorPinFront);
  //  oled.print(sensorFrontMF);
  //  oled.print("  ");
  //  sensorRightMF = ReadSensor(sensorRight, medianFilterRight, sensorPinRight);
  //  oled.print(sensorRightMF);
  //  oled.print("  ");
  //  oled.setRow(2);
  //  oled.setCol(0);
  //  diferencial = (sensorLeftMF - sensorRightMF) + 105;
  //  oled.print(diferencial);
  //  oled.print("  ");
  sensorLeftMF = ReadSensor(sensorLeft, medianFilterLeft, sensorPinLeft);
  sensorFrontMF = ReadSensor(sensorFront, medianFilterFront, sensorPinFront);
  sensorRightMF = ReadSensor(sensorRight, medianFilterRight, sensorPinRight);
  Serial.print(sensorLeftMF);
  Serial.print(",");
  Serial.print(sensorLeft);
  Serial.print(",");
  Serial.print(sensorFrontMF);
  Serial.print(",");
  Serial.print(sensorFront);
  Serial.print(",");
  Serial.print(sensorRightMF);
  Serial.print(",");
  Serial.print(sensorRight);
  Serial.println();
}

int ReadSensor(int &sensor, MedianFilter &Filtro, int pin)
{
  sensor = analogRead(pin);
  Filtro.in(sensor);
  return Filtro.out();
}
