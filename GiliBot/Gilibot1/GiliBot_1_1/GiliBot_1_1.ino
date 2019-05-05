#include "Motors293.h"
#include <Adafruit_NeoPixel.h>

#define PIN  6
#define NUMPIXELS  3

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int sensorPinR = A0;
int sensorPinL = A1;
int sensorValueR = 0;
int sensorValueL = 0;
int i = 0;

Motors293 Motores;

void setup() {
  Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.setPixelColor(0, pixels.Color(40, 0, 20));
  pixels.setPixelColor(1, pixels.Color(40, 0, 20));
  pixels.setPixelColor(2, pixels.Color(40, 0, 20));
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(5000);
  for (i = 0; i < 10  ; i++)
  {
    pixels.setPixelColor(0, pixels.Color(0, 0, 80));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 80));
    pixels.show();
    delay(250);
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.setPixelColor(1, pixels.Color(80, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    pixels.show();
    delay(250);
  }
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.setPixelColor(1, pixels.Color(0, 0, 0));
  pixels.setPixelColor(2, pixels.Color(0, 0, 0));
  pixels.show();
  delay(1000);
  Motores.Stop();
}

void loop() {
  sensorValueR = analogRead(sensorPinR);
  sensorValueL = analogRead(sensorPinL);
  if (sensorValueR <= 50 && sensorValueL <= 50)
  {
    Motores.Move(150, 150);
    pixels.setPixelColor(0, pixels.Color(0, 15, 0));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 15, 0));
    pixels.show();
  }
  if (sensorValueR >= 50 && sensorValueL >= 50)
  {
    Motores.Stop();
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    pixels.show();
  }
  if (sensorValueR >= 50 && sensorValueL <= 50)
  {
    Motores.Move(-75, 200);
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(15, 0, 0));
    pixels.show();
  }
  if (sensorValueR <= 50 && sensorValueL >= 50)
  {
    Motores.Move(200, -75);
    pixels.setPixelColor(0, pixels.Color(15, 0, 0));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    pixels.show();
  }
}
