#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

SSD1306AsciiWire oled;

byte m = 0;
unsigned long segundo = 0;
unsigned long minuto = 0;
unsigned long hora = 0;
unsigned long segundot = 0;
unsigned long minutot = 0;

unsigned long time1 = 0;
unsigned long time2 = 0;
String inString = "";

void setup () {
//  Serial.begin(9600);
  Wire.begin();
  Wire.setClock(400000L);
  //  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.begin(&SH1106_128x64, I2C_ADDRESS);
  oled.setFont(System5x7);
  oled.clear();
  oled.set2X();
  oled.println("Test");
  oled.println("SH1106");
  oled.set1X();
  oled.println("");
  oled.print("SSD1306Ascii lib");
  delay(4000);
  oled.clear();
}
//------------------------------------------------------------------------------
void loop () {
  time2 = millis();
//  Serial.println(time2);
  segundo = time2 / 1000;
  minuto = segundo / 60;
  hora = minuto / 60;
  minutot = minuto - (hora * 60);
  segundot = segundo - (minuto * 60);
  inString = "";
  inString += hora;
  inString += ":";
  inString += minutot;
  inString += ":";
  inString += segundot;
  oled.set2X();
  oled.setRow(0);
  oled.setCol(0);
  oled.print(inString);
  oled.clearToEOL();
  oled.set1X();
  oled.setRow(4);
  oled.setCol(0);
  oled.print(time2);
  oled.clearToEOL();
}
