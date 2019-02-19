#include <SoftwareSerial.h>
char c;
const int LEDR = 3;
const int LEDG = 5;
const int LEDB = 6;
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
  delay(1000);
}

void loop()
{
  while (!mySerial.available());
  c = mySerial.read();
  switch (c) {
    case ('0'):
      {
        analogWrite(LEDR, 0);
        analogWrite(LEDG, 0);
        analogWrite(LEDB, 0);
        break;
      }
    case ('1'):
      {
        analogWrite(LEDR, 255);
        analogWrite(LEDG, 255);
        analogWrite(LEDB, 210);
        break;
      }
    case ('2'):
      {
        analogWrite(LEDR, 255);
        analogWrite(LEDG, 0);
        analogWrite(LEDB, 0);
        break;
      }
    case ('3'):
      {
        analogWrite(LEDR, 0);
        analogWrite(LEDG, 255);
        analogWrite(LEDB, 0);
        break;
      }
    case ('4'):
      {
        analogWrite(LEDR, 0);
        analogWrite(LEDG, 0);
        analogWrite(LEDB, 255);
        break;
      }
    case ('5'):
      {
        analogWrite(LEDR, 255);
        analogWrite(LEDG, 255);
        analogWrite(LEDB, 0);
        break;
      }
  }
}

