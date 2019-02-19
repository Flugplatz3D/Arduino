#include <Arduino.h>
#include "MedianFilter.h"

#ifndef SensorIR_h
#define SensorIR_h
class SensorIR {
  public:
    SensorIR(int Pin);
    int LeeSensor();
    void IniciaFiltro(MedianFilter Filtro);
    int PasaFiltro(int valor);

  private:
    int _pin;
    MedianFilter *pFiltro;
};
#endif
