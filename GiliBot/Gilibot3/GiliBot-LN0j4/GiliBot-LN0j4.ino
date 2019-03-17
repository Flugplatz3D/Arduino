#include <Wire.h>
#include <SSD1306Ascii.h>
#include <SSD1306AsciiWire.h>
#include <MedianFilter.h>
#include "Motors.h"

SSD1306AsciiWire oled;
Motors Motores;

#define Ventana 100
#define VelocidadChocar 150
#define VelocidadGirar 75

//Declaracion del nombre de ESTADOS y de EVENTOS
#define CHOCAR     1
#define PARAR      2
#define DERECHA    3
#define IZQUIERDA  4

unsigned int Estado = 3;
unsigned int Evento;

#define EV_Norte    6
#define EV_Sur      9
#define EV_Este     4
#define EV_Oeste    8
#define EV_I_D      3
#define EV_Fuera    0

MedianFilter medianFilterLeft(Ventana, 0);
MedianFilter medianFilterFront(Ventana, 0);
MedianFilter medianFilterRight(Ventana, 0);

int sensorPinRight = A0;
int sensorPinFront = A1;
int sensorPinLeft = A2;

int sensorLeft, sensorFront, sensorRight;
int sensorLeftMF, sensorFrontMF, sensorRightMF;
int diferencial;

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
  oled.setCol(36);
  oled.print("Vers.LN0j4");
  delay(3000);
  oled.clear();
  //  Motores.Move(VelocidadChocar, VelocidadChocar);
  //  delay(2000);
  //  Motores.Stop();
}

void loop() {
  sensorLeftMF = ReadSensor(sensorLeft, medianFilterLeft, sensorPinLeft);
  sensorFrontMF = ReadSensor(sensorFront, medianFilterFront, sensorPinFront);
  sensorRightMF = ReadSensor(sensorRight, medianFilterRight, sensorPinRight);
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
  LeerEventos();
  FSMEstados();
}

int ReadSensor(int &sensor, MedianFilter &Filtro, int pin)
{
  sensor = analogRead(pin);
  Filtro.in(sensor);
  return Filtro.out();
}

void FSMEstados()
{
  switch (Estado)
  {
    case CHOCAR:
      {
        switch (Evento)
        {
          case EV_Norte:
            {
              Estado = CHOCAR;
              break;
            }
          case EV_Sur:
          case EV_Este:
          case EV_Oeste:
            {
              Estado = PARAR;
              Motores.Stop();
              break;
            }
        }
        Func_ST_CHOCAR();
        break;
      }
    case PARAR:
      {
        switch (Evento)
        {
          //          case EV_Sur:
          //            {
          //              break;
          //            }
          default:
            {
              break;
            }
        }
        Func_ST_PARAR();
        break;
      }
    case DERECHA:
      {
        Func_ST_DERECHA();
        break;
      }
    case IZQUIERDA:
      {
        Func_ST_IZQUIERDA();
        break;
      }
  }
}

void LeerEventos() {
  // Evento = 0;
  //  if (Radar > 10)
  //  {
  //    Evento = EV_Front;
  //  }
  //  else if (Radar < 8)
  //  {
  //    Evento = EV_Rear;
  //  }
  //  else
  //  {
  //    Evento = EV_Stop;
  //  }
};

void Func_ST_IZQUIERDA() {
}

void Func_ST_CHOCAR() {
}

void Func_ST_PARAR() {
}

void Func_ST_DERECHA() {
}
