#include "Motors293.h"

int sensorPinR = A0;
int sensorPinL = A1;
int sensorValueR = 0;
int sensorValueL = 0;
int i = 0;

#define LED 13

#define FL 100
#define FR 85
#define RL -20
#define RR -20
#define umbral 300

Motors293 Motores;

void setup() {
  Serial.begin(9600);
  delay(1000);
  Motores.Stop();
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  for (i = 0; i < 20  ; i++)
  {
    Flash();
  }
  delay(2000);
}

void loop() {
  sensorValueL = analogRead(sensorPinL);
  sensorValueR = analogRead(sensorPinR);
  Serial.print(sensorValueL);
  Serial.print(",");
  Serial.println(sensorValueR);
  if (sensorValueL <= umbral && sensorValueR <= umbral)
  {
    Motores.Move(FL, FR);
  }
  if (sensorValueL >= umbral && sensorValueR <= umbral)
  {
    Motores.Move(RL, FR);
  }
    if (sensorValueL <= umbral && sensorValueR >= umbral)
  {
    Motores.Move(FL, RR);
  }
  if (sensorValueL >= umbral && sensorValueR >= umbral)
  {
    Motores.Stop();
  }
}

void Flash()
{
  digitalWrite(LED, HIGH);
  delay(25);
  digitalWrite(LED, LOW);
  delay(100);
}
