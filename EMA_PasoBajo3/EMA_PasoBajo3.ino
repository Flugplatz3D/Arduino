#include "EMAFilter.h"
#include "DoubleEMAFilterLib.h"

int sensorPin = A0;
int ledPin = 2;
int placaPin = 13;
int sensorValue = 0;
int sensorValueF = 0;
int ema = 0;
int ema_ema = 0;
int sensorValueF2 = 0;
double ema_a = 0.05;

EMAFilter EMApbF(ema_a);

DoubleEMAFilter<int> doubleEMAFilter(0.025, 0.1);


void setup()
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  //  sensorValueF = EMApbF.LowPassFilter(sensorValue);
  sensorValueF = EMA_function(ema_a, sensorValue, sensorValueF);
  ema_ema = EMA_function(ema_a, sensorValueF, ema_ema);

  sensorValueF2 = 2 * sensorValueF - ema_ema;

  Serial.print(sensorValue);
  Serial.print(",");
//  Serial.print(sensorValueF);
//  Serial.print(",");
  Serial.println(sensorValueF2);

  if (sensorValueF2 < 1000)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW );
  }
}
int EMA_function(double alpha, int latest, int stored) {
  //  return round(alpha * latest) + round((1 - alpha) * stored);
  return alpha * latest + (1 - alpha) * stored;
}
