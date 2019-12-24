#include <Arduino.h>

//Arduino - pins L293 - ATMega328p
#define AIN1 11 // 10 // 18
#define AIN2 12 // 15 // 17
#define PWMA 10 // 9 // 16
#define BIN1 8 // 2 // 13
#define BIN2 7 // 7 // 14
#define PWMB 9 // 1 // 15

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
