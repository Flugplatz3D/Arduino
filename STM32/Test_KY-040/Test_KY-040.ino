#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

SSD1306AsciiWire oled;

#define LED PC13
//#define LED PB1 Maple Mini
#define intPin PA0
#define controlPin PA1

int i = 0, j = 0;
unsigned long time1 = 0;
unsigned long time2 = 201;
byte control = 0;

void intSR()
{
  control = digitalRead(controlPin);
  if (control == 0)
  {
    if (i > 0)
    {
      i--;
    }
    digitalWrite(LED, HIGH);
  }
  else
  {
    if (i < 99)
    {
      i++;
    }
    digitalWrite(LED, LOW);
  }
  time1 = millis();
}

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(controlPin, INPUT);
  Wire.begin();
  Wire.setClock(400000L);
  //oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.begin(&SH1106_128x64, I2C_ADDRESS);
  oled.setFont(System5x7);
  oled.clear();
  oled.println("Test KY-040");
  attachInterrupt(digitalPinToInterrupt(intPin), intSR, RISING);
  delay(4000);
  oled.clear();
  oled.setFont(Verdana_digits_24);
  oled.setRow(0);
  oled.setCol(45);
  oled.print(i);
  oled.clearToEOL();
}

void loop() {
  if (j != i)
  {
    j = i;
    time2 = time1 - time2;
    detachInterrupt(digitalPinToInterrupt(intPin));
    oled.setFont(Verdana_digits_24);
    oled.setRow(0);
    oled.setCol(45);
    oled.print(i);
    oled.clearToEOL();
    oled.setFont(System5x7);
    oled.setRow(6);
    oled.setCol(0);
    oled.print(time2);
    oled.clearToEOL();
    oled.setRow(7);
    oled.setCol(0);
    oled.print(time1);
    oled.clearToEOL();
    attachInterrupt(digitalPinToInterrupt(intPin), intSR, RISING);
    time2 = time1;
  }
}
