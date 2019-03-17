#include "MedianFilterLib.h"

#define Ventana 100
MedianFilter<int> medianFilterLeft(Ventana);
MedianFilter<int> medianFilterFront(Ventana);
MedianFilter<int> medianFilterRight(Ventana);

int sensorPinRight = A0;
int sensorPinFront = A1;
int sensorPinLeft = A2;
int sensorLeft, sensorFront, sensorRight;
int sensorLeftMF, sensorFrontMF, sensorRightMF;

byte miEstado, miEvento;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorLeftMF = ReadSensor(sensorLeft, medianFilterLeft, sensorPinLeft);
  sensorFrontMF = ReadSensor(sensorFront, medianFilterFront, sensorPinFront);
  sensorRightMF = ReadSensor(sensorRight, medianFilterRight, sensorPinRight);
  Serial.print(sensorLeftMF);
  Serial.print(",");
  Serial.print(sensorFrontMF);
  Serial.print(",");
  Serial.println(sensorRightMF);
  LeerEventos();
  FSMEstados();
}

int ReadSensor(int &sensor, MedianFilter<int> &Filtro, int pin)
{
  sensor = analogRead(pin);
  return Filtro.AddValue(sensor);
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
