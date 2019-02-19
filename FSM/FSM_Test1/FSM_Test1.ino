#include <FSM.h>
#include "myStates.h"

unsigned char myEvent;
unsigned long t0 = 0, tt = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
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
  if (millis() - t0 > 500)
  {
    myEvent = EV_Cambia;
  }
  FSM.AddEvent(myEvent);
}

//Funciones correspondientes a los ESTADOS
void func2(void)
{
  t0 = millis();
  Serial.println(tt, DEC);
  digitalWrite(13, bitRead(tt, 0));
  tt++;
  FSM.AddEvent(EV_Reset);
}
