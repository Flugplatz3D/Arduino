#include <Arduino.h>

#define LHist 60
#define FHist 60
#define RHist 60

#define BIN1 8 // 2 // 13
#define BIN2 7 // 7 // 14
#define PWMB 9 // 1 // 15

#ifndef SensoresIR_h
#define SensoresIR_h
class SensoresIR {
  public:
    SensoresIR();
    // ampersand is byRef operator
    void ReadABS(int &vLeft, int &vFront, int &vRight);
    int ReadWalls();
    
  private:
    int mSensorPinLeft;
    int mSensorPinFront;
    int mSensorPinRight;
    int mLeft;
    int mFront;
    int mRight;
    int mPrevLeft;
    int mPrevFront;
    int mPrevRight;
    int ReadLeft();
    int ReadFront();
    int ReadRight();
};
#endif
