#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C
#include <AM2320.h>

#define LED 17

AM2320 th;
SSD1306AsciiWire oled;
const int buttonPin = 7;
int boton = 0;

unsigned long segundo = 0;
unsigned long minuto = 0;
unsigned long hora = 0;
unsigned long segundot = 0;
unsigned long minutot = 0;

unsigned long time1 = 0;
unsigned long time2 = 0;
String inString = "";

unsigned long timeFlash = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  Wire.begin();
  Wire.setClock(400000L);
  //oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.begin(&SH1106_128x64, I2C_ADDRESS);
  oled.setFont(lcd5x7);
  oled.clear();
  oled.set2X();
  oled.println("AM2320");
  oled.println();
  oled.set1X();
  oled.print("Arduino");
  delay(3000);
  oled.clear();
  leerSensor();
  delay(3000);
  oled.clear();
  timeFlash = millis();
}

void loop() {
  boton = digitalRead(buttonPin);
  if (boton == 0)
  {
    delay(100);
    leerSensor();
    delay(8000);
    oled.clear();
  }
  if (millis() - timeFlash > 5000)
  {
    digitalWrite(LED, LOW );
    delay(5);
    digitalWrite(LED, HIGH );
    timeFlash = millis();
  }
}

void leerSensor()
{
  switch (th.Read()) {
    case 2:
      oled.set1X();
      oled.clear();
      oled.setRow(0);
      oled.setCol(0);
      oled.print("CRC failed");
      break;
    case 1:
      oled.set1X();
      oled.clear();
      oled.setRow(0);
      oled.setCol(0);
      oled.print("Sensor offline");
      break;
    case 0:
      oled.set1X();
      oled.setRow(0);
      oled.setCol(0);
      oled.print("Temp:  ");
      oled.set2X();
      oled.print(th.t);
      oled.clearToEOL();
      oled.set1X();
      oled.setRow(3);
      oled.setCol(0);
      oled.print("Humid: ");
      oled.set2X();
      oled.print(th.h);
      oled.clearToEOL();
      break;
  }
  crono();
  oled.set1X();
  oled.setRow(7);
  oled.setCol(0);
  oled.print(inString);
  oled.clearToEOL();
}

void crono()
{
  inString = "";
  time2 = millis();
  segundo = millis() / 1000;
  minuto = segundo / 60;
  hora = minuto / 60;
  minutot = minuto - (hora * 60);
  segundot = segundo - (minuto * 60);
  inString += hora;
  inString += ":";
  inString += minutot;
  inString += ":";
  inString += segundot;
}
