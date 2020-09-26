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
byte u = 0, d = 0;
unsigned long time1 = 0;
unsigned long time2 = 0;
byte control = 0;
//char output[50];

void intSR()
{
  control = digitalRead(controlPin);
  if (control == 0)
  {
    d = 1;
    digitalWrite(LED, HIGH);
  }
  else
  {
    u = 1;
    digitalWrite(LED, LOW);
  }
}

void setup() {
  //  Serial.begin(9600);
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
  oled.setCol(40);
  oled.print(i);
  oled.clearToEOL();
}

void loop() {
  if (u == 1 || d == 1)
  {
    detachInterrupt(digitalPinToInterrupt(intPin));
    time1 = millis() - time1;
    //    sprintf(output, "%u - %u - %lu - %d", i, time1, millis(), digitalRead(controlPin));
    //    Serial.println(output);
    if (u == 1 && i < 199) {
      i++;
    }
    else if (d == 1 && i > 0)
    {
      i--;
    }
    oled.setFont(Verdana_digits_24);
    oled.setRow(0);
    oled.setCol(40);
    oled.print(i);
    oled.clearToEOL();
    oled.setFont(System5x7);
    oled.setRow(6);
    oled.setCol(0);
    oled.print(time1);
    oled.clearToEOL();
    oled.setRow(7);
    oled.setCol(0);
    oled.print(time2);
    oled.clearToEOL();
    time1 = millis();
    u = 0;
    d = 0;
    time2 = 0;
    attachInterrupt(digitalPinToInterrupt(intPin), intSR, RISING);
  }
  time2 ++;
}
