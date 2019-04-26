#include <Arduino.h>

#ifndef EMAFilter_h
#define EMAFilter_h
class EMAFilter {
  public:
    EMAFilter(double vAlfa);
    int EMALowPassFilter(int vNew);

  private:
    float _EMA_alpha;
    int _EMA_pv = 0;
    int _EMA_cv = 0;
};
#endif
