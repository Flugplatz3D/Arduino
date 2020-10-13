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
#define switchPin PA2

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
  }
  else
  {
    if (i < 99)
    {
      i++;
    }
  }
  time1 = millis();
}

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  pinMode(controlPin, INPUT);
  Wire.begin();
  Wire.setClock(400000L);
  //oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.begin(&SH1106_128x64, I2C_ADDRESS);
  oled.setFont(System5x7);
  oled.clear();
  oled.println("Test DiyMore");
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
//    oled.setRow(6);
//    oled.setCol(50);
//    oled.print(digitalRead(switchPin));
//    oled.clearToEOL();
    oled.setRow(7);
    oled.setCol(0);
    oled.print(time1);
    oled.clearToEOL();
    time2 = time1;
  }
  else if (digitalRead(switchPin) == 0)
  {
    j = 0;
    i = 0;
    oled.setFont(Verdana_digits_24);
    oled.setRow(0);
    oled.setCol(45);
    oled.print(i);
    oled.clearToEOL();
  }
}
