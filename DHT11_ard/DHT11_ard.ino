#include <DHT.h>
#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C
#define LED 13

SSD1306AsciiWire oled;

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(LED, OUTPUT);
  dht.begin();
  Wire.begin();
  Wire.setClock(400000L);
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  //  oled.begin(&SH1106_128x64, I2C_ADDRESS);
  oled.setFont(lcd5x7);
  oled.clear();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  oled.set1X();
  oled.setRow(0);
  oled.setCol(0);
  oled.print("Temp:  ");
  oled.set2X();
  oled.print(t);
  oled.set1X();
  oled.setRow(3);
  oled.setCol(0);
  oled.print("Humid: ");
  oled.set2X();
  oled.print(h);
  oled.clearToEOL();
  oled.set1X();
  oled.setRow(7);
  oled.setCol(0);
  oled.print(millis());
  oled.clearToEOL();
  delay(5000);
  digitalWrite(LED, HIGH );
  delay(5);
  digitalWrite(LED, LOW );
}
