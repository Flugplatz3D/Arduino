#include "SensoresIR.h"

SensoresIR::SensoresIR()
{
  //Constructor
}

void ReadABS(int vLeft, int vFront, int vRight)
{
}

/*void Motors293::Move (int vLeft, int vRight)
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
  void Motors293::FrontLeft()
  {
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  }
  void Motors293::FrontRight()
  {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  }
  void Motors293::ReverseLeft()
  {
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  }
  void Motors293::ReverseRight()
  {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  }
  void Motors293::StopLeft()
  {
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  }
  void Motors293::StopRight()
  {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  }
  void Motors293::Stop()
  {
  analogWrite (PWMA, 0);
  analogWrite (PWMB, 0);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  }
*/
