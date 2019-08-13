#include <Arduino.h>

////Micro PRO - pins L293
//#define AIN1 7 //2
//#define AIN2 8 //7
//#define PWMA 9 //1
//#define BIN1 14 //12 //10
//#define BIN2 16 //11 //15
//#define PWMB 10 //9

#define BIN1 7 //2
#define BIN2 8 //7
#define PWMB 9 //1
#define AIN1 14 //12 //10
#define AIN2 16 //11 //15
#define PWMA 10 //9

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
