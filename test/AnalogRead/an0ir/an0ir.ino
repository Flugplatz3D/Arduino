#include "MedianFilter.h"

MedianFilter medianFilterAn0(50, 2000);

int sensorPin = PA0;
int ledPin = PB11;
int placaPin = PB1;
int sensorValueON = 0;
int sensorValueOFF = 0;
int sensorValueF = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(placaPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(ledPin, LOW);
  sensorValueON = analogRead(sensorPin);
  delayMicroseconds(750);
  digitalWrite(ledPin, HIGH);
  sensorValueOFF = analogRead(sensorPin);
  medianFilterAn0.in(sensorValueON);
  sensorValueF = medianFilterAn0.out();
  Serial.print(sensorValueON);
  Serial.print(",");
  Serial.print(sensorValueOFF);
  Serial.print(",");
  Serial.println(sensorValueF);
  if (sensorValueON < 2000)
  {
    digitalWrite(placaPin, HIGH);
  }
  else
  {
    digitalWrite(placaPin, LOW);
  }
  delay(30);
}
