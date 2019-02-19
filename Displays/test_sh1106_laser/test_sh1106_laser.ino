#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <VL53L0X.h>

#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);
VL53L0X sensor;

byte m = 0;
unsigned long segundo = 0;
unsigned long minuto = 0;
unsigned long hora = 0;
unsigned long dia = 0;
unsigned long segundot = 0;
unsigned long minutot = 0;
unsigned long horat = 0;

unsigned long time1 = 0;
unsigned long time2 = 0;
String inString = "";

void setup()   {
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x64)
  // init done

  // Clear the buffer.
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.display();
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();
}

void loop() {
  display.clearDisplay();
  inString = "";
  time2 = millis();
  segundo = millis() / 1000;
  minuto = segundo / 60;
  hora = minuto / 60;
  dia = hora / 24;
  horat = hora - (dia * 24);
  minutot = minuto - (hora * 60);
  segundot = segundo - (minuto * 60);
  inString += dia;
  inString += ":";
  inString += horat;
  inString += ":";
  inString += minutot;
  inString += ":";
  inString += segundot;
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print(sensor.readRangeContinuousMillimeters());
  display.setTextSize(1);
  display.setCursor(0, 22);
  display.print(inString);
  display.setCursor(0, 32);
  display.print(millis());
  display.display();
  //delay(50);
}
