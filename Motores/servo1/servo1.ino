#include <Servo.h>

const int SPIND = 5;
const int SPINI = 6;

const int OFFSETD = 0;
const int OFFSETI = 0;

const int STOPD = 90 + OFFSETD;
const int STOPI = 90 + OFFSETI;

const int AVZD = 30 + OFFSETD;
const int AVZI = 150 + OFFSETI;

const int RETD = 150 + OFFSETD;
const int RETI = 30 + OFFSETI;

Servo servoD;
Servo servoI;

void setup() {
  Serial.begin(9600);
  servoD.attach(SPIND);
  servoI.attach(SPINI);
}

void loop() {
  setServoD(STOPD);
  setServoI(STOPI);
  delay(3000);
  setServoD(AVZD);
  setServoI(AVZI);
  delay(3000);
  setServoD(RETD);
  setServoI(RETI);
  delay(3000);
  Serial.println(millis(), DEC);
}

void setServoD(int pos)
{
  servoD.write(pos + OFFSETD);
}

void setServoI(int pos)
{
  servoI.write(pos + OFFSETI);
}

