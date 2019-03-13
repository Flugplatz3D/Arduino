#include "MedianFilterLib.h"

#define Ventana 100
MedianFilter<int> medianFilterLeft(Ventana);
MedianFilter<int> medianFilterFront(Ventana);
MedianFilter<int> medianFilterRight(Ventana);

int sensorPinRight = A0;
int sensorPinFront = A1;
int sensorPinLeft = A2;
int sensorLeft, sensorFront, sensorRight;
int sensorLeftMF, sensorFrontMF, sensorRightMF;

byte miEstado, miEvento;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorLeftMF = ReadSensor(sensorLeft, medianFilterLeft, sensorPinLeft);
  sensorFrontMF = ReadSensor(sensorFront, medianFilterFront, sensorPinFront);
  sensorRightMF = ReadSensor(sensorRight, medianFilterRight, sensorPinRight);
  Serial.print(sensorLeftMF);
  Serial.print(",");
  Serial.print(sensorFrontMF);
  Serial.print(",");
  Serial.println(sensorRightMF);
  LeerEventos();
  FSMEstados();
}

int ReadSensor(int &sensor, MedianFilter<int> &Filtro, int pin)
{
  sensor = analogRead(pin);
  return Filtro.AddValue(sensor);
}

void LeerEventos() {
};

void FSMEstados()
{
}
