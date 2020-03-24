#include <FiniteStateMachine.h> //http://playground.arduino.cc/Code/FiniteStateMachine
#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
#include "SensoresIR.h"
#include "Motors293.h"

int i = 0;
#define ledPin 13

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C
SSD1306AsciiWire oled;

SensoresIR sensores;
int vSensorLeft;
int vSensorFront;
int vSensorRight;
int vWalls;
#define LFR 1111
#define LNR 1101
#define NFR 1011
#define LFN 1110
#define LNN 1100
#define NFN 1010
#define NNR 1001
#define NNN 1000

Motors293 Motores;

State noop = State(noopUpdate);
State Start = State(StartEnter, StartUpdate, NULL);
State Stop = State(StopEnter, StopUpdate, NULL);
State ScanF = State(ScanFEnter, ScanFUpdate, NULL);
State ScanR = State(ScanREnter, ScanRUpdate, NULL);
State ScanL = State(ScanLEnter, ScanLUpdate, NULL);

FSM stateMachine = FSM(noop); //initialize state machine, start in state: noop

void setup() {
  Motores.Stop();
  pinMode(ledPin, OUTPUT);
  Wire.begin();
  Wire.setClock(400000L);
  oled.begin(&Adafruit128x32, I2C_ADDRESS);
  oled.setFont(System5x7);
  oled.clear();
  oled.set2X();
  oled.println("GiliBot4");
  oled.set1X();
  oled.println("");
  oled.println("MVC-202003");
  digitalWrite(ledPin, HIGH);
  delay(3000);
  oled.clear();
  digitalWrite(ledPin, LOW);
}
void loop() {
  stateMachine.update();
}
//[noop state:update] the state machine is in a state that does nothing
void noopUpdate() {
  vWalls = sensores.ReadFEma();
  oled.set1X();
  oled.setRow(0);
  oled.setCol(0);
  oled.print(__FUNCTION__);
  oled.set2X();
  oled.setRow(2);
  oled.setCol(0);
  oled.print("    ");
  oled.setRow(2);
  oled.setCol(0);
  oled.print(vWalls);
  if (vWalls == 0)
  {
    //Wait for sensors stabilization/Maybe launch control too
    stateMachine.transitionTo(Start);
  }
}
void StartEnter() {
  oled.clear();
  oled.set1X();
  oled.setRow(0);
  oled.setCol(0);
  oled.print(__FUNCTION__);
  digitalWrite(ledPin, HIGH);
  delay(5000);
  digitalWrite(ledPin, LOW);
  for (i = 0; i < 15  ; i++)
  {
    Flash();
  }
  delay(1000);
}
void StartUpdate() {
  stateMachine.transitionTo(Stop);
}
void StopEnter() {
  oled.clear();
  oled.set1X();
  oled.setRow(0);
  oled.setCol(0);
  oled.print(__FUNCTION__);
  Motores.Stop();
  digitalWrite(ledPin, HIGH);
  delay(2000);
  digitalWrite(ledPin, LOW);
}
void StopUpdate() {
  vWalls = sensores.ReadWalls();
  oled.clear();
  oled.set1X();
  oled.setRow(0);
  oled.setCol(0);
  oled.print(__FUNCTION__);
  oled.set2X();
  oled.setRow(2);
  oled.setCol(0);
  oled.print("    ");
  oled.setRow(2);
  oled.setCol(0);
  oled.print(vWalls);
  switch (vWalls) {
    case LNR:
    case LNN:
    case NNR:
      {
        stateMachine.transitionTo(ScanF);
        break;
      }

  }
}
void ScanFEnter() {
  Motores.Move(50, 50);
  oled.clear();
}
void ScanFUpdate() {
  //  oled.clear();
  DisplayABS_1();
  //  vWalls = sensores.ReadFEma();
  //  oled.set1X();
  //  oled.setRow(0);
  //  oled.setCol(0);
  //  oled.print(__FUNCTION__);
  //  oled.set2X();
  //  oled.setRow(2);
  //  oled.setCol(0);
  //  oled.print("    ");
  //  oled.setRow(2);
  //  oled.setCol(0);
  //  oled.print(vWalls);
  //  if (vWalls == 1)
  if (sensores.ReadFEma() == 1)
  {
    stateMachine.transitionTo(ScanR);
  }
}
void ScanREnter() {
  oled.clear();
  oled.set1X();
  oled.setRow(0);
  oled.setCol(0);
  oled.print(__FUNCTION__);
  Motores.Stop();
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  Motores.Move(75, -75);
  delay(850);
  Motores.Stop();
}
void ScanRUpdate() {
  oled.clear();
  oled.set1X();
  oled.setRow(0);
  oled.setCol(0);
  oled.print("    ");
  oled.setRow(0);
  oled.setCol(0);
  oled.print(sensores.ReadLAbs());
  delay(100);
}
void ScanLEnter() {
}
void ScanLUpdate() {
}
void Flash() {
  digitalWrite(ledPin, HIGH);
  delay(25);
  digitalWrite(ledPin, LOW);
  delay(100);
}
void DisplayABS_1() {
  sensores.ReadABS(vSensorLeft, vSensorFront, vSensorRight);
  oled.set1X();
  oled.setRow(0);
  oled.setCol(0);
  oled.print("    ");
  oled.setRow(0);
  oled.setCol(0);
  oled.print(vSensorLeft);
  oled.setRow(0);
  oled.setCol(32);
  oled.print("    ");
  oled.setRow(0);
  oled.setCol(32);
  oled.print(vSensorFront);
  oled.setRow(0);
  oled.setCol(64);
  oled.print("    ");
  oled.setRow(0);
  oled.setCol(64);
  oled.print(vSensorRight);
}
