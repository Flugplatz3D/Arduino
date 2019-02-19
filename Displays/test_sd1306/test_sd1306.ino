#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup()   {
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(16, 12);
  display.print("SSD1306");
  display.display();
  delay(3000);
  display.clearDisplay();
  display.setTextSize(1);
  display.display();
}

void loop() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print(millis());
  display.display();
  //delay(100);
}
