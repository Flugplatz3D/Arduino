#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

SSD1306AsciiWire oled;
unsigned long cuenta = 0;
const int sensorPin = 4;
int sensorState = 0;
int reads = 0;
int suma = 0;
unsigned long timeActual = 0;
unsigned long timeAnterior = 0;
unsigned long timeResta = 0;
unsigned long timeRestaEMA = 0;
float EMA_ALPHA = 0.1;
int EMA_LP = 400;
float rpm;

void setup () {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  Wire.begin();
  Wire.setClock(400000L);
  //  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.begin(&SH1106_128x64, I2C_ADDRESS);
  oled.setFont(lcd5x7);
  oled.clear();
  oled.print("Test SH1106");
  delay(3000);
  oled.clear();
  oled.set2X();
  timeActual = millis();
}

void loop () {
  sensorState = digitalRead(sensorPin);
  if (sensorState == HIGH) {
    timeActual = millis();
    timeResta = timeActual - timeAnterior;
    timeAnterior = timeActual;
    timeRestaEMA = EMALowPassFilter(timeResta);
    while (sensorState == HIGH)
    {
      sensorState = digitalRead(sensorPin);
      delay(20);
    }
    suma = suma + timeRestaEMA;
    reads ++;
    if (reads > 3)
    {
      rpm = 60 * (1.0 / ((float)suma / 1000.0));
      Serial.print(timeRestaEMA);
      Serial.print(" - ");
      Serial.println(rpm, 2);
      oled.setRow(0);
      oled.setCol(0);
      oled.print(rpm);
      oled.clearToEOL();
      reads = 1;
      suma = 0;
    }
  }
}

int EMALowPassFilter(int value)
{
  EMA_LP = EMA_ALPHA * value + (1 - EMA_ALPHA) * EMA_LP;
  return EMA_LP;
}
