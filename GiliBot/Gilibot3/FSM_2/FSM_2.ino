#include <Wire.h>
#include <SSD1306Ascii.h>
#include <SSD1306AsciiWire.h>
#include <MedianFilter.h>
#include "FSM.h"
#include "myStates.h"
#include "Motors.h"

SSD1306AsciiWire oled;
Motors Motores;

#define Ventana 100
#define FiltroIni 999
#define VelocidadChocar 150
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

unsigned long time_start;
unsigned long time_actual;

unsigned char myEvent;
unsigned int An0;

void setup() {
  Serial.begin(9600);
  Motores.Stop();
  Serial.println("");
  //  Serial.flush();
  //  Wire.begin();
  //  Wire.setClock(400000L);
  //  oled.begin(&Adafruit128x64, 0x3C);
  //  oled.setFont(lcd5x7);
  //  oled.clear();
  FSM.begin(FSM_NextState, nStateMachine, FSM_State, nStateFcn, INICIO);
}

void loop()
{
  ReadEvents();
  FSM.Update();
}

void ReadEvents()
{
  myEvent = 0;
  if (time_actual < 30000)
    //if (sensorFrontMF < ParedFront)
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
void FuncInicio(void)
{
  Serial.println("Estado INICIO");
  time_start = millis();
  delay(3000);
  //  oled.setRow(0);
  //  oled.setCol(24);
  //  oled.set2X();
  //  oled.print("GiliBot");
  //  oled.set1X();
  //  oled.setRow(3);
  //  oled.setCol(36);
  //  oled.print("Vers.LN0F1");

  //  oled.clear();

  FSM.AddEvent(EV_Inicio);
}

void FuncChocar(void)
{
  Serial.print("Estado CHOCAR  -> ");
  time_actual = millis() - time_start;
  Serial.println(time_actual);
  delay(250);
  //  sensorFrontMF = ReadSensor(sensorFront, medianFilterFront, sensorPinFront);
  //  Motores.Move(VelocidadGirar, VelocidadGirar);
}

void FuncParar(void)
{
  Serial.println("Estado PARAR");
  FSM.AddEvent(EV_Stop);
  //  Motores.Stop();
}

void FuncDerecha(void)
{

}

void FuncIzquierda(void)
{

}

int ReadSensor(int &sensor, MedianFilter &Filtro, int pin)
{
  sensor = analogRead(pin);
  Filtro.in(sensor);
  return Filtro.out();
}
