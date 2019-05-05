#include <Arduino.h>

//pins L293 - Mini PRO
#define AIN1 7
#define AIN2 8
#define PWMA 9
#define BIN1 12
#define BIN2 11
#define PWMB 10

#ifndef Motors293_h
#define Motors293_h
class Motors293 {
  public:
    Motors293();
    void Move(int vLeft, int vRight);
    void Stop();
    void Brake();

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
