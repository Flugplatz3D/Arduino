#include "SensorIR.h"

#define Ventana 125

SensorIR sensorAn0(A0);
SensorIR sensorAn1(A1);
SensorIR sensorAn2(A0); //solo hay dos sensores

MedianFilter medianFilterAn0(Ventana, 0);
MedianFilter medianFilterAn1(Ventana, 0);
MedianFilter medianFilterAn2(Ventana, 0);

int lecturaAn0 = 0;
int lecturaAn1 = 0;
int lecturaAn2 = 0;

void setup() {
  Serial.begin(9600);
  sensorAn0.IniciaFiltro(medianFilterAn0);
  sensorAn1.IniciaFiltro(medianFilterAn1);
  sensorAn2.IniciaFiltro(medianFilterAn2);
}

void loop() {
  lecturaAn0 = sensorAn0.LeeSensor();
  lecturaAn1 = sensorAn1.LeeSensor();
  lecturaAn2 = sensorAn2.LeeSensor();
//  Serial.print(lecturaAn0);
//  Serial.print(",");
  Serial.print(sensorAn0.PasaFiltro(lecturaAn0));
  Serial.print(",");
//  Serial.print(lecturaAn1);
//  Serial.print(",");
  Serial.print(sensorAn1.PasaFiltro(lecturaAn1));
  Serial.print(",");
//  Serial.print(lecturaAn2);
//  Serial.print(",");
  Serial.print(sensorAn2.PasaFiltro(lecturaAn2));
//  Serial.print(",");
//  Serial.print(sizeof(medianFilterAn0));
//  Serial.print(",");
//  Serial.print(sizeof(medianFilterAn1));
//  Serial.print(",");
//  Serial.print(sizeof(medianFilterAn2));
  Serial.println();
  delay(10);
}
