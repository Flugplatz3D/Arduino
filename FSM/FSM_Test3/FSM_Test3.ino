#include <FSM.h>
#include "myStates.h"
#define ECHOPIN 2                            // Pin to receive echo pulse
#define TRIGPIN 3                            // Pin to send trigger pulse

unsigned char myEvent;
unsigned int An0;
unsigned int Radar;


void setup() {
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
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
  if (Radar > 10)
  {
    myEvent = EV_Front;
  }
  else if (Radar < 8)
  {
    myEvent = EV_Rear;
  }
  else
  {
    myEvent = EV_Stop;
  }
  FSM.AddEvent(myEvent);
}

//Funciones correspondientes a los ESTADOS
void FuncST1(void)
{
  Radar = LeeSensorUS();
}

void FuncST2(void)
{
  Serial.print(Radar, DEC);
  Serial.println(" Parar");
  delay(100);
  FSM.AddEvent(EV_Reset);
}

void FuncST3(void)
{
  Serial.print(Radar, DEC);
  Serial.println(" Retroceder");
  delay(100);
  FSM.AddEvent(EV_Reset);
}

void FuncST4(void)
{
  Serial.print(Radar, DEC);
  Serial.println(" Avanzar");
  delay(100);
  FSM.AddEvent(EV_Reset);
}

int LeeSensorUS()
{
  digitalWrite(TRIGPIN, LOW);                   // Set the trigger pin to low for 2uS
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  // Send a 10uS high to trigger ranging
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   // Send pin low again
  int distance = pulseIn(ECHOPIN, HIGH);        // Read in times pulse
  distance = distance / 58;                     // Calculate distance from time of pulse
  return distance;
}
