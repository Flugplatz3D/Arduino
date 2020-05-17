#include "Motors293.h"

//#define VelicidadFL  70
//#define VelicidadFR  70
//#define VelicidadRL  -70
//#define VelicidadRR  -70
#define VelicidadFL  170
#define VelicidadFR  170
#define VelicidadRL  -170
#define VelicidadRR  -170

float EMA_ALPHA = 0.5;
int EMA_LP = 0;
int EMA_HP = 0;
int sensorPin = A0;
int ledPin = 13;
int sensorValue = 0;
int sensorValueF = 0;
int rawMeasure = 0;

Motors293 Motores;

void setup() {
  Motores.Stop();
  pinMode(ledPin, OUTPUT);
  delay(2000);
  for (int i = 0; i < 10  ; i++)
  {
    Flash();
  }
  delay(2000);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  sensorValueF = EMALowPassFilter(sensorValue);
  if (sensorValueF < 850)
  {
    if (sensorValueF < 750)
    {
      digitalWrite(ledPin, LOW);
      Motores.Move(VelicidadRL, VelicidadRR);
    }
    else
    {
      Motores.Stop();
      digitalWrite(ledPin, HIGH);
    }
  }
  else
  {
    digitalWrite(ledPin, LOW);
    Motores.Move(VelicidadFL, VelicidadFR);
  }
}

int EMALowPassFilter(int value)
{
  EMA_LP = EMA_ALPHA * value + (1 - EMA_ALPHA) * EMA_LP;
  return EMA_LP;
}

void Flash()
{
  digitalWrite(ledPin, HIGH);
  delay(50);
  digitalWrite(ledPin, LOW);
  delay(100);
}
