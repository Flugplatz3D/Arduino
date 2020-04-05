#include "Motors293.h"

#define FADE 3
#define PAUSA 250
#define LED 13

int i = 0;

Motors293 Motores;

void setup() {
  Motores.Stop();
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  delay(500);
  for (i = 0; i < 20  ; i++)
  {
    Flash();
  }
  delay(1500);
}

void loop() {
  //Avanza izquierda
  for (i = 0; i < 255  ; i++)
  {
    Motores.Move(i, 0);
    delay(FADE);
  }
  delay(PAUSA);
  for (i = 255; i > 0  ; i--)
  {
    Motores.Move(i, 0);
    delay(FADE);
  }
  Motores.Stop();
  Flash();
  delay(PAUSA);
  //Avanza derecha
  for (i = 0; i < 255  ; i++)
  {
    Motores.Move(0, i);
    delay(FADE);
  }
  delay(PAUSA);
  for (i = 255; i > 0  ; i--)
  {
    Motores.Move(0, i);
    delay(FADE);
  }
  Motores.Stop();
  Flash();
  delay(PAUSA);
  //Retrocede izquierda
  for (i = 0; i > -255  ; i--)
  {
    Motores.Move(i, 0);
    delay(FADE);
  }
  delay(PAUSA);
  for (i = -255; i < 0  ; i++)
  {
    Motores.Move(i, 0);
    delay(FADE);
  }
  Motores.Stop();
  Flash();
  delay(PAUSA);
  //Retrocede derecha
  for (i = 0; i > -255  ; i--)
  {
    Motores.Move(0, i);
    delay(FADE);
  }
  delay(PAUSA);
  for (i = -255; i < 0  ; i++)
  {
    Motores.Move(0, i);
    delay(FADE);
  }
  Motores.Stop();
  Flash();
  delay(PAUSA);
  for (i = 0; i < 255  ; i++)
  {
    Motores.Move(i, -i);
    delay(FADE);
  }
  delay(PAUSA);
  for (i = 255; i > 0  ; i--)
  {
    Motores.Move(i, -i);
    delay(FADE);
  }
  Motores.Stop();
  Flash();
  delay(PAUSA);
  for (i = 0; i > -255  ; i--)
  {
    Motores.Move(i, -i);
    delay(FADE);
  }
  delay(PAUSA);
  for (i = -255; i < 0  ; i++)
  {
    Motores.Move(i, -i);
    delay(FADE);
  }
  Motores.Stop();
  Flash();
  delay(PAUSA);
}

void Flash()
{
  digitalWrite(LED, HIGH);
  delay(25);
  digitalWrite(LED, LOW);
  delay(50);
}
