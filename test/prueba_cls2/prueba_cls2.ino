#include "SensorIR.h"

SensorIR sensorAn0(A0);
SensorIR sensorAn1(A1);

MedianFilter medianFilterAn0(100, 0);
MedianFilter medianFilterAn1(100, 0);

int lectura = 0;

void setup() {
  Serial.begin(9600);
  sensorAn0.IniciaFiltro(medianFilterAn0);
  sensorAn1.IniciaFiltro(medianFilterAn1);
}

void loop() {
  lectura = sensorAn0.LeeSensor();
  Serial.print(lectura);
  Serial.print(",");
  Serial.print(sensorAn0.PasaFiltro(lectura));
  Serial.print(",");
  lectura = sensorAn1.LeeSensor();
  Serial.print(lectura);
  Serial.print(",");
  Serial.println(sensorAn1.PasaFiltro(lectura));
  //  delay(5);
}
