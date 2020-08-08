#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
//U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

int i = 0;

void setup() {
  u8g2.begin();
  //u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setFont(u8g2_font_cu12_tr);
  u8g2.setFontRefHeightExtendedText();
  u8g2.setDrawColor(1);
  u8g2.setFontPosTop();
  u8g2.setFontDirection(0);
}

void loop() {
  u8g2.clearBuffer();
  u8g2.drawStr(0, 0, "U8g2lib SH1106");
  u8g2.setCursor(0, 20);
  u8g2.print(i);
  //u8g2.print(millis());
  u8g2.sendBuffer();
  i++;
  delay(25);
}
