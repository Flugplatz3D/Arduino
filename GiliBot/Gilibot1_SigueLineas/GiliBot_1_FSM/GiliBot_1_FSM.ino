#include "Motors293.h"
#include <Adafruit_NeoPixel.h>
#include <FiniteStateMachine.h>
//http://playground.arduino.cc/Code/FiniteStateMachine

#define PIN  6
#define NUMPIXELS  3

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int sensorPinR = A0;
int sensorPinL = A1;
int sensorValueR = 0;
int sensorValueL = 0;
int i = 0, f = 0;

Motors293 Motores;

State noop = State(noopUpdate);  //no operation
State avanzar = State(avanzarEnter, avanzarUpdate, NULL);
State frenar = State(frenarEnter, frenarUpdate, NULL);
State parar = State(pararEnter, pararUpdate, NULL);
State derecha = State(derechaEnter, derechaUpdate, NULL);
State izquierda = State(izquierdaEnter, izquierdaUpdate, NULL);

unsigned long parcial = 0;

FSM stateMachine = FSM(noop); //initialize state machine, start in state: noop

void setup() {
  Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.
  for (i = 0; i < 5  ; i++)
  {
    pixels.setPixelColor(0, pixels.Color(0, 0, 80));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 80));
    pixels.show();
    delay(250);
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    pixels.show();
    delay(250);
  }
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.setPixelColor(1, pixels.Color(0, 0, 0));
  pixels.setPixelColor(2, pixels.Color(0, 0, 0));
  pixels.show();
  delay(1000);
  Motores.Stop();
  stateMachine.transitionTo(avanzar);
}

void loop() {
  stateMachine.update();
}

//[noop state:update] the state machine is in a state that does nothing
void noopUpdate() {
}
void avanzarEnter() {
  Motores.Move(100, 100);
  pixels.setPixelColor(0, pixels.Color(0, 15, 0));
  pixels.setPixelColor(1, pixels.Color(0, 0, 0));
  pixels.setPixelColor(2, pixels.Color(0, 15, 0));
  pixels.show();
  f = 0;
}
void avanzarUpdate() {
  sensorValueR = analogRead(sensorPinR);
  sensorValueL = analogRead(sensorPinL);
  if (sensorValueR >= 50 && sensorValueL >= 50)
  {
    stateMachine.transitionTo(frenar);
  }
  if (sensorValueR >= 50 && sensorValueL <= 50)
  {
    stateMachine.transitionTo(derecha);
  }
  if (sensorValueR <= 50 && sensorValueL >= 50)
  {
    stateMachine.transitionTo(izquierda);
  }
}
void pararEnter() {
  Motores.Stop();
  pixels.setPixelColor(0, pixels.Color(15, 0, 0));
  pixels.setPixelColor(1, pixels.Color(0, 0, 0));
  pixels.setPixelColor(2, pixels.Color(15, 0, 0));
  pixels.show();
}
void pararUpdate() {
  sensorValueR = analogRead(sensorPinR);
  sensorValueL = analogRead(sensorPinL);
  if (sensorValueR <= 50 && sensorValueL <= 50)
  {
    stateMachine.transitionTo(avanzar);
  }
}
void frenarEnter() {
  Motores.Move(-100, -100);
}
void frenarUpdate() {
  f++;
  if (f > 3000)
  {
    stateMachine.transitionTo(parar);
  }
}
void derechaEnter() {
  Motores.Move(-75, 125);
}
void derechaUpdate() {
  sensorValueR = analogRead(sensorPinR);
  sensorValueL = analogRead(sensorPinL);
  if (sensorValueR <= 50 && sensorValueL <= 50)
  {
    stateMachine.transitionTo(avanzar);
  }
}
void izquierdaEnter() {
  Motores.Move(125, -75);
}
void izquierdaUpdate() {
  sensorValueR = analogRead(sensorPinR);
  sensorValueL = analogRead(sensorPinL);
  if (sensorValueR <= 50 && sensorValueL <= 50)
  {
    stateMachine.transitionTo(avanzar);
  }
}
