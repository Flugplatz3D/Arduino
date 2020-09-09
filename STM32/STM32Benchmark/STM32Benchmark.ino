#include <Adafruit_GFX_AS.h>  //https://github.com/rogerclarkmelbourne/Arduino_STM32/tree/master/STM32F1/libraries/Adafruit_GFX_AS
#include "Adafruit_ST7735.h" // https://github.com/KenjutsuGH/Adafruit-ST7735-Library

//Please note that you need to delete the Adafruit ST7735 library for Arduino if you have it installed, else the
//sketch won't compile.

#define cs     PA2
#define rst    PA4 
#define dc     PA3

// Color definitions
#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF

#define ITERATIONS 500000L    // number of iterations
#define REFRESH_TFT 7500      // refresh bar every 7500 iterations
#define ACTIVATED LOW 

#if defined(__SAM3X8E__)
    #undef __FlashStringHelper::F(string_literal)
    #define F(string_literal) string_literal
#endif

Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, rst);

int percent = 0;
int progress = 1;
const int buttonPin = PB9;     
int buttonState = 0;    

void setup(void) {

  pinMode(buttonPin, INPUT_PULLUP);  
  
  Serial.begin(9600);
  
  tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab

  tft.fillScreen(ST7735_BLACK);

  printUI();
 
}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  if (buttonState == ACTIVATED) {   
    removePressKeyText();
    drawBar();
    startCalculation();
  }
  else {
  }

delay(10);
}

void fillBar(int percent)
{
    int counter =60;
    percent = map(percent,0,100,5,121);     
    for(counter = 60; counter<75;counter++)
    {
     tft.drawFastHLine(5, counter, percent, YELLOW );
    }
}

void printUI()
{
 tft.setCursor(30,5);
 tft.setTextColor(RED);
 tft.setTextSize(1);
 tft.print("PI BENCHMARK");

 tft.setCursor(30,60);
 tft.setTextColor(WHITE);
 tft.setTextSize(1);
 tft.print("PRESS KEY");
 
 tft.setCursor(5,120);
 tft.setTextColor(RED);
 tft.setTextSize(1);
 tft.print("PI:");

 tft.setCursor(5,140);
 tft.setTextColor(RED);
 tft.setTextSize(1);
 tft.print("TIME:");
}

void removePressKeyText()
{
 tft.setCursor(30,60);
 tft.setTextColor(BLACK);
 tft.setTextSize(1);
 tft.print("PRESS KEY");
}

void drawBar()
{
  tft.drawRect(5,60,120,15, YELLOW);
}

void startCalculation()
{
 unsigned long start, time;
 unsigned long niter=ITERATIONS;
 int LEDcounter = 0;
 unsigned long i;
 float x = 1.0;
 float pi=1.0;

 Serial.begin(9600);
 Serial.print("Beginning ");
 Serial.print(niter);
 Serial.println(" iterations...");
 Serial.println();

 start = millis();  
 for ( i = 2; i < niter; i++) {
   x *= -1.0;
   pi += x / (2.0f*(float)i-1.0f);   
    if (LEDcounter++ > REFRESH_TFT) {
     LEDcounter = 0;
     progress++;
     percent = progress*100/(ITERATIONS/ REFRESH_TFT);
     fillBar(percent);
    }
 }
 time = millis() - start;
 
 pi = pi * 4.0;

 Serial.print("# of trials = ");
 Serial.println(niter);
 Serial.print("Estimate of pi = ");
 String piString = String(pi,7);
 String timeString = String(time)+"ms";
 Serial.println(piString);
 
 Serial.print("Time: "); Serial.print(time); Serial.println(" ms");
 
 tft.setCursor(40,120);
 tft.setTextColor(GREEN);
 tft.setTextSize(1);
 tft.print(piString);

 tft.setCursor(40,140);
 tft.setTextColor(GREEN);
 tft.setTextSize(1);
 tft.print(timeString);
}
