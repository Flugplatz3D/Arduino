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
  vLeft = analogRead(mSensorPinLeft);
  vFront = analogRead(mSensorPinFront);
  vRight = analogRead(mSensorPinRight);
}
int SensoresIR::ReadWalls()
{
  int Walls = 1000;

  mLeft = ReadLeft();
  mFront = ReadFront();
  mRight = ReadRight();
  if (mLeft < LHist) Walls = Walls + 100;
  if (mFront < FHist) Walls = Walls + 10;
  if (mRight < RHist) Walls = Walls + 1;
  return Walls;
}
int SensoresIR::ReadLEma()
{
  int retVal = 0;
  mLeft = ReadLeft();
  if (mLeft < LHist) retVal = 1;
  return retVal;
}
int SensoresIR::ReadFEma()
{
  int retVal = 0;
  mFront = ReadFront();
  if (mFront < FHist) retVal = 1;
  return retVal;
}
int SensoresIR::ReadREma()
{
  int retVal = 0;
  mRight = ReadFront();
  if (mRight < RHist) retVal = 1;
  return retVal;
}
int SensoresIR::ReadLeft()
{
  mActLeft = analogRead(mSensorPinLeft);
  mStoLeft = EMA_function(ema_alpha, mActLeft, mStoLeft);
  return mStoLeft;
}
int SensoresIR::ReadFront()
{
  mActFront = analogRead(mSensorPinFront);
  mStoFront = EMA_function(ema_alpha, mActFront, mStoFront);
  return mStoFront;
}
int SensoresIR::ReadRight()
{
  mActRight = analogRead(mSensorPinRight);
  mStoRight = EMA_function(ema_alpha, mActRight, mStoRight);
  return mStoRight;
}
int SensoresIR::EMA_function(float alpha, int actual, int stored)
{
  return round(alpha * actual) + round((1 - alpha) * stored);
}
int SensoresIR::ReadLAbs()
{
  return analogRead(mSensorPinLeft);
}
int SensoresIR::ReadFAbs()
{
  return analogRead(mSensorPinFront);
}
int SensoresIR::ReadRAbs()
{
  return analogRead(mSensorPinRight);
}
