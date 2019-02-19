#include <Servo.h>

const int SPIND = 5;
const int SPINI = 6;

const int OFFSETD = 4;
const int OFFSETI = 7;

const int STOPD = 1500;
const int STOPI = 1505;

const int AVZD = 1000;
const int AVZI = 2000;

const int RETD = 2000;
const int RETI = 1000;

Servo servoD;
Servo servoI;

char c;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  servoD.attach(SPIND);
  servoI.attach(SPINI);
  digitalWrite(13, HIGH);
  setServoD(STOPD);
  setServoI(STOPI);
  delay(8000);
  digitalWrite(13, LOW);
}

void loop() {
  while (!Serial.available());
  c = Serial.read();
  switch (c) {
    case ('0'):
      {
        setServoD(STOPD);
        setServoI(STOPI);
        break;
      }
    case ('1'):
      {
        setServoD(AVZD);
        setServoI(AVZI);

        break;
      }
    case ('2'):
      {
        setServoD(RETD);
        setServoI(RETI);
        break;
      }
    case ('3'):
      {
        setServoD(AVZD);
        setServoI(STOPI);
        break;
      }
    case ('4'):
      {
        setServoD(STOPD);
        setServoI(AVZI);
        break;
      }
    case ('5'):
      {
        setServoD(RETD);
        setServoI(AVZI);
        break;
      }
    case ('6'):
      {
        setServoD(AVZD);
        setServoI(RETI);
        break;
      }
  }
}

void setServoD(int pos)
{
  servoD.writeMicroseconds(pos + OFFSETD);
}

void setServoI(int pos)
{
  servoI.writeMicroseconds(pos + OFFSETI);
}
