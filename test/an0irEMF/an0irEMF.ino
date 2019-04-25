#include "SingleEMAFilterLib.h"

SingleEMAFilter<int> singleEMAFilter(0.01);

int sensorPin = PA0;
int ledPin = PB11;
int placaPin = PB1;
int sensorValue = 0;
int sensorValueF = 0;
int rawMeasure = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(placaPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  singleEMAFilter.AddValue(sensorValue);
  sensorValueF = singleEMAFilter.GetLowPass();
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.println(sensorValueF);
  if (sensorValueF < 3500)
  {
    digitalWrite(placaPin, HIGH);
  }
  else
  {
    digitalWrite(placaPin, LOW);
  }
  delay(1);
}
