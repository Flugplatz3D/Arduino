#include <Arduino.h>

#ifndef SensoresIR_h
#define SensoresIR_h
class SensoresIR {
  public:
    SensoresIR();
    // ampersand is byRef operator
    void ReadABS(int &vLeft, int &vFront, int &vRight);

  private:
    int vSensorPinLeft;
    int vSensorPinFront;
    int vSensorPinRight;
    int ReadLeft();
    int ReadFront();
    int ReadRight();
};
#endif
