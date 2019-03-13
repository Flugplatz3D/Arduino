#include <Arduino.h>

//pins TB6612FNG
#define AIN1 2
#define AIN2 4
#define PWMA 5
#define PWMB 6
#define BIN1 7
#define BIN2 8
#define STBY 9

#ifndef Motors_h
#define Motors_h
class Motors {
  public:
    Motors();
    void Move(int vLeft, int vRight);
    void Stop();

  private:
    int _vLeftSet;
    int _vRightSet;
    int _motLeft = 0;
    int _motRight = 0;
    void FrontLeft();
    void FrontRight();
    void ReverseLeft();
    void ReverseRight();
    void StopLeft();
    void StopRight();
};
#endif
