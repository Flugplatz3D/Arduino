#include <Arduino.h>

//Mini PRO - pins L293
#define AIN1 14
#define AIN2 16
#define PWMA 10
#define BIN1 7
#define BIN2 8
#define PWMB 9

#ifndef Motors293_h
#define Motors293_h
class Motors293 {
  public:
    Motors293();
    void Move(int vLeft, int vRight);
    void Stop();

  private:
    int _vLeftSet;
    int _vRightSet;
    void FrontLeft();
    void FrontRight();
    void ReverseLeft();
    void ReverseRight();
    void StopLeft();
    void StopRight();
};
#endif
