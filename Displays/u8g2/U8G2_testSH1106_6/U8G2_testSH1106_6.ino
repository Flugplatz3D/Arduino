#include <U8g2lib.h>
#include <Wire.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
//U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

int frame = 0, c = 38, r = 12, gap = 0;
unsigned long parcial;
//#define LED 13
#define LED PB1

#define image_01411_width 48
#define image_01411_height 48
static const unsigned char image_01411_bits[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xfe, 0x1d, 0x00, 0x00, 0x00, 0x00, 0x02, 0x3e, 0x00, 0x00,
  0x00, 0x00, 0x02, 0x64, 0x00, 0x00, 0x00, 0x00, 0x06, 0x44, 0x00, 0x00,
  0x00, 0x00, 0x06, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xc0, 0x01, 0x00,
  0x00, 0x00, 0x0c, 0x80, 0x01, 0x00, 0x00, 0x00, 0x08, 0x00, 0x01, 0x00,
  0x00, 0x00, 0x18, 0x80, 0x01, 0x00, 0x00, 0x00, 0x10, 0x80, 0x01, 0x00,
  0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x00, 0x00, 0x30, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x30, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x20, 0x40, 0x00, 0x00,
  0x00, 0x00, 0x20, 0x60, 0xc0, 0x00, 0x00, 0x00, 0x60, 0x20, 0xc0, 0x00,
  0x00, 0x00, 0x30, 0x30, 0xe0, 0x01, 0x00, 0x00, 0x60, 0x18, 0xa0, 0x01,
  0x00, 0x00, 0x30, 0x18, 0xb0, 0x07, 0x00, 0xfa, 0x61, 0x3c, 0x18, 0x06,
  0x00, 0x8e, 0x73, 0xfe, 0x0c, 0x06, 0x00, 0x03, 0x27, 0xde, 0x8d, 0x03,
  0x80, 0x31, 0x3e, 0x02, 0xe7, 0x00, 0xc0, 0x39, 0x1c, 0x00, 0x36, 0x00,
  0xf0, 0x00, 0x00, 0x00, 0x18, 0x00, 0x98, 0x00, 0x00, 0x00, 0x18, 0x00,
  0xf8, 0x00, 0x00, 0x00, 0x08, 0x00, 0xe0, 0x01, 0x1c, 0x00, 0x08, 0x00,
  0x80, 0x01, 0x1f, 0x00, 0x0c, 0x00, 0x00, 0x07, 0x73, 0x00, 0x7b, 0x08,
  0x00, 0xfe, 0xe3, 0xd7, 0xe3, 0x0d, 0x00, 0x50, 0x00, 0xfe, 0x00, 0x1f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#define image_01412_width 48
#define image_01412_height 48
static const unsigned char image_01412_bits[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0x00, 0x80, 0xe1, 0x07, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x03, 0x38, 0x00,
  0x00, 0x00, 0x00, 0x03, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x01, 0x30, 0x00,
  0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x03, 0x30, 0x00,
  0x00, 0x00, 0x00, 0x03, 0x30, 0x00, 0x00, 0x00, 0x00, 0x03, 0x18, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x18, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0c, 0x00,
  0x00, 0x00, 0x00, 0x03, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc2, 0x01,
  0x00, 0x00, 0x00, 0x01, 0xc3, 0x01, 0x00, 0x00, 0x80, 0x81, 0xc1, 0x01,
  0x00, 0x00, 0x80, 0x81, 0x61, 0x01, 0x00, 0x00, 0x80, 0xc0, 0x20, 0x07,
  0x00, 0x78, 0xc0, 0x40, 0x30, 0x0e, 0x00, 0xf7, 0xc1, 0x30, 0x18, 0x0c,
  0x80, 0x81, 0xc1, 0xf0, 0x0d, 0x0c, 0x80, 0x09, 0x43, 0x1c, 0x0f, 0x07,
  0x80, 0x39, 0x6e, 0x0c, 0xe2, 0x01, 0x80, 0x19, 0x0c, 0x04, 0x70, 0x00,
  0xe0, 0x01, 0x00, 0x00, 0x10, 0x00, 0xb8, 0x00, 0x00, 0x00, 0x10, 0x00,
  0xd8, 0x01, 0x00, 0x00, 0x18, 0x00, 0xf0, 0x01, 0x1e, 0x00, 0x1c, 0x00,
  0x80, 0x01, 0x3f, 0x00, 0x1c, 0x08, 0x00, 0x83, 0x71, 0x00, 0x3e, 0x18,
  0x00, 0xfe, 0xc1, 0x80, 0xf3, 0x08, 0x00, 0x78, 0x80, 0xff, 0x81, 0x1f,
  0x00, 0x00, 0x00, 0x2d, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#define image_01413_width 48
#define image_01413_height 48
static const unsigned char image_01413_bits[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x40, 0x01, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x7f, 0x00, 0x00,
  0x80, 0x0e, 0x7e, 0xc1, 0x03, 0x00, 0xe0, 0xbf, 0x0f, 0x00, 0x0f, 0x00,
  0x70, 0xf0, 0x01, 0x00, 0xfe, 0x0b, 0x18, 0xe1, 0x00, 0x00, 0x40, 0x7f,
  0x98, 0x41, 0x00, 0x00, 0x00, 0x3c, 0x98, 0x01, 0x10, 0x00, 0x10, 0x38,
  0x88, 0x00, 0x18, 0x08, 0xf8, 0x38, 0x1c, 0x00, 0x0c, 0x18, 0xd8, 0x33,
  0x1c, 0x80, 0x0d, 0x10, 0x0c, 0x2f, 0x1e, 0x80, 0x05, 0x18, 0x0e, 0x3c,
  0x3e, 0xc0, 0x03, 0xd0, 0x3f, 0x00, 0xf0, 0xc1, 0x01, 0xf8, 0x32, 0x00,
  0x40, 0xff, 0x00, 0x18, 0xe0, 0x00, 0x00, 0x60, 0x00, 0x08, 0xc0, 0x00,
  0x00, 0x38, 0x00, 0x08, 0x80, 0x03, 0x00, 0x0f, 0x00, 0x08, 0x00, 0x0f,
  0x80, 0x01, 0x00, 0x08, 0x00, 0x1e, 0x80, 0x01, 0x00, 0x08, 0x00, 0x1a,
  0x80, 0x03, 0x00, 0x0c, 0x00, 0x16, 0x00, 0x07, 0x00, 0x04, 0x00, 0x02,
  0x00, 0xbc, 0x00, 0x04, 0x00, 0x00, 0x00, 0xf0, 0x0b, 0x02, 0x00, 0x00,
  0x00, 0xc0, 0x3f, 0x03, 0x00, 0x00, 0x00, 0x00, 0xf4, 0x01, 0x00, 0x00,
  0x00, 0x00, 0xe0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#define image_01414_width 48
#define image_01414_height 48
static const unsigned char image_01414_bits[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xd4, 0x7f, 0x01, 0x00, 0x00, 0x00, 0xff, 0xa2, 0x07, 0x00,
  0xc0, 0xdf, 0x03, 0x00, 0x7e, 0x00, 0x60, 0xf8, 0x00, 0x00, 0xfc, 0x1f,
  0x20, 0x23, 0x00, 0x00, 0x00, 0x7a, 0x30, 0x07, 0x10, 0x00, 0x00, 0x38,
  0x18, 0x03, 0x10, 0x00, 0x70, 0x18, 0x18, 0x00, 0x18, 0x00, 0xf8, 0x11,
  0x18, 0x00, 0x1f, 0x00, 0x0e, 0x37, 0x1c, 0x80, 0x0e, 0x10, 0x0e, 0x3e,
  0x3e, 0xc0, 0x07, 0x10, 0x1f, 0x78, 0x7e, 0xe0, 0x03, 0x90, 0x73, 0x00,
  0x70, 0xf8, 0x00, 0xf8, 0x61, 0x00, 0xc0, 0x3f, 0x00, 0xf8, 0xc0, 0x01,
  0xc0, 0x07, 0x00, 0x08, 0x00, 0x07, 0xc0, 0x01, 0x00, 0x0c, 0x00, 0x3e,
  0x30, 0x00, 0x00, 0x0c, 0x00, 0x1e, 0xf0, 0x07, 0x00, 0x06, 0x00, 0x3c,
  0xc0, 0x0f, 0x00, 0x06, 0x00, 0x24, 0x00, 0x07, 0x00, 0x02, 0x00, 0x00,
  0x00, 0x0e, 0x00, 0x03, 0x00, 0x00, 0x00, 0xf8, 0x80, 0x01, 0x00, 0x00,
  0x00, 0xe0, 0xc0, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xf3, 0x00, 0x00, 0x00,
  0x00, 0x80, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#define image_01415_width 48
#define image_01415_height 48
static const unsigned char image_01415_bits[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x40, 0x01, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x7f, 0x00, 0x00,
  0x80, 0x0e, 0x7e, 0xc1, 0x03, 0x00, 0xe0, 0xbf, 0x0f, 0x00, 0x0f, 0x00,
  0x70, 0xf0, 0x01, 0x00, 0xfe, 0x0b, 0x18, 0xe1, 0x00, 0x00, 0x40, 0x7f,
  0x98, 0x41, 0x00, 0x00, 0x00, 0x3c, 0x98, 0x01, 0x10, 0x00, 0x10, 0x38,
  0x88, 0x00, 0x18, 0x08, 0xf8, 0x38, 0x1c, 0x00, 0x0c, 0x18, 0xd8, 0x33,
  0x1c, 0x80, 0x0d, 0x10, 0x0c, 0x2f, 0x1e, 0x80, 0x05, 0x18, 0x0e, 0x3c,
  0x3e, 0xc0, 0x03, 0xd0, 0x3f, 0x00, 0xf0, 0xc1, 0x01, 0xf8, 0x32, 0x00,
  0x40, 0xff, 0x00, 0x18, 0xe0, 0x00, 0x00, 0x60, 0x00, 0x08, 0xc0, 0x00,
  0x00, 0x38, 0x00, 0x08, 0x80, 0x03, 0x00, 0x0f, 0x00, 0x08, 0x00, 0x0f,
  0x80, 0x01, 0x00, 0x08, 0x00, 0x1e, 0x80, 0x01, 0x00, 0x08, 0x00, 0x1a,
  0x80, 0x03, 0x00, 0x0c, 0x00, 0x16, 0x00, 0x07, 0x00, 0x04, 0x00, 0x02,
  0x00, 0xbc, 0x00, 0x04, 0x00, 0x00, 0x00, 0xf0, 0x0b, 0x02, 0x00, 0x00,
  0x00, 0xc0, 0x3f, 0x03, 0x00, 0x00, 0x00, 0x00, 0xf4, 0x01, 0x00, 0x00,
  0x00, 0x00, 0xe0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#define image_01416_width 48
#define image_01416_height 48
static const unsigned char image_01416_bits[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0x00, 0x80, 0xe1, 0x07, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x03, 0x38, 0x00,
  0x00, 0x00, 0x00, 0x03, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x01, 0x30, 0x00,
  0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x03, 0x30, 0x00,
  0x00, 0x00, 0x00, 0x03, 0x30, 0x00, 0x00, 0x00, 0x00, 0x03, 0x18, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x18, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0c, 0x00,
  0x00, 0x00, 0x00, 0x03, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc2, 0x01,
  0x00, 0x00, 0x00, 0x01, 0xc3, 0x01, 0x00, 0x00, 0x80, 0x81, 0xc1, 0x01,
  0x00, 0x00, 0x80, 0x81, 0x61, 0x01, 0x00, 0x00, 0x80, 0xc0, 0x20, 0x07,
  0x00, 0x78, 0xc0, 0x40, 0x30, 0x0e, 0x00, 0xf7, 0xc1, 0x30, 0x18, 0x0c,
  0x80, 0x81, 0xc1, 0xf0, 0x0d, 0x0c, 0x80, 0x09, 0x43, 0x1c, 0x0f, 0x07,
  0x80, 0x39, 0x6e, 0x0c, 0xe2, 0x01, 0x80, 0x19, 0x0c, 0x04, 0x70, 0x00,
  0xe0, 0x01, 0x00, 0x00, 0x10, 0x00, 0xb8, 0x00, 0x00, 0x00, 0x10, 0x00,
  0xd8, 0x01, 0x00, 0x00, 0x18, 0x00, 0xf0, 0x01, 0x1e, 0x00, 0x1c, 0x00,
  0x80, 0x01, 0x3f, 0x00, 0x1c, 0x08, 0x00, 0x83, 0x71, 0x00, 0x3e, 0x18,
  0x00, 0xfe, 0xc1, 0x80, 0xf3, 0x08, 0x00, 0x78, 0x80, 0xff, 0x81, 0x1f,
  0x00, 0x00, 0x00, 0x2d, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void setup() {
  pinMode(LED, OUTPUT);
  u8g2.begin();
  u8g2.setFontRefHeightExtendedText();
  u8g2.setDrawColor(1);
  u8g2.setFontPosTop();
  u8g2.setFontDirection(0);
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_BBSesque_tf);
  u8g2.drawStr(0, 0, "U8g2lib SH1106");
  //  u8g2.drawStr(0, 0, "U8g2lib SSD1306");
  u8g2.setFont(u8g2_font_HelvetiPixel_tr);
  u8g2.sendBuffer();
  delay(2000);
  parcial = millis();
}

void loop() {
  u8g2.firstPage();
  do {
    draw();
  } while (u8g2.nextPage());
  frame ++;
  if (frame > 5)
  {
    frame = 0;
    digitalWrite(LED, !digitalRead(LED));
  }
  gap = millis() - parcial;
  parcial = millis();
  delay(55);
}

void draw()
{
  switch (frame)
  {
    case 0:
      {
        u8g2.setCursor(0, 0);
        u8g2.print(gap, DEC);
        u8g2.drawXBMP(c, r, image_01411_width, image_01411_height, image_01411_bits);
        break;
      }
    case 1:
      {
        u8g2.setCursor(0, 0);
        u8g2.print(gap, DEC);
        u8g2.drawXBMP(c, r, image_01412_width, image_01412_height, image_01412_bits);
        break;
      }
    case 2:
      {
        u8g2.setCursor(0, 0);
        u8g2.print(gap, DEC);
        u8g2.drawXBMP(c, r, image_01413_width, image_01413_height, image_01413_bits);
        break;
      }
    case 3:
      {
        u8g2.setCursor(0, 0);
        u8g2.print(gap, DEC);
        u8g2.drawXBMP(c, r, image_01414_width, image_01414_height, image_01414_bits);
        break;
      }
    case 4:
      {
        u8g2.setCursor(0, 0);
        u8g2.print(gap, DEC);
        u8g2.drawXBMP(c, r, image_01415_width, image_01415_height, image_01415_bits);
        break;
      }
    case 5:
      {
        u8g2.setCursor(0, 0);
        u8g2.print(gap, DEC);
        u8g2.drawXBMP(c, r, image_01416_width, image_01416_height, image_01416_bits);
        break;
      }
  }
}
