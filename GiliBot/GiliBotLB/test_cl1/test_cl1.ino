#include "SensoresIR.h"

SensoresIR sensores;
int vSensorLeft;
int vSensorFront;
int vSensorRight;
int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensores.ReadABS(vSensorLeft, vSensorFront, vSensorRight);
  Serial.print("I ");
  Serial.print(vSensorLeft);
  Serial.print(" F ");
  Serial.print(vSensorFront);
  Serial.print(" D ");
  Serial.println(vSensorRight);
  delay(50);
  digitalWrite(ledPin, !digitalRead(ledPin));
}
