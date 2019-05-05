#include "Motors293.h"

Motors293 Motores;
int j = 0;

#define ledArduino 13

void setup() {
  pinMode(ledArduino, OUTPUT);
  for (int i = 0; i < 10; i++)
  {
    delay(200);
    digitalWrite(ledArduino, HIGH);
    delay(200);
    digitalWrite(ledArduino, LOW);
  }
}

void loop() {
  for (j = 0; j < 255; j += 10) {
    Motores.Move(j, j);
    delay (100);
  }
  delay(1000);
  for (j = 255; j >= 0; j -= 10) {
    Motores.Move(j, j);
    delay (100);
  }
  delay(1000);
}
