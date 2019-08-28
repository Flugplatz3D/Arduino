#include <Arduino.h>

//Mini PRO - pins L293
#define AIN1 16 //10
#define AIN2 14 //15
#define PWMA 10 //9
#define BIN1 8 //2
#define BIN2 7 //7
#define PWMB 9 //1

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
