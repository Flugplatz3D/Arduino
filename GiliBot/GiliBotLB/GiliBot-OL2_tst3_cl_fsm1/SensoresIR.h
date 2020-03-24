#include <Arduino.h>

#define LHist 930
#define FHist 930
#define RHist 930

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
    int ReadLEma();
    int ReadFEma();
    int ReadREma();
    int ReadLAbs();
    int ReadFAbs();
    int ReadRAbs();

  private:
    int mSensorPinLeft, mSensorPinFront, mSensorPinRight;
    int mActLeft, mActFront, mActRight;
    int mLeft, mFront, mRight;
    int mStoLeft, mStoFront, mStoRight;
    int ReadLeft();
    int ReadFront();
    int ReadRight();
    float ema_alpha = 0.25;
    int EMA_function(float alpha, int actual, int stored);
};
#endif
