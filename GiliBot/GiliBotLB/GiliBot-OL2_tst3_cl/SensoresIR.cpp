#include "SensoresIR.h"

SensoresIR::SensoresIR()
{
  //Constructor
  mSensorPinLeft = A0;
  mSensorPinFront = A1;
  mSensorPinRight = A2;
}

void SensoresIR::ReadABS(int &vLeft, int &vFront, int &vRight)
{
  vLeft = ReadLeft();
  vFront = ReadFront();
  vRight = ReadRight();
}
int SensoresIR::ReadWalls()
{
  return mFront;
}
int SensoresIR::ReadLeft()
{
  mLeft = analogRead(mSensorPinLeft);
  return mLeft;
}
int SensoresIR::ReadFront()
{
  mFront = analogRead(mSensorPinFront);
  return mFront;
}
int SensoresIR::ReadRight()
{
  mRight=analogRead(mSensorPinRight);
  return mRight;
}
