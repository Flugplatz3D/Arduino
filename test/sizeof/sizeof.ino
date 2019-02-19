#include <MedianFilterLib.h>

MedianFilter<int> medianFilterLeft(100);
MedianFilter<int> medianFilterFront(100);
MedianFilter<int> medianFilterRight(100);

unsigned long minutot = 0;

void setup() {
  Serial.begin(9600);
  Serial.println(sizeof(medianFilterLeft));
  Serial.println(sizeof(medianFilterFront));
  Serial.println(sizeof(medianFilterRight));
  Serial.println(sizeof(minutot));
}

void loop() {

}
