#include <MedianFilterLib.h>

MedianFilter<int> medianFilterAn0(25);
MedianFilter<int> medianFilterAn1(25);

int sensorPinA0 = A0;
int sensorValueA0 = 0;
int sensorPinA1 = A1;
int sensorValueA1 = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValueA0 = analogRead(sensorPinA0);
  sensorValueA1 = analogRead(sensorPinA1);
  Serial.print(medianFilterAn0.AddValue(sensorValueA0));
  Serial.print(",");
  Serial.println(medianFilterAn1.AddValue(sensorValueA1));
  //delay(25);
}
