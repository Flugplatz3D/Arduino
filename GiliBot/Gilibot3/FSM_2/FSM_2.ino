#include "FSM.h"
#include "myStates.h"

unsigned long time_start;
unsigned long time_actual;
unsigned long time_parar;
unsigned long time_parcial = 0;

unsigned char myEvent = EV_Inicio;
int tecla = 0;

void setup() {
  Serial.begin(9600);
  FSM.begin(FSM_NextState, nStateMachine, FSM_State, nStateFcn, INICIO);
  time_start = millis();
}

void loop()
{
  ReadEvents();
  FSM.Update();
}

void EsperaTecla()
{
  while (!Serial.available()) {}
  tecla = Serial.read();
}

void ReadEvents()
{
  switch (FSM.State())
  {
    case INICIO:
      {
          Serial.println("ReadEvents INICIO");
        FSM.AddEvent(EV_Inicio);
        break;
      }
    case IZQUIERDA:
    {
        Serial.println("ReadEvents IZQUIERDA");
        FSM.AddEvent(EV_Front);
        break;
      }
    case CHOCAR:
      {
          Serial.print("ReadEvents CHOCAR ->");
          Serial.println(millis());
        FSM.AddEvent(EV_Right);
        break;
      }
    default:
      {
      }
  }
//  Serial.println("ReadEvents");
//  Serial.println(FSM.State());
}

void FuncInicio()
{
  Serial.println("INICIO");
  EsperaTecla();
  FSM.AddEvent(EV_Front);
}

void FuncChocar()
{
//  Serial.print("CHOCAR -> ");
//  Serial.println(millis());
//  EsperaTecla();
  //FSM.AddEvent(EV_Right);
}

void FuncParar()
{
  Serial.print("PARAR -> ");
  Serial.println(time_parar);
  time_parcial = millis();
}

void FuncDerecha()
{
  Serial.println("DERECHA");
  EsperaTecla();
  FSM.AddEvent(EV_Left);
}

void FuncIzquierda()
{
  Serial.println("IZQUIERDA");
  EsperaTecla();
  //FSM.AddEvent(EV_Front);
}

void FuncEsperar()
{
  Serial.println("ESPERAR");
  EsperaTecla();
}
