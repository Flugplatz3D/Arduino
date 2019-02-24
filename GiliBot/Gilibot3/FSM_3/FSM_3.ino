#include <Wire.h>
#include <SSD1306Ascii.h>
#include <SSD1306AsciiWire.h>
#include <MedianFilter.h>
#include "FSM.h"
#include "myStates.h"
#include "Motors.h"

SSD1306AsciiWire oled;
Motors Motores;

#define Ventana 50
#define FiltroIni 999
#define VelocidadChocar 100
#define VelocidadGirar 75
#define ParedLeft 850
#define ParedFront 800
#define ParedRight 850

MedianFilter medianFilterLeft(Ventana, FiltroIni);
MedianFilter medianFilterFront(Ventana, FiltroIni);
MedianFilter medianFilterRight(Ventana, FiltroIni);

int sensorPinRight = A0;
int sensorPinFront = A1;
int sensorPinLeft = A2;

int sensorLeft, sensorFront, sensorRight;
int sensorLeftMF, sensorFrontMF, sensorRightMF;
int diferencial;

unsigned char myEvent;

void setup() {
  Serial.begin(9600);
  Motores.Stop();
  Serial.println("\nSetup Arduino");
  Wire.begin();
  Wire.setClock(400000L);
  oled.begin(&Adafruit128x64, 0x3C);
  oled.setFont(lcd5x7);
  oled.clear();
  FSM.begin(FSM_NextState, nStateMachine, FSM_State, nStateFcn, INICIO);
}

void loop()
{
  ReadEvents();
  FSM.Update();
}

void ReadEvents()
{
  sensorFrontMF = ReadSensor(sensorFront, medianFilterFront, sensorPinFront);
  myEvent = 0;
  if (sensorFrontMF >  ParedFront)
  {
    myEvent = EV_Front;
  }
  else
  {
    myEvent = EV_Stop;
  }
  FSM.AddEvent(myEvent);
}

//Funciones correspondientes a los ESTADOS
void FuncInicio()
{
  oled.setRow(0);
  oled.setCol(24);
  oled.set2X();
  oled.print("GiliBot");
  oled.set1X();
  oled.setRow(3);
  oled.setCol(36);
  oled.print("Vers.LN0F1");
  delay(3000);
  oled.clear();
  FSM.AddEvent(EV_Inicio);
}

void FuncChocar()
{
  oled.setRow(0);
  oled.setCol(0);
  oled.print(sensorFrontMF);
  oled.print("  ");
  Motores.Move(VelocidadChocar, VelocidadChocar);
}

void FuncParar()
{
  oled.setRow(0);
  oled.setCol(0);
  oled.print(sensorFrontMF);
  oled.print("  ");
  Motores.Stop();
//  FSM.AddEvent(EV_Stop);
}

void FuncDerecha()
{

}

void FuncIzquierda()
{

}

int ReadSensor(int &sensor, MedianFilter &Filtro, int pin)
{
  sensor = analogRead(pin);
  Filtro.in(sensor);
  return Filtro.out();
}
