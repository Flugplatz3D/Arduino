#include "Fsm.h"

#define INICIO 0
#define ESPERAR 1
#define CHOCAR 2
#define DERECHA 3

unsigned long time_start = 0;
unsigned long time_actual = 0;
unsigned char miEvento = INICIO;

State state_inicio(inicio_entrada, NULL, NULL);
State state_chocar(chocar_entrada, NULL, &chocar_salida);
State state_esperar(esperar_entrada, NULL, &esperar_salida);

Fsm fsm(&state_inicio);

void setup() {
  Serial.begin(9600);
  fsm.add_transition(&state_inicio, &state_chocar, CHOCAR, NULL);
  fsm.add_transition(&state_chocar, &state_esperar, ESPERAR, NULL);
  fsm.add_transition(&state_esperar, &state_chocar, CHOCAR, NULL);
}

void loop() {
  fsm.run_machine();
  time_actual = millis() - time_start;
  Serial.print(miEvento);
  Serial.print(" - ");
  Serial.println(time_actual);
  delay(20);
  switch (miEvento)
  {
    case INICIO:
      {
        miEvento = CHOCAR;
        fsm.trigger(CHOCAR);
      }
    case CHOCAR:
      {
        miEvento = ESPERAR;
        fsm.trigger(CHOCAR);
        break;
      }
    case ESPERAR:
      {
        if (time_actual > 10000)
        {
          miEvento = CHOCAR;
          fsm.trigger(ESPERAR);
        }
        break;
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
  delay(2000);
  time_start = millis();
}

void chocar_salida()
{
  Serial.println("Salida CHOCAR");
}

void esperar_entrada()
{
  Serial.println("Entrada ESPERAR");
  delay(5000);
  time_start = millis();
}

void esperar_salida()
{
  Serial.println("Salida ESPERAR");
}
