#include "EMAFilter.h"

//Exponential Moving Average Filter

EMAFilter::EMAFilter(double vAlfa)
{
  _EMA_alpha = vAlfa;
}

int EMAFilter::EMALowPassFilter(int vNew)
{
  _EMA_cv = _EMA_alpha * vNew + (1 - _EMA_alpha) * _EMA_pv;
  return _EMA_cv;
}
