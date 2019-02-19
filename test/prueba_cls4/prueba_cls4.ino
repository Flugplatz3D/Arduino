#include "SensorIR.h"

#define Ventana 99 //Maximo aproximado para cuatro filtros micros de 2kb. No hay memoria para ventana mas grande.

SensorIR sensorAn0(A0);
SensorIR sensorAn1(A1);
SensorIR sensorAn2(A2); //solo hay dos sensores
SensorIR sensorAn3(A3); //solo hay dos sensores

MedianFilter medianFilterAn0(Ventana, 1);
MedianFilter medianFilterAn1(Ventana, 1);
MedianFilter medianFilterAn2(Ventana, 1);
MedianFilter medianFilterAn3(Ventana, 1);

int lecturaAn0 = 0;
int lecturaAn1 = 0;
int lecturaAn2 = 0;
int lecturaAn3 = 0;

void setup() {
  Serial.begin(9600);
  sensorAn0.IniciaFiltro(medianFilterAn0);
  sensorAn1.IniciaFiltro(medianFilterAn1);
  sensorAn2.IniciaFiltro(medianFilterAn2);
  sensorAn3.IniciaFiltro(medianFilterAn3);
}

void loop() {
  lecturaAn0 = sensorAn0.LeeSensor();
  lecturaAn1 = sensorAn1.LeeSensor();
  lecturaAn2 = sensorAn2.LeeSensor();
  lecturaAn3 = sensorAn3.LeeSensor();
  Serial.print(lecturaAn0);
  Serial.print(",");
  Serial.print(sensorAn0.PasaFiltro(lecturaAn0));
  Serial.print(",");
  Serial.print(lecturaAn1);
  Serial.print(",");
  Serial.print(sensorAn1.PasaFiltro(lecturaAn1));
  Serial.print(",");
  Serial.print(lecturaAn2);
  Serial.print(",");
  Serial.print(sensorAn2.PasaFiltro(lecturaAn2));
  Serial.print(",");
  Serial.print(lecturaAn3);
  Serial.print(",");
  Serial.print(sensorAn3.PasaFiltro(lecturaAn3));
  Serial.println();
  delay(10);
}
