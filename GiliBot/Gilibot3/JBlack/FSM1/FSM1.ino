#include "Fsm.h"

#define INICIO 0
#define AVANZA_CHOCAR 1
#define ESPERAR 2
#define DERECHA 3

unsigned long time_start = 0;
unsigned long time_actual = 0;
unsigned long time_esperar = 0;
unsigned long time_parcial = 0;

unsigned char miEvento = INICIO;

State state_inicio(inicio_entrada, NULL, &inicio_salida);
State state_chocar(chocar_entrada, NULL, &chocar_salida);
State state_esperar(esperar_entrada, NULL, &esperar_salida);

Fsm fsm(&state_inicio);

void setup() {
  Serial.begin(9600);
  fsm.add_transition(&state_inicio, &state_chocar, AVANZA_CHOCAR, NULL);
  fsm.add_transition(&state_chocar, &state_esperar, ESPERAR, &chocar_a_esperar);
  fsm.add_transition(&state_esperar, &state_chocar, AVANZA_CHOCAR, NULL);
}

void loop() {
  fsm.run_machine();
  time_actual = millis() - time_start;
  Serial.print(miEvento);
  Serial.print(" - ");
  Serial.println(time_actual);
  delay(100);
  switch (miEvento)
  {
    case INICIO:
      {
        miEvento = AVANZA_CHOCAR;
        fsm.trigger(AVANZA_CHOCAR);
      }
    case AVANZA_CHOCAR:
      {
        miEvento = ESPERAR;
        fsm.trigger(AVANZA_CHOCAR);
        break;
      }
    case ESPERAR:
      {
        if (time_actual > 20000)
        {
          miEvento = AVANZA_CHOCAR;
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

void inicio_salida()
{
  //Serial.println("Salida INICIO");
  //EsperaTecla();
}

void chocar_entrada()
{
  Serial.println("Entrada CHOCAR");
  //EsperaTecla();
  time_start = millis();
}

void chocar_salida()
{
  Serial.println("Salida CHOCAR");
  //EsperaTecla();
}

//void inicio_a_chocar()
//{
//  Serial.println("inicio_a_chocar");
//  EsperaTecla();
//}

void esperar_entrada()
{
  Serial.println("Entrada ESPERAR");
  //EsperaTecla();
  delay(3000);
  time_start = millis();
}

void esperar_salida()
{
  Serial.println("Salida ESPERAR");
  //EsperaTecla();
}

void chocar_a_esperar()
{
  //Serial.println("chocar_a_esperar");
  //EsperaTecla();
}
