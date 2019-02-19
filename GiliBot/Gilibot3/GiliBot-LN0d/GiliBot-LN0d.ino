#include "MedianFilterLib.h"

#define Ventana 100
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
  Serial.begin(9600);
}

void loop() {
  sensorRight = analogRead(sensorPinRight);
  sensorRightMF = medianFilterRight.AddValue(sensorRight);
  Serial.print(sensorRight);
  Serial.print(",");
  Serial.print(sensorRightMF);
  sensorFront = analogRead(sensorPinFront);
  sensorFrontMF = medianFilterFront.AddValue(sensorFront);
  Serial.print(",");
  Serial.print(sensorFront);
  Serial.print(",");
  Serial.print(sensorFrontMF);
  sensorLeft = analogRead(sensorPinLeft);
  sensorLeftMF = medianFilterLeft.AddValue(sensorLeft);
  Serial.print(",");
  Serial.print(sensorLeft);
  Serial.print(",");
  Serial.println(sensorLeftMF);
}
