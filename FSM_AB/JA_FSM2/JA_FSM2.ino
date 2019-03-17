#include <FiniteStateMachine.h> //http://playground.arduino.cc/Code/FiniteStateMachine
#include <Wire.h>
#include <SSD1306Ascii.h>
#include <SSD1306AsciiWire.h>
#include <MedianFilter.h>
#include "Motors.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

SSD1306AsciiWire oled;
Motors Motores;

#define Ventana 50
#define FiltroIni 999
#define VelocidadChocar 75
#define VelocidadGirar 50
#define ParedLeft 850
#define ParedFront 750
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

int i = 0;

State noop = State(noopUpdate);  //no operation
State chocar = State(chocarEnter, chocarUpdate, NULL);
State parar = State(pararEnter, pararUpdate, NULL);

FSM stateMachine = FSM(noop); //initialize state machine, start in state: noop

void setup() {
  Serial.begin(9600);
  Motores.Stop();
  Wire.begin();
  Wire.setClock(400000L);
  oled.begin(&Adafruit128x64, 0x3C);
  oled.setFont(lcd5x7);
  oled.clear();
  oled.setRow(0);
  oled.setCol(24);
  oled.set2X();
  oled.print("GiliBot");
  oled.set1X();
  oled.setRow(3);
  oled.setCol(28);
  oled.print("Vers.FSM_AB1");
  Serial.println("\nFSM Alexander Brevig\n");
  delay(2000);
  oled.clear();
  stateMachine.transitionTo(chocar);
}

void loop() {
  //do not remove the stateMachine.update() call, it is what makes this program 'tick'
  stateMachine.update();
}

//[noop state:update] the state machine is in a state that does nothing
void noopUpdate() {
}

void chocarEnter() {
  Serial.println(__FUNCTION__);
  Motores.Move(VelocidadChocar, VelocidadChocar);
}

void chocarUpdate() {
  sensorLeftMF = ReadSensor(sensorLeft, medianFilterLeft, sensorPinLeft);
  sensorFrontMF = ReadSensor(sensorFront, medianFilterFront, sensorPinFront);
  sensorRightMF = ReadSensor(sensorRight, medianFilterRight, sensorPinRight);
  DatosOled();
  if (sensorFrontMF < ParedFront)
  {
    stateMachine.transitionTo(parar);
  }
}

void pararEnter() {
  Serial.println(__FUNCTION__);
  Motores.Stop();
}

void pararUpdate() {
  sensorLeftMF = ReadSensor(sensorLeft, medianFilterLeft, sensorPinLeft);
  sensorFrontMF = ReadSensor(sensorFront, medianFilterFront, sensorPinFront);
  sensorRightMF = ReadSensor(sensorRight, medianFilterRight, sensorPinRight);
  DatosOled();
}

int ReadSensor(int &sensor, MedianFilter &Filtro, int pin)
{
  sensor = analogRead(pin);
  Filtro.in(sensor);
  return Filtro.out();
}

void DatosOled()
{
  oled.setRow(0);
  oled.setCol(0);
  oled.print(sensorLeftMF);
  oled.print("  ");
  oled.print(sensorFrontMF);
  oled.print("  ");
  oled.print(sensorRightMF);
  oled.print("  ");
  oled.setRow(2);
  oled.setCol(0);
  diferencial = (sensorLeftMF - sensorRightMF) + 105;
  oled.print(diferencial);
  oled.print("  ");
}
