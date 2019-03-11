#include <Wire.h>
#include <SSD1306Ascii.h>
#include <SSD1306AsciiWire.h>
#include <MedianFilter.h>
#include <Fsm.h>
#include "Motors.h"

Motors Motores;
SSD1306AsciiWire oled;

#define Ventana 50
#define ValorInicio 1000
#define VelocidadChocar 150
#define VelocidadGirar 75

MedianFilter medianFilterLeft(Ventana, ValorInicio);
MedianFilter medianFilterFront(Ventana, ValorInicio);
MedianFilter medianFilterRight(Ventana, ValorInicio);

unsigned long time_start = 0;
unsigned long time_actual = 0;

// Used pins
#define LED_PIN LED_BUILTIN

// State machine variables
#define FLIP_LIGHT_SWITCH 1
#define ARRANCAR 2
#define RESET 3

State state_light_on(on_light_on_enter, NULL, &on_light_on_exit);
State state_light_off(on_light_off_enter, NULL, &on_light_off_exit);
State state_inicio(on_inicio_in, NULL, &on_inicio_out);
State state_chocar(on_chocar_in, NULL, &on_chocar_out);
Fsm fsm(&state_inicio);

// Transition callback functions
void on_light_on_enter() {
  Serial.println(__FUNCTION__);
  digitalWrite(LED_PIN, HIGH);
}

void on_light_on_exit() {
  Serial.println(__FUNCTION__);
  digitalWrite(LED_PIN, LOW);
}

void on_light_off_enter() {
  Serial.println(__FUNCTION__);
}

void on_light_off_exit() {
  Serial.println(__FUNCTION__);
}

void on_trans_light_on_light_off() {
  Serial.println(__FUNCTION__);
  Serial.println("  Transitioning from LIGHT_ON to LIGHT_OFF");
}

void on_trans_light_off_light_on() {
  Serial.println(__FUNCTION__);
  Serial.println("  Transitioning from LIGHT_OFF to LIGHT_ON");
}

void on_inicio_in() {
  Serial.println(__FUNCTION__);
  delay(3000);
  time_start = millis();
  fsm.trigger(ARRANCAR);
}

void on_inicio_out() {
  Serial.println(__FUNCTION__);
  delay(3000);
}

void on_chocar_in() {
  Serial.println(__FUNCTION__);
  delay(3000);
}

void on_chocar_out() {
  Serial.println(__FUNCTION__);
  delay(3000);
}

// standard arduino functions
void setup() {
  Serial.begin(9600);
  Serial.println("\nFSM Light Switch\n");
  pinMode(LED_PIN, OUTPUT);

  //  fsm.add_transition(&state_light_on, &state_light_off,
  //                     FLIP_LIGHT_SWITCH,
  //                     &on_trans_light_on_light_off);
  //  fsm.add_transition(&state_light_off, &state_light_on,
  //                     FLIP_LIGHT_SWITCH,
  //                     &on_trans_light_off_light_on);
  fsm.add_transition(&state_inicio, &state_chocar, ARRANCAR, NULL);
  fsm.add_transition(&state_chocar, &state_inicio, RESET, NULL);
  fsm.run_machine();
}

void loop() {
  time_actual = millis() - time_start;
  Serial.print("-- loop -- ");
  Serial.println(time_actual);
  if (time_actual > 20000)
  {
    fsm.trigger(RESET);
  }
  else if (time_actual > 40000)
  {
    fsm.trigger(ARRANCAR);
  }
}
