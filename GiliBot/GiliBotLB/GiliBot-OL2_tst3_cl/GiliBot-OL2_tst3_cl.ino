#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
#include "SensoresIR.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C
SSD1306AsciiWire oled;

SensoresIR sensores;
int vSensorLeft;
int vSensorFront;
int vSensorRight;
int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  Wire.begin();
  Wire.setClock(400000L);
  oled.begin(&Adafruit128x32, I2C_ADDRESS);
  oled.setFont(System5x7);
  oled.clear();
  oled.set2X();
  oled.println("GiliBot4");
  oled.set1X();
  oled.println("");
  oled.println("MVC-202003");
  digitalWrite(ledPin, HIGH);
  delay(3000);
  oled.clear();
  digitalWrite(ledPin, LOW);
}

void loop() {
  sensores.ReadABS(vSensorLeft, vSensorFront, vSensorRight);
  oled.setRow(0);
  oled.setCol(0);
  oled.print("    ");
  oled.setRow(0);
  oled.setCol(0);
  oled.print(vSensorLeft);
  oled.setRow(0);
  oled.setCol(32);
  oled.print("    ");
  oled.setRow(0);
  oled.setCol(32);
  oled.print(vSensorFront);
  oled.setRow(0);
  oled.setCol(64);
  oled.print("    ");
  oled.setRow(0);
  oled.setCol(64);
  oled.print(vSensorRight);
  oled.setRow(3);
  oled.setCol(0);
  oled.print("    ");
  oled.setRow(3);
  oled.setCol(0);
  oled.print(sensores.ReadWalls());
  delay(50);
  //  digitalWrite(ledPin, !digitalRead(ledPin));
}
