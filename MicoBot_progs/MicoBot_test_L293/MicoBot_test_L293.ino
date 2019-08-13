#include "Motors293.h"

#define FADE 15
#define PAUSA 750

int i = 0;

Motors293 Motores;

void setup() {
  Motores.Stop();
  delay(5000);
}

void loop() {
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
  delay(PAUSA);
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
  delay(PAUSA);
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
  delay(PAUSA);
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
  delay(PAUSA);
    for (i = 0; i < 255  ; i++)
  {
    Motores.Move(i, i);
    delay(FADE);
  }
  delay(PAUSA);
  for (i = 255; i > 0  ; i--)
  {
    Motores.Move(i, i);
    delay(FADE);
  }
  Motores.Stop();
  delay(PAUSA);
  for (i = 0; i > -255  ; i--)
  {
    Motores.Move(i, i);
    delay(FADE);
  }
  delay(PAUSA);
  for (i = -255; i < 0  ; i++)
  {
    Motores.Move(i, i);
    delay(FADE);
  }
  Motores.Stop();
  delay(PAUSA);
}
