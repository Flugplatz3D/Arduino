#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

int sensorPinLeft = A0;
int sensorPinFront = A1;
int sensorPinRight = A2;
int sensorLeft = 0;
int sensorFront = 0;
int sensorRight = 0;
int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(24, 0);
  display.print("GiliBot");
  display.setTextSize(1);
  display.setCursor(40, 24);
  display.print("Vers.LN0a");
  display.display();
  delay(3000);
  display.clearDisplay();
  display.display();
}

void loop() {
  display.clearDisplay();
  sensorLeft = analogRead(sensorPinLeft);
  sensorFront = analogRead(sensorPinFront);
  sensorRight = analogRead(sensorPinRight);
  display.setCursor(0, 0);
  display.print("R - ");
  display.setCursor(24, 0);
  display.print(sensorRight);
  display.setCursor(0, 12);
  display.print("F - ");
  display.setCursor(24, 12);
  display.print(sensorFront);
  display.setCursor(0, 24);
  display.print("L - ");
  display.setCursor(24, 24);
  display.print(sensorLeft);
  display.display();
}
