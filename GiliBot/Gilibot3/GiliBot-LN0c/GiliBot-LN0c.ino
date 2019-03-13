#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "MedianFilterLib.h"

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define Ventana 50
MedianFilter<int> medianFilterLeft(Ventana);
MedianFilter<int> medianFilterFront(Ventana);
MedianFilter<int> medianFilterRight(Ventana);

int sensorPinRight = A0;
int sensorPinFront = A1;
int sensorPinLeft = A2;
int sensorLeft = 0;
int sensorFront = 0;
int sensorRight = 0;
int sensorLeftMF = 0;
int sensorFrontMF = 0;
int sensorRightMF = 0;
//int ledPin = 13;

void setup() {
  //  Serial.begin(9600);
  //  pinMode(ledPin, OUTPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(24, 0);
  display.print("GiliBot");
  display.setTextSize(1);
  display.setCursor(40, 24);
  display.print("Vers.LN0b");
  display.display();
  delay(3000);
  display.clearDisplay();
  display.display();
}

void loop() {
  display.clearDisplay();
  sensorRight = analogRead(sensorPinRight);
  sensorRightMF = medianFilterRight.AddValue(sensorRight);
  //  Serial.print(sensorRight);
  //  Serial.print(",");
  //  Serial.print(sensorRightMF);
  sensorFront = analogRead(sensorPinFront);
  sensorFrontMF = medianFilterFront.AddValue(sensorFront);
  //  Serial.print(",");
  //  Serial.print(sensorFront);
  //  Serial.print(",");
  //  Serial.print(sensorFrontMF);
  sensorLeft = analogRead(sensorPinLeft);
  sensorLeftMF = medianFilterLeft.AddValue(sensorLeft);
  //  Serial.print(",");
  //  Serial.print(sensorLeft);
  //  Serial.print(",");
  //  Serial.println(sensorLeftMF);
  display.setCursor(0, 0);
  display.print("R - ");
  display.setCursor(24, 0);
  display.print(sensorRight);
  display.setCursor(64, 0);
  display.print(sensorRightMF);
  display.setCursor(0, 12);
  display.print("F - ");
  display.setCursor(24, 12);
  display.print(sensorFrontMF);
  display.setCursor(64, 12);
  display.print(sensorFront);
  display.setCursor(0, 24);
  display.print("L - ");
  display.setCursor(24, 24);
  display.print(sensorLeftMF);
  display.setCursor(64, 24);
  display.print(sensorLeft);
  display.display();
}
