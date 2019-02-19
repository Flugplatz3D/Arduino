#include <SoftwareSerial.h>
char c;
const int LEDR = 3;
const int LEDG = 5;
const int LEDB = 6;
const int pRX = 10;
const int pTX = 11;
int i = 0;

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
  if (c == '1')
  {
    i++;
    Serial.println(i, DEC);
  }
  if (c == '0')
  {
    i--;
    Serial.println(i, DEC);
  }
  if (i > 0)
  {
    analogWrite(LEDR, 255);
    analogWrite(LEDG, 255);
    analogWrite(LEDB, 255);
  }
  else
  {
    analogWrite(LEDR, 0);
    analogWrite(LEDG, 0);
    analogWrite(LEDB, 0);
  }
}

