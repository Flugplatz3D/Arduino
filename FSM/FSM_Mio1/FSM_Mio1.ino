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

//Declaracion del nombre de ESTADOS y de EVENTOS 913300269
#define ST_LEE_SENSOR  	0x01
#define ESTADO2  	0x02
#define ESTADO3  	0x03
#define ST_AVANZAR  0x04

#define EV_Null     0x40
#define EV_Reset	0x41
#define EV_Front	0x42
#define EV_Stop		0x43
#define EV_Rear		0x44

unsigned int An0;
unsigned int Radar;
OrangutanMotors motors;
OrangutanAnalog analog;
OrangutanLEDs leds;
OrangutanLCD lcd;
unsigned int miEstado;
unsigned int miEvento;

void setup() {
  motors.setSpeeds(STOP, STOP);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  lcd.clear();
  lcd.print("Inicio");
  delay(1500);
  miEstado = ST_LEE_SENSOR;
  Radar = 9; //parado la primera lectura
}

void LeerEventos() {
  miEvento = 0;
  if (Radar > 10)
  {
    miEvento = EV_Front;
  }
  else if (Radar < 8)
  {
    miEvento = EV_Rear;
  }
  else
  {
    miEvento = EV_Stop;
  }
};

void FSMEstados()
{
  switch (miEstado)
  {
    case ST_LEE_SENSOR:
      {
        switch (miEvento)
        {
          case EV_Stop:
            {
              miEstado = ST_LEE_SENSOR;
              break;
            }
          case EV_Rear:
            {
              miEstado = ESTADO3;
              break;
            }
          case EV_Front:
            {
              miEstado = ST_AVANZAR;
              break;
            }
        }
        break;
        FuncST1();
      }
    case ESTADO2:
      {
        switch (miEvento)
        {
          case EV_Stop:
            {} break;
          case EV_Reset:
            {} break;
        }
        break;
        FuncST2();
      }
    case ESTADO3:
      {
        switch (miEvento)
        {
          case EV_Reset:
            {} break;
        }
        break;
        FuncST3();
      }
    case ST_AVANZAR:
      {
        switch (miEvento)
        {
          case EV_Front:
            {
              miEstado = ST_LEE_SENSOR;
              break;
            }
          default:
            {}
        }
        break;
        FuncST4();
      }
  }
}

void loop() {
  LeerEventos();
  FSMEstados();
}

void FuncST1() {
  Radar = LeeSensorUS();
};

void FuncST2() {
  lcd.clear();
  motors.setSpeeds(STOP, STOP);
  leds.red(LOW);
  leds.green(HIGH);
  lcd.gotoXY(0, 0);               // LCD cursor to home position (upper-left)
  lcd.print(Radar);
  lcd.print("  ");
  lcd.gotoXY(0, 1);               // LCD cursor to start of the second line
  lcd.print("Parar");
};

void FuncST3() {
  lcd.clear();
  motors.setSpeeds(REV_DER, REV_IZQ);
  leds.red(HIGH);
  leds.green(LOW);
  lcd.gotoXY(0, 0);               // LCD cursor to home position (upper-left)
  lcd.print(Radar);
  lcd.print("  ");
  lcd.gotoXY(0, 1);               // LCD cursor to start of the second line
  lcd.print("Retroceder");
};

void FuncST4() {
  lcd.clear();
  motors.setSpeeds(FWD_DER, FWD_IZQ);
  leds.red(LOW);
  leds.green(HIGH);
  lcd.gotoXY(0, 0);               // LCD cursor to home position (upper-left)
  lcd.print(Radar);
  lcd.print("  ");
  lcd.gotoXY(0, 1);               // LCD cursor to start of the second line
  lcd.print("Avanzar");
};

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
