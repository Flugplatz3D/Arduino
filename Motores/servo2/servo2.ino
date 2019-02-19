#include <Servo.h>

const int SPIND = 5;
const int SPINI = 6;

const int OFFSETD = -21;
const int OFFSETI = -21;

const int STOPD = 1500;
const int STOPI = 1500;

const int AVZD = 1000;
const int AVZI = 2000;

const int RETD = 2000;
const int RETI = 1000;

Servo servoD;
Servo servoI;

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
  setServoD(AVZD);
  setServoI(AVZI);
  delay(3000);
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  setServoD(STOPD);
  setServoI(STOPI);
  delay(3000);
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  setServoD(RETD);
  setServoI(RETI);
  delay(3000);
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  setServoD(STOPD);
  setServoI(STOPI);
  delay(3000);
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  Serial.println(millis(), DEC);
}

void setServoD(int pos)
{
  servoD.writeMicroseconds(pos + OFFSETD);
}

void setServoI(int pos)
{
  servoI.writeMicroseconds(pos + OFFSETI);
}

