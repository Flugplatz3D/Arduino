#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
//U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

int i = -16;

void setup() {
  u8g2.begin();
  u8g2.setFontRefHeightExtendedText();
  u8g2.setDrawColor(1);
  u8g2.setFontPosTop();
  u8g2.setFontDirection(0);
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_BBSesque_tf);
  //  u8g2.drawStr(0, 0, "NUCLEO-32");
  //  u8g2.drawStr(0, 16, "STM32F303K8");
  //  u8g2.drawStr(0, 32, "Test U8g2lib SH1106");
  u8g2.drawStr(0, 0, "Test U8g2lib SH1106");
  u8g2.setFont(u8g2_font_HelvetiPixel_tr);
  u8g2.sendBuffer();
  delay(3000);
}

void loop() {
  u8g2.clearBuffer();
  u8g2.setCursor(0, 0);
  u8g2.print(millis(), DEC);
  u8g2.drawCircle(i, 40, 16);
  u8g2.drawCircle(i, 40, 15);
  u8g2.drawCircle(i, 40, 14);
  //  u8g2.drawDisc(i, 40, 16);
  u8g2.sendBuffer();
  //  i++;
  i = i + 2;
  if (i > 144) i = -16;
  //delay(250);
}
