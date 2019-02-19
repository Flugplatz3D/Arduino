#include <FSM.h>
#include "myStates.h"

unsigned char myEvent;
unsigned int An0;

void setup() {
  Serial.begin(9600);
  Serial.println("Inicio");
  delay(1500);
  FSM.begin(FSM_NextState, nStateMachine, FSM_State, nStateFcn, STATE1);
}

void loop()
{
  ReadEvents();
  FSM.Update();
}

void ReadEvents(void)
{
  myEvent = 0;
  if (An0 > 400)
  {
    myEvent = EV_Rear;
  }
  else if (An0 > 300)
  {
    myEvent = EV_Stop;
  }
  else
  {
    myEvent = EV_Front;
  }
  FSM.AddEvent(myEvent);
}

//Funciones correspondientes a los ESTADOS
void FuncST1(void)
{
  An0 = LeeSensorIR();
}

void FuncST2(void)
{
  Serial.print(An0, DEC);
  Serial.println(" Parar");
  delay(100);
  FSM.AddEvent(EV_Reset);
}

void FuncST3(void)
{
  Serial.print(An0, DEC);
  Serial.println(" Retroceder");
  delay(100);
  FSM.AddEvent(EV_Reset);
}

void FuncST4(void)
{
  Serial.print(An0, DEC);
  Serial.println(" Avanzar");
  delay(100);
  FSM.AddEvent(EV_Reset);
}

int LeeSensorIR()
{
  byte i = 0;
  unsigned long Suma = 0;

  for (i = 0; i < 100; i++)
  {
    Suma = Suma + analogRead(0);
  }
  Suma = Suma / 100;
  return Suma;
}
