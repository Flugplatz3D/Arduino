#include "Motors.h"

Motors::Motors()
{
  pinMode (AIN1, OUTPUT);
  pinMode (AIN2, OUTPUT);
  pinMode (PWMA, OUTPUT);
  pinMode (BIN1, OUTPUT);
  pinMode (BIN2, OUTPUT);
  pinMode (PWMB, OUTPUT);
  pinMode (STBY, OUTPUT);
}
void Motors::Move (int vLeft, int vRight)
{
  _vLeftSet = constrain(vLeft, -255, 255);
  _vRightSet = constrain(vRight, -255, 255);
  if (_vLeftSet > 0)
  {
    FrontLeft();
    analogWrite (PWMB, _vLeftSet);
  }
  if (_vRightSet > 0) {
    FrontRight();
    analogWrite (PWMA, _vRightSet);
  }
  if (_vLeftSet < 0)
  {
    ReverseLeft();
    analogWrite (PWMB, abs(_vLeftSet));
  }
  if (_vRightSet < 0) {
    ReverseRight();
    analogWrite (PWMA, abs(_vRightSet));
  }
  if (_vLeftSet = 0)
  {
    StopLeft();
    analogWrite (PWMB, 0);
  }
  if (_vRightSet = 0) {
    StopRight();
    analogWrite (PWMA, 0);
  }
}
void Motors::FrontLeft()
{
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  digitalWrite(STBY, HIGH);
}
void Motors::FrontRight()
{
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(STBY, HIGH);
}
void Motors::ReverseLeft()
{
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  digitalWrite(STBY, HIGH);
}
void Motors::ReverseRight()
{
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(STBY, HIGH);
}
void Motors::StopLeft()
{
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}
void Motors::StopRight()
{
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
}
void Motors::Stop()
{
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(STBY, LOW);
}
void Motors::Brake()
{
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, HIGH);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, HIGH);
  digitalWrite(STBY, LOW);
}
