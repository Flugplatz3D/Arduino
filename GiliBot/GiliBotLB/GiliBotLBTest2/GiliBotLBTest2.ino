#include "Motors293.h"

#define FADE 30
#define PAUSA 750
#define LED 13

int i = 0;

Motors293 Motores;

void setup() {
  Motores.Stop();
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(1500);
  for (i = 0; i < 10  ; i++)
  {
    Flash();
  }
  delay(2000);
}

void loop() {
  for (i = 0; i < 80  ; i++)
  {
    Motores.Move(i, i);
    delay(FADE);
  }
  delay(PAUSA);
  for (i = 80; i > 0  ; i--)
  {
    Motores.Move(i, i);
    delay(FADE);
  }
  Motores.Stop();
  Flash();
  delay(PAUSA);
}

void Flash()
{
  digitalWrite(LED, HIGH);
  delay(50);
  digitalWrite(LED, LOW);
  delay(100);
}
