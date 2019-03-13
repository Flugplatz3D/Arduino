#include "Fsm.h"

#define INICIO 0
#define ESPERAR 1
#define CHOCAR 2
#define DERECHA 3

#define EV_INICIO 0
#define EV_ESPERAR 1
#define EV_CHOCAR 2
#define EV_DERECHA 3

unsigned long time_start = 0;
unsigned long time_actual = 0;
unsigned char EstadoControl = INICIO;

State state_inicio(inicio_entrada, NULL, NULL);
State state_chocar(chocar_entrada, NULL, &chocar_salida);
State state_esperar(esperar_entrada, NULL, &esperar_salida);
State state_derecha(derecha_entrada, NULL, &derecha_salida);

Fsm fsm(&state_inicio);

void setup() {
  Serial.begin(9600);
  fsm.add_transition(&state_inicio, &state_chocar, EV_CHOCAR, NULL);
  fsm.add_transition(&state_chocar, &state_esperar, EV_ESPERAR, NULL);
  fsm.add_transition(&state_esperar, &state_chocar, EV_CHOCAR, NULL);
  fsm.add_transition(&state_esperar, &state_derecha, EV_DERECHA, NULL);
  fsm.run_machine();
}

void loop() {
  time_actual = millis() - time_start;
  switch (EstadoControl)
  {
    case INICIO:
      {
        EstadoControl = CHOCAR;
        fsm.trigger(EV_CHOCAR);
      }
    case CHOCAR:
      {
        EstadoControl = ESPERAR;
        fsm.trigger(EV_CHOCAR);
        break;
      }
    case ESPERAR:
      {
        Serial.println(time_actual);
        delay(20);
        if (time_actual > 10000)
        {
          EstadoControl = CHOCAR;
          fsm.trigger(EV_ESPERAR);
        }
        break;
      }
    case DERECHA:
    {
    }
  }
}

void EsperaTecla()
{
  int tecla = 0;
  while (!Serial.available()) {}
  tecla = Serial.read();
}

void inicio_entrada()
{
  Serial.println("\nEntrada INICIO");
  EsperaTecla();
  time_start = millis();
}

void chocar_entrada()
{
  Serial.println("Entrada CHOCAR");
  delay(1000);
  time_start = millis();
}

void chocar_salida()
{
  Serial.println("Salida CHOCAR");
}

void esperar_entrada()
{
  Serial.println("Entrada ESPERAR");
  delay(2000);
  time_start = millis();
}

void esperar_salida()
{
  Serial.println("Salida ESPERAR");
}

void derecha_entrada()
{
  Serial.println("Entrada DERECHA");
}

void derecha_salida()
{
  Serial.println("Salida DERECHA");
}