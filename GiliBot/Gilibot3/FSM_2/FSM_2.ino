#include "FSM.h"
#include "myStates.h"

unsigned long time_start;
unsigned long time_actual;
unsigned long time_parar;
unsigned long time_parcial = 0;

unsigned char myEvent;
int tecla = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("\nSetup");
  EsperaTecla();
  FSM.begin(FSM_NextState, nStateMachine, FSM_State, nStateFcn, INICIO);
}

void loop()
{
  ReadEvents();
  FSM.Update();
}

void ReadEvents()
{
  time_parar = millis() - time_parcial;
  //Serial.println("ReadEvents");
  //EsperaTecla();
  myEvent = 0;
  if (time_actual > 5000)
  {
    myEvent = EV_Stop;
  }
  else
  {
    myEvent = EV_Front;
  }
  FSM.AddEvent(myEvent);
}

void FuncInicio()
{
  Serial.println("INICIO");
  EsperaTecla();
  time_start = millis();
  FSM.AddEvent(EV_Inicio);
}

void FuncChocar()
{
  Serial.print("CHOCAR -> ");
  time_actual = millis() - time_start;
  Serial.println(time_actual);
  //EsperaTecla();
}

void FuncParar()
{
  Serial.println("PARAR");
  EsperaTecla();
  time_parcial = millis();
}

void FuncDerecha()
{
  Serial.print("Derecha -> ");
  Serial.println(time_parar);
  if (time_parar > 5000)
  {
      FSM.AddEvent(EV_Front);
  }
  //delay(300);
}

void FuncIzquierda()
{
  Serial.print("Izquierda -> ");
  Serial.println(time_parar);
}

void EsperaTecla()
{
  while (!Serial.available()) {}
  tecla = Serial.read();
}
