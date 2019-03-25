#include <Servo.h>

const int SPIND = 2;

Servo servo1;

void setup() {
  Serial.begin(9600);
  servo1.attach(SPIND);
  pinMode(13, OUTPUT);
}

void loop() {
  servo1.write(1405);
  delay(3000);
  servo1.write(2000);
  delay(3000);
  servo1.write(1405  );
  delay(3000);
  servo1.write(1000);
  digitalWrite(13, HIGH);
  delay(3000);
  digitalWrite(13, LOW);
}
