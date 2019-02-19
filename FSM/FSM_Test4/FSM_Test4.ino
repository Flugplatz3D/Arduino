#include <FSM.h>
#include "myStates.h"
#include <OrangutanMotors.h>
#include <OrangutanAnalog.h>
#include <OrangutanLEDs.h>
#include <OrangutanLCD.h>

#define ECHOPIN 2    // Pin to receive echo pulse
#define TRIGPIN 3    // Pin to send trigger pulse
#define STOP 0
#define FWD_DER 128
#define FWD_IZQ 128
#define REV_DER -128
#define REV_IZQ -128

unsigned char myEvent;
unsigned int An0;
unsigned int Radar;
OrangutanMotors motors;
OrangutanAnalog analog;
OrangutanLEDs leds;
OrangutanLCD lcd;
int pot;

void setup() {
  Serial.begin(9600);
  motors.setSpeeds(STOP, STOP);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  Serial.println("Inicio");
  lcd.clear();
  lcd.print("Inicio");
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
  motors.setSpeeds(STOP, STOP);
  leds.red(LOW);
  leds.green(LOW);
  Serial.print(Radar, DEC);
  Serial.println(" Parar");
  lcd.gotoXY(0, 0);               // LCD cursor to home position (upper-left)
  lcd.print(Radar);
  lcd.print("  ");
  lcd.gotoXY(0, 1);               // LCD cursor to start of the second line
  lcd.print("Parar");
  delay(100);
  FSM.AddEvent(EV_Reset);
}

void FuncST3(void)
{
  motors.setSpeeds(REV_DER, REV_IZQ);
  leds.red(HIGH);
  leds.green(LOW);
  Serial.print(Radar, DEC);
  Serial.println(" Retroceder");
  lcd.gotoXY(0, 0);               // LCD cursor to home position (upper-left)
  lcd.print(Radar);
  lcd.print("  ");
  lcd.gotoXY(0, 1);               // LCD cursor to start of the second line
  lcd.print("Retroceder");
  delay(100);
  FSM.AddEvent(EV_Reset);
}

void FuncST4(void)
{
  motors.setSpeeds(FWD_DER, FWD_IZQ);
  leds.red(LOW);
  leds.green(HIGH);
  Serial.print(Radar, DEC);
  Serial.println(" Avanzar");
  lcd.gotoXY(0, 0);               // LCD cursor to home position (upper-left)
  lcd.print(Radar);
  lcd.print("  ");
  lcd.gotoXY(0, 1);               // LCD cursor to start of the second line
  lcd.print("Avanzar");
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
