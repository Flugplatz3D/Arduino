#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DRV8835MotorShield.h>
/*
   This example uses the DRV8835MotorShield library to drive each motor with the
   Pololu DRV8835 Dual Motor Driver Shield for Arduino forward, then backward.
   The yellow user LED is on when a motor is set to a positive speed and off when
   a motor is set to a negative speed.
  M1DIR = 7;
  M2DIR = 8;
  M1PWM = 9;
  M2PWM = 10;
*/

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

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
  pinMode(ledPin, OUTPUT);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done

  // uncomment one or both of the following lines if your motors' directions need to be flipped
  motors.flipM1(true);
  motors.flipM2(true);

  motors.setM1Speed(0); //IZ
  motors.setM2Speed(0); //DR

  // Clear the buffer.
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  time1 = millis();
  time2 = 0;
  while (time2 <= 10000)
  {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(i);
    display.display();
    delay(1000);
    i--;
    time2 = millis() - time1;
  }
}

void loop() {
  sensorValueR = analogRead(sensorPinR);
  sensorValueL = analogRead(sensorPinL);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print(sensorValueR);
  display.setCursor(64, 0);
  display.print(sensorValueL);
  display.display();

  if (sensorValueR <= 50 && sensorValueL <= 50)
  {
    motors.setM1Speed(150);
    motors.setM2Speed(150);
  }
  if (sensorValueR >= 50 && sensorValueL >= 50)
  {
    motors.setM1Speed(0);
    motors.setM2Speed(0);
  }
  if (sensorValueR >= 50 && sensorValueL <= 50)
  {
    motors.setM1Speed(-60);
    motors.setM2Speed(150);
  }
  if (sensorValueR <= 50 && sensorValueL >= 50)
  {
    motors.setM1Speed(150);
    motors.setM2Speed(-60);
  }
}
