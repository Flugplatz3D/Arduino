#include <SoftwareSerial.h>
char c;
const int LEDR = 3;
const int LEDG = 5;
const int LEDB = 6;
int Rojo = 0;
int Verde = 0;
int Azul = 0;
const int pRX = 10;
const int pTX = 11;

SoftwareSerial mySerial(pRX, pTX);

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  Serial.println("HC-06 On-Line");
}

void loop()
{
  while (!mySerial.available());
  c = mySerial.read();
  switch (c) {
    case ('0'):
      {
        Rojo = 0;
        Verde = 0;
        Azul = 0;
        break;
      }
    case ('1'):
      {
        if (Rojo <= 250)
        {
          Rojo += 5;
        }
        break;
      }
    case ('4'):
      {
        if (Rojo >= 5)
        {
          Rojo -=5;
        }
        break;
      }
    case ('2'):
      {
        if (Verde <= 250)
        {
          Verde += 5;
        }
        break;
      }
    case ('5'):
      {
        if (Verde >=5)
        {
          Verde -= 5;
        }
        break;
      }
    case ('3'):
      {
        if (Azul <= 250)
        {
          Azul += 5;
        }
        break;
      }
    case ('6'):
      {
        if (Azul >= 5)
        {
          Azul -= 5;
        }
        break;
      }
  }
  analogWrite(LEDR, Rojo);
  analogWrite(LEDG, Verde);
  analogWrite(LEDB, Azul);
  Serial.print("Rojo -> ");
  Serial.print(Rojo, DEC);
  Serial.print("  Verde -> ");
  Serial.print(Verde, DEC);
  Serial.print("  Azul -> ");
  Serial.print(Azul, DEC);
  Serial.println();
}

