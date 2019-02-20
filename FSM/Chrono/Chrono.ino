#include <FSM.h>
#include "myStates.h"
#include <OrangutanLCD.h>
#include <OrangutanMotors.h>

#define delayShowData  3000

//VARIABLES
OrangutanLCD Lcd;
OrangutanMotors Motors;

unsigned char myEvent;
char myByteRec;
unsigned long my0to100;
unsigned long t0;
unsigned long t_prev;
float Speed;
char bUpdateLCD;

void setup()
{
  Motors.setSpeeds(0, 0);
  Lcd.clear();                  // clear the LCD
  Lcd.print("Hello");
  FSM.begin(FSM_NextState, nStateMachine, FSM_State, nStateFcn, STATE1);
}

void loop()
{
  ReadEvents();
  FSM.Update();
}


void ReadEvents(void)
{
  //LCD.setCursor(0, 1);
  //LCD.print("Speed= ");
  //LCD.print((int)Speed);
  //
  if (Speed <= 0) {
    FSM.AddEvent(EV_Stop);
  } else if (Speed >= 100) {
    FSM.AddEvent(EV_100);
  } else if ( (Speed > 0) && (Speed < 100) ) {
    FSM.AddEvent(EV_Start);
    bUpdateLCD = 1;
  }
}

void func1(void)
{
  Lcd.clear();                  // clear the LCD
  Lcd.print("Hello");
}

void func2(void)
{
  t0 = millis();
  //LCD.setCursor(0, 2);
  //LCD.print("State 2");
  FSM.AddEvent(0);
}

void func3(void)
{
  //LCD.setCursor(0, 2);
  //LCD.print("State 3");
}

void func4(void)
{
  my0to100 = millis() - t0;
  t_prev = millis();
  //LCD.setCursor(0, 2);
  //LCD.print("State 4");

  //LCD.setCursor(0, 3);
  //LCD.print((float)my0to100 / (float)1000.0);
  //LCD.print(" s");

  while (millis() - t_prev <= delayShowData);
  FSM.AddEvent(EV_Wait);
}
