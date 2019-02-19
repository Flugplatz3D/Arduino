#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);

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
  //display.print("SH1106 I2C");
  //display.setCursor(0, 11);
  display.print(millis());
  //display.setTextSize(1);
  display.setCursor(0, 18);
  display.print(inString);
  display.display();
  //delay(50);
}
