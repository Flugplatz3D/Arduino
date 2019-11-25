#include "Motors293.h"

int sensorPinR = A0;
int sensorPinL = A1;
int sensorValueR = 0;
int sensorValueL = 0;
int i = 0, f = 0;
#define LED 13

Motors293 Motores;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(2000);
  Motores.Stop();
}

void loop() {
  sensorValueR = analogRead(sensorPinR);
  sensorValueL = analogRead(sensorPinL);
  if (sensorValueR <= 50 && sensorValueL <= 50)
  {
    Motores.Move(100, 100);
    f = 0;
  }
  if (sensorValueR >= 50 && sensorValueL >= 50)
  {
    if (f < 100)
    {
      Motores.Move(-100, -100);
      f++;
    }
    else
    {
      Motores.Stop();
    }
  }
  if (sensorValueR >= 50 && sensorValueL <= 50)
  {
    Motores.Move(-75, 125);
  }
  if (sensorValueR <= 50 && sensorValueL >= 50)
  {
    Motores.Move(125, -75);
  }
}
