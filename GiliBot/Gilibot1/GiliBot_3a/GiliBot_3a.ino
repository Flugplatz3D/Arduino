#include <DRV8835MotorShield.h>
#include <Adafruit_NeoPixel.h>
/*
  M1DIR = 7;
  M2DIR = 8;
  M1PWM = 9;
  M2PWM = 10;
*/

#define PIN  6
#define NUMPIXELS  3

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int sensorPinR = A0;
int sensorPinL = A1;
int ledPin = 13;
int sensorValueR = 0;
int sensorValueL = 0;
int i = 10;
unsigned long time1 = 0;
unsigned long time2 = 0;

DRV8835MotorShield motors;

void setup() {

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
  pixels.setPixelColor(0, pixels.Color(0, 15, 0));
  pixels.setPixelColor(1, pixels.Color(0, 0, 0));
  pixels.setPixelColor(2, pixels.Color(0, 15, 0));
  pixels.show();

  pinMode(ledPin, OUTPUT);

  // uncomment one or both of the following lines if your motors' directions need to be flipped
  motors.flipM1(true);
  motors.flipM2(true);

  motors.setM1Speed(0); //IZ
  motors.setM2Speed(0); //DR

}

void loop() {
  sensorValueR = analogRead(sensorPinR);
  sensorValueL = analogRead(sensorPinL);

  if (sensorValueR <= 50 && sensorValueL <= 50)
  {
    motors.setM1Speed(255);
    motors.setM2Speed(255);
  }
  if (sensorValueR >= 50 && sensorValueL >= 50)
  {
    motors.setM1Speed(0);
    motors.setM2Speed(0);
  }
  if (sensorValueR >= 50 && sensorValueL <= 50)
  {
    motors.setM1Speed(-75);
    motors.setM2Speed(255);
  }
  if (sensorValueR <= 50 && sensorValueL >= 50)
  {
    motors.setM1Speed(255);
    motors.setM2Speed(-75);
  }
}
