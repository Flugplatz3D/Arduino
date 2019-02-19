#include "SensorIR.h"
//#include "MedianFilter.h"

SensorIR sensorAn0(A0);
MedianFilter medianFilterAn0(150, 0);

int lectura = 0;

//MedianFilter *p_medianFilterAn0;

void setup() {
  Serial.begin(9600);
  //  p_medianFilterAn0 = &medianFilterAn0;
  sensorAn0.IniciaFiltro(medianFilterAn0);
}

void loop() {
  lectura = sensorAn0.LeeSensor();
  //  p_medianFilterAn0 -> in(lectura);
  Serial.print(lectura);
  Serial.print(",");
  Serial.println(sensorAn0.PasaFiltro(lectura));
  //  Serial.println(p_medianFilterAn0 -> out());
  delay(10);
}
