#include "SensoresIR.h"

SensoresIR::SensoresIR()
{
  //Constructor
  vSensorPinLeft = A0;
  vSensorPinFront = A1;
  vSensorPinRight = A2;
}

void SensoresIR::ReadABS(int &vLeft, int &vFront, int &vRight)
{
  vLeft = ReadLeft();
  vFront = ReadFront();
  vRight = ReadRight();
}
int SensoresIR::ReadLeft()
{
  return analogRead(vSensorPinLeft);
}
int SensoresIR::ReadFront()
{
  return analogRead(vSensorPinFront);
}
int SensoresIR::ReadRight()
{
  return analogRead(vSensorPinRight);
}
