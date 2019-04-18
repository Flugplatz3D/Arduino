#include "SingleEMAFilterLib.h"

SingleEMAFilter<int> singleEMAFilter(0.01);

int sensorPin = PA0;
int ledPin = PB11;
int placaPin = PB1;
int sensorValueON = 0;
int sensorValueOFF = 0;
int sensorValueF = 0;
int rawMeasure = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(placaPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  sensorValueON = analogRead(sensorPin);
  singleEMAFilter.AddValue(sensorValueON);
  sensorValueF = singleEMAFilter.GetLowPass();
  Serial.print(sensorValueON);
  Serial.print(",");
  Serial.println(sensorValueF);
  if (sensorValueF < 3750)
  {
    digitalWrite(placaPin, HIGH);
  }
  else
  {
    digitalWrite(placaPin, LOW);
  }
  delay(1);
}
