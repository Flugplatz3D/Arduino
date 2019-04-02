#include "MedianFilter.h"

MedianFilter medianFilterAn0(50, 4000);

int sensorPin = PA0;
int ledPin = PB1;
int sensorValue = 0;
int sensorValueF = 0;


void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  medianFilterAn0.in(sensorValue);
  sensorValueF = medianFilterAn0.out();
  if (sensorValueF < 3950)
  {
    digitalWrite(ledPin, HIGH );
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.println(sensorValueF);
  delay(10);
}
