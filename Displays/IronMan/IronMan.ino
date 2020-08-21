/*
 Filename : ironman.ino
 Author   : Sandhan Sarma <sandhansmailbox@gmail.com>
 
  ironman.ino

  Universal 8bit Graphics Library (https://github.com/olikraus/u8g2/)

  Copyright (c) 2016, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  

*/

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

//U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// Copy the contents of your .xbm file below
#define ironman_width 44
#define ironman_height 64
static const unsigned char ironman_bits[] PROGMEM = {
   0x00, 0x00, 0xfc, 0x03, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x3f, 0x00, 0x00,
   0x00, 0xf8, 0xff, 0xff, 0x01, 0x00, 0x00, 0x86, 0xff, 0x1f, 0x06, 0x00,
   0x80, 0x81, 0xff, 0x1f, 0x18, 0x00, 0xc0, 0x80, 0xff, 0x1f, 0x30, 0x00,
   0x20, 0x80, 0xff, 0x1f, 0xc0, 0x00, 0x10, 0x00, 0xff, 0x0f, 0x80, 0x01,
   0x08, 0x00, 0xff, 0x0f, 0x00, 0x01, 0x08, 0x00, 0xff, 0x0f, 0x00, 0x02,
   0x08, 0x00, 0xff, 0x0f, 0x00, 0x02, 0x08, 0x00, 0xfe, 0x07, 0x00, 0x02,
   0x08, 0x00, 0xfe, 0x07, 0x00, 0x02, 0x08, 0x00, 0xfe, 0x07, 0x00, 0x02,
   0x08, 0x00, 0x00, 0x00, 0x00, 0x06, 0x08, 0x00, 0x00, 0x00, 0x00, 0x06,
   0x08, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x06,
   0x0c, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x06,
   0x0c, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x06,
   0x0c, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x06,
   0x06, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x06,
   0x06, 0x00, 0x00, 0x00, 0x00, 0x0e, 0xc6, 0x07, 0x00, 0x00, 0x7c, 0x0e,
   0xe6, 0xff, 0xff, 0xff, 0xff, 0x0e, 0xe6, 0xff, 0x03, 0xf8, 0xff, 0x0c,
   0x02, 0x3f, 0x00, 0x80, 0x1f, 0x0c, 0x02, 0x00, 0x00, 0x00, 0x00, 0x0c,
   0x03, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x0c,
   0x03, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x0c,
   0x03, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x07, 0x00, 0x00, 0x00, 0x00, 0x06,
   0x07, 0x00, 0x00, 0x00, 0x00, 0x06, 0x16, 0x00, 0x00, 0x00, 0x00, 0x06,
   0x2e, 0x00, 0x00, 0x00, 0x80, 0x07, 0x6e, 0x00, 0x00, 0x00, 0x40, 0x07,
   0x6e, 0x00, 0x00, 0x00, 0x60, 0x07, 0xde, 0x00, 0x00, 0x00, 0xb0, 0x07,
   0xde, 0x00, 0x00, 0x00, 0xb0, 0x07, 0x9c, 0x01, 0x00, 0x00, 0xd8, 0x03,
   0xbc, 0x01, 0x00, 0x00, 0xf8, 0x03, 0x3c, 0x01, 0x00, 0x00, 0xe8, 0x03,
   0x7c, 0x03, 0x00, 0x00, 0xf4, 0x03, 0xfc, 0x02, 0x00, 0x00, 0xf4, 0x03,
   0xfc, 0xc2, 0xff, 0x1f, 0xfa, 0x03, 0xf8, 0x25, 0xff, 0x27, 0xfa, 0x01,
   0xf8, 0x38, 0x00, 0x60, 0xf9, 0x01, 0xf8, 0x10, 0x00, 0xc0, 0xf8, 0x01,
   0xf0, 0x00, 0x00, 0x00, 0xf8, 0x01, 0xf0, 0x00, 0x00, 0x00, 0xf8, 0x01,
   0xf0, 0x00, 0xf8, 0x00, 0xf8, 0x00, 0xe0, 0xc1, 0xff, 0x0f, 0xf8, 0x00,
   0xc0, 0xe3, 0xff, 0x1f, 0x7c, 0x00, 0x80, 0xff, 0xff, 0x7f, 0x3e, 0x00,
   0x00, 0xff, 0xff, 0x7f, 0x0f, 0x00, 0x00, 0xf6, 0x00, 0xfe, 0x07, 0x00,
   0x00, 0x3c, 0x00, 0xb0, 0x01, 0x00, 0x00, 0x08, 0x00, 0x40, 0x00, 0x00 };

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g2.drawXBMP( 42, 0, ironman_width, ironman_height, ironman_bits);
}

void setup(void) {
  u8g2.begin();
}

void loop(void) {
  // picture loop
  u8g2.firstPage();  
  do {
    draw();
  } while( u8g2.nextPage() );

  // rebuild the picture after some delay
  delay(1000);
}
