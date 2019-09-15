//CONFIGURAR Motors293.h si no coincide
#include "Motors293.h"

#define LED 13
#define PAUSA 3000

int i = 0;

Motors293 Motores;

void setup() {
  Motores.Stop();
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  delay(2000);
  for (i = 0; i < 20  ; i++)
  {
    Flash();
  }
  delay(2000);
}

void loop() {
  //Avanza izquierda
  Motores.Move(100, 0);
  delay(PAUSA);
  Motores.Stop();
  Flash();
  delay(PAUSA);
  //Avanza derecha
  Motores.Move(0, 100);
  delay(PAUSA);
  Motores.Stop();
  Flash();
  delay(PAUSA);
  //Retrocede izquierda
  Motores.Move(-100, 0);
  delay(PAUSA);
  Motores.Stop();
  Flash();
  delay(PAUSA);
  //Retrocede derecha
  Motores.Move(0, -100);
  delay(PAUSA);
  Motores.Stop();
  Flash();
  delay(PAUSA);
  //Avanzan ambos
  Motores.Move(100, 100);
  delay(PAUSA);
  Motores.Stop();
  Flash();
  delay(PAUSA);
  //Retroceden ambos
  Motores.Move(-100, -100);
  delay(PAUSA);
  Motores.Stop();
  Flash();
  delay(2 * PAUSA);
}

void Flash()
{
  digitalWrite(LED, HIGH);
  delay(25);
  digitalWrite(LED, LOW);
  delay(100);
}
