#include <Arduino.h>

#ifndef EMAFilter_h
#define EMAFilter_h
class EMAFilter {
  public:
    EMAFilter(double vAlfa);
    int LowPassFilter(int vNew);

  private:
    float _EMA_alpha;
    int _EMA_pv = 0;
};
#endif
