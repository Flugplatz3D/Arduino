#include "SensorIR.h"

SensorIR::SensorIR(int Pin)
{
  _pin = Pin;
}

int SensorIR::LeeSensor() {
  return analogRead(_pin);
}

void SensorIR::IniciaFiltro(MedianFilter Filtro) {
  pFiltro = &Filtro;
}

int SensorIR::PasaFiltro(int valor) {
  pFiltro -> in(valor);
  return pFiltro -> out();
}
