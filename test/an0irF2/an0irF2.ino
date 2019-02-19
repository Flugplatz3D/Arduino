#include "MedianFilter.h"

MedianFilter medianFilterAn0(200, 0);

int sensorPin = A0;
int sensorValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  medianFilterAn0.in(sensorValue);
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.println(medianFilterAn0.out());
//  delay(10);
}
