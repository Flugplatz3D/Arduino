#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
#include "MedianFilterLib.h"

SSD1306AsciiWire oled;

#define Ventana 100
MedianFilter<int> medianFilterLeft(Ventana);
MedianFilter<int> medianFilterFront(Ventana);
MedianFilter<int> medianFilterRight(Ventana);

int sensorPinRight = A0;
int sensorPinFront = A1;
int sensorPinLeft = A2;
int sensorLeft, sensorFront, sensorRight;
int sensorLeftMF, sensorFrontMF, sensorRightMF;
int diferencial;

byte miEstado, miEvento;

void setup() {
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
  oled.setCol(38);
  oled.print("Vers.LN0g");
  delay(3000);
  oled.clear();
}

void LeerEventos() {
  miEvento = 0;
  //  if (Radar > 10)
  //  {
  //    miEvento = EV_Front;
  //  }
  //  else if (Radar < 8)
  //  {
  //    miEvento = EV_Rear;
  //  }
  //  else
  //  {
  //    miEvento = EV_Stop;
  //  }
};

void FSMEstados()
{
  //  switch (miEstado)
  //  {
  //    case ST_LEE_SENSOR:
  //      {
  //        switch (miEvento)
  //        {
  //          case EV_Stop:
  //            {
  //              miEstado = ST_LEE_SENSOR;
  //              break;
  //            }
  //          case EV_Rear:
  //            {
  //              miEstado = ESTADO3;
  //              break;
  //            }
  //          case EV_Front:
  //            {
  //              miEstado = ST_AVANZAR;
  //              break;
  //            }
  //        }
  //        break;
  //        FuncST1();
  //      }
  //    case ESTADO2:
  //      {
  //        switch (miEvento)
  //        {
  //          case EV_Stop:
  //            {} break;
  //          case EV_Reset:
  //            {} break;
  //        }
  //        break;
  //        FuncST2();
  //      }
  //    case ESTADO3:
  //      {
  //        switch (miEvento)
  //        {
  //          case EV_Reset:
  //            {} break;
  //        }
  //        break;
  //        FuncST3();
  //      }
  //    case ST_AVANZAR:
  //      {
  //        switch (miEvento)
  //        {
  //          case EV_Front:
  //            {
  //              miEstado = ST_LEE_SENSOR;
  //              break;
  //            }
  //          default:
  //            {}
  //        }
  //        break;
  //        FuncST4();
  //      }
  //  }
}

void FuncST1() {
  //  Radar = LeeSensorUS();
};

void FuncST2() {
  //  BorraP();
  //  digitalWrite(LED_Azul, LOW);
  //  digitalWrite(LED_Rojo, LOW);
  //  Cursor(0, 0);
  //  Serial.print(Radar, DEC);
  //  Serial.print("  ");
  //  Cursor(1, 0);
  //  Serial.print("Parar");
};

void FuncST3() {
  //  BorraP();
  //  digitalWrite(LED_Azul, HIGH);
  //  digitalWrite(LED_Rojo, LOW);
  //  Cursor(0, 0);
  //  Serial.print(Radar, DEC);
  //  Serial.print("  ");
  //  Cursor(1, 0);
  //  Serial.print("Retroceder");
};

void FuncST4() {
  //  BorraP();
  //  digitalWrite(LED_Azul, LOW);
  //  digitalWrite(LED_Rojo, HIGH);
  //  Cursor(0, 0);
  //  Serial.print(Radar, DEC);
  //  Serial.print("  ");
  //  Cursor(1, 0);
  //  Serial.print("Avanzar");
};

void loop() {
  oled.setRow(0);
  oled.setCol(0);
  sensorLeftMF = ReadSensor(sensorLeft, medianFilterLeft, sensorPinLeft);
  oled.print(sensorLeftMF);
  oled.print("  ");
  sensorFrontMF = ReadSensor(sensorFront, medianFilterFront, sensorPinFront);
  oled.print(sensorFrontMF);
  oled.print("  ");
  sensorRightMF = ReadSensor(sensorRight, medianFilterRight, sensorPinRight);
  oled.print(sensorRightMF);
  oled.print("  ");
  oled.setRow(2);
  oled.setCol(0);
  oled.print(sensorLeftMF + sensorRightMF);
  oled.print("  ");
  diferencial = (sensorLeftMF + sensorRightMF) / 2;
  oled.print(diferencial);
  oled.print("  ");
  LeerEventos();
  FSMEstados();
}

int ReadSensor(int &sensor, MedianFilter<int> &Filtro, int pin)
{
  sensor = analogRead(pin);
  return Filtro.AddValue(sensor);
}

//#define LED_Rojo 9
//#define LED_Azul 10
//#define ECHOPIN 12    // Pin to receive echo pulse
//#define TRIGPIN 13    // Pin to send trigger pulse
//
//#define STOP 0
//#define FWD_DER 128
//#define FWD_IZQ 128
//#define REV_DER -128
//#define REV_IZQ -128
//
////Declaracion del nombre de ESTADOS y de EVENTOS 913300269
//#define ST_LEE_SENSOR    0x01
//#define ESTADO2   0x02
//#define ESTADO3   0x03
//#define ST_AVANZAR  0x04
//
//#define EV_Null     0x40
//#define EV_Reset  0x41
//#define EV_Front  0x42
//#define EV_Stop   0x43
//#define EV_Rear   0x44
