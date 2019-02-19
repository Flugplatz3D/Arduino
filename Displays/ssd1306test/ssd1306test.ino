#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// If using software SPI (the default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

byte m = 0;
unsigned long segundo = 0;
unsigned long minuto = 0;
unsigned long hora = 0;
unsigned long segundot = 0;
unsigned long minutot = 0;

unsigned long time1 = 0;
unsigned long time2 = 0;
String inString = "";

const unsigned char PROGMEM logoMVC [] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x35, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x03, 0xF5, 0x00, 0x00, 0x3F, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0x00, 0x00, 0x7F, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0x80, 0x00, 0x7F, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0x80, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xC0, 0x00, 0x03, 0xC0, 0x3F, 0x07, 0xF0, 0x3D, 0xE3, 0xC0,
  0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xC0, 0x00, 0x03, 0xC0, 0xFF, 0x8F, 0xFC, 0x3F, 0xF7, 0xE0,
  0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xC0, 0x00, 0x07, 0x81, 0xE3, 0xC8, 0x3C, 0x7C, 0xF9, 0xE0,
  0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xE0, 0x00, 0x07, 0x81, 0xC3, 0xC0, 0x3C, 0x78, 0xF1, 0xE0,
  0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xE0, 0x00, 0x07, 0x83, 0xFF, 0xC3, 0xFC, 0x78, 0xF1, 0xE0,
  0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xE0, 0x00, 0x0F, 0x83, 0xFF, 0xDF, 0xF8, 0xF8, 0xF3, 0xC0,
  0x00, 0x00, 0x00, 0x00, 0xFF, 0xEF, 0xE0, 0x00, 0x0F, 0x03, 0xC0, 0x3E, 0x78, 0xF1, 0xE3, 0xC0,
  0x00, 0x00, 0x00, 0x01, 0xFF, 0xC7, 0xC0, 0x00, 0x0F, 0x03, 0xC0, 0xBC, 0x78, 0xF1, 0xE3, 0xC0,
  0x00, 0x00, 0x00, 0x07, 0xFF, 0xE1, 0xC0, 0x00, 0x0F, 0x03, 0xE1, 0xBC, 0xF8, 0xF1, 0xE3, 0xC0,
  0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x1E, 0x01, 0xFF, 0x3F, 0xF1, 0xE3, 0xE7, 0x80,
  0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x1E, 0x00, 0x7E, 0x1E, 0xF1, 0xE3, 0xC7, 0x80,
  0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x7B, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xFB, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0xF3, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0xF3, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0xF3, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x7C, 0x1F, 0x78, 0x1F, 0x07, 0xE0, 0x00,
  0x03, 0xF1, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x7C, 0x3F, 0x78, 0x1E, 0x1F, 0xF8, 0x00,
  0x03, 0xF1, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0xFC, 0x3E, 0x78, 0x3E, 0x3F, 0xF8, 0x00,
  0x03, 0xE1, 0xFF, 0xFF, 0xFB, 0xE0, 0x00, 0x00, 0x00, 0xFC, 0x7E, 0x78, 0x7C, 0x7C, 0x38, 0x00,
  0x03, 0xE3, 0xFF, 0xDF, 0xC1, 0xE0, 0x00, 0x00, 0x00, 0xFC, 0xFE, 0x3C, 0x78, 0xF8, 0x10, 0x00,
  0x03, 0xE3, 0xF7, 0x80, 0x01, 0xF0, 0x00, 0x00, 0x00, 0xFD, 0xDE, 0x3C, 0xF8, 0xF0, 0x00, 0x00,
  0x03, 0xC7, 0xEF, 0x00, 0x01, 0xF8, 0x00, 0x00, 0x01, 0xED, 0xFC, 0x3C, 0xF1, 0xE0, 0x00, 0x00,
  0x06, 0x07, 0xCF, 0x00, 0x07, 0xF8, 0x00, 0x00, 0x01, 0xEF, 0xBC, 0x3D, 0xF1, 0xE0, 0x00, 0x00,
  0x0C, 0x07, 0x8F, 0x00, 0x1F, 0xF8, 0x00, 0x00, 0x01, 0xEF, 0x3C, 0x3D, 0xE1, 0xE0, 0x00, 0x00,
  0x00, 0x03, 0x87, 0x00, 0x0F, 0xB8, 0x00, 0x00, 0x03, 0xEF, 0x7C, 0x3F, 0xC1, 0xE0, 0x00, 0x00,
  0x00, 0x03, 0x87, 0x00, 0x0F, 0x18, 0x00, 0x00, 0x03, 0xCE, 0x78, 0x3F, 0xC1, 0xE0, 0x20, 0x00,
  0x00, 0x03, 0x83, 0x80, 0x06, 0x1C, 0x00, 0x00, 0x03, 0xC0, 0x78, 0x1F, 0x81, 0xF0, 0xE0, 0x00,
  0x00, 0x03, 0x81, 0x80, 0x00, 0x1C, 0x00, 0x00, 0x03, 0xC0, 0x78, 0x1F, 0x80, 0xFF, 0xC0, 0x00,
  0x00, 0x03, 0x81, 0xC0, 0x00, 0x1E, 0x00, 0x00, 0x07, 0xC0, 0xF8, 0x1F, 0x00, 0x7F, 0xC0, 0x00,
  0x00, 0x03, 0x81, 0xF8, 0x00, 0x0F, 0x80, 0x00, 0x07, 0x80, 0xF0, 0x1F, 0x00, 0x3F, 0x00, 0x00,
  0x00, 0x07, 0x80, 0xFC, 0x00, 0x1F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x03, 0xC0, 0xD0, 0x00, 0x07, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x03, 0xE0, 0x00, 0x00, 0x03, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x03, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x08, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x3F, 0x1C, 0xD3, 0x92, 0x72, 0x64, 0x7B, 0xF1, 0xCA, 0x0E, 0x39, 0xF8, 0x00, 0x00,
  0x00, 0x00, 0x24, 0x82, 0x94, 0x52, 0x8A, 0xA4, 0x8A, 0x48, 0x2A, 0x11, 0x45, 0x24, 0x00, 0x00,
  0x00, 0x00, 0x24, 0x9E, 0x94, 0x52, 0x82, 0xA4, 0x8A, 0x49, 0xEA, 0x10, 0x45, 0x24, 0x00, 0x00,
  0x00, 0x00, 0x24, 0xA2, 0x94, 0x4C, 0x8A, 0x58, 0x8A, 0x4A, 0x2A, 0x11, 0x45, 0x24, 0x00, 0x00,
  0x00, 0x00, 0x24, 0x9E, 0x93, 0x8C, 0x71, 0x00, 0x7A, 0x49, 0xEA, 0x8E, 0x39, 0x24, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  display.drawBitmap(0, 0,  logoMVC, SSD1306_LCDWIDTH, SSD1306_LCDHEIGHT, WHITE);
  display.display();
  delay(3000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  inString = "";
  time2 = millis();
  segundo = millis() / 1000;
  minuto = segundo / 60;
  hora = minuto / 60;
  minutot = minuto - (hora * 60);
  segundot = segundo - (minuto * 60);
  inString += hora;
  inString += ":";
  inString += minutot;
  inString += ":";
  inString += segundot;
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Test SSD1306 SPI");
  display.setCursor(0, 16);
  display.print(millis());
  display.setTextSize(2);
  display.setCursor(0, 32);
  display.print(inString);

  display.display();
  delay(100);
  display.clearDisplay();
}
