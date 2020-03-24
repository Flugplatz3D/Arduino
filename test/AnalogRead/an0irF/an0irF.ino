#include <MedianFilterLib.h>

MedianFilter<int> medianFilterAn0(125);

int sensorPin = A0;
int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  Serial.println(sizeof(medianFilterAn0));
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.println(medianFilterAn0.AddValue(sensorValue));
  delay(15);
}
