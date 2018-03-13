/***********************************
128 by 64 LCD Oscilloscope
By Bob Davis
Uses Universal 8bit Graphics Library, http://code.google.com/p/u8glib/
  
  Copyright (c) 2012, olikraus@gmail.com
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

********************************************/
#include "U8glib.h"

// 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, di=17,rw=16
U8GLIB_ST7920_128X64_4X u8g(8, 9, 10, 11, 4, 5, 6, 7, 18, 17, 16);   

void u8g_prepare(void) {
  u8g.setFont(u8g_font_6x10);
  u8g.setFontRefHeightExtendedText();
  u8g.setDefaultForegroundColor();
  u8g.setFontPosTop();
}

//uint8_t draw_state = 0;
void draw(void) {
// Draw border marker lines
  u8g_prepare();
  u8g.drawLine (0,0,128,0);
  u8g.drawLine (0,0,0,5);
  u8g.drawLine (22,0,22,5);
  u8g.drawLine (43,0,43,5);
  u8g.drawLine (64,0,64,5);
  u8g.drawLine (85,0,85,5);
  u8g.drawLine (106,0,106,5);
  u8g.drawLine (0,63,128,63);
  u8g.drawLine (22,63,22,58);
  u8g.drawLine (43,63,43,58);
  u8g.drawLine (64,63,64,58);
  u8g.drawLine (85,63,85,58);
  u8g.drawLine (106,63,106,58);
  u8g.drawLine (0,0,0,64);
  u8g.drawLine (0,11,5,11);
  u8g.drawLine (0,21,5,21);
  u8g.drawLine (0,32,5,32);
  u8g.drawLine (0,42,5,42);
  u8g.drawLine (0,53,5,53);
  u8g.drawLine (127,0,127,64);
  u8g.drawLine (123,11,127,11);
  u8g.drawLine (123,21,127,21);
  u8g.drawLine (123,32,127,32);
  u8g.drawLine (123,42,127,42);
  u8g.drawLine (123,53,127,53);
  u8g.drawLine (123,63,127,63);
  
// analogRead(A0)/10.24 because 1024 becomes 100 = 5 volts
//  if (analogRead(A0)/10.24 > 50){  // wait for trigger
    for(int xpos=0; xpos<128; xpos++) {
    u8g.drawPixel(xpos, analogRead(A0)/10.24);
    u8g.drawPixel(xpos, analogRead(A1)/10.24);
//    }
  }  
}

void setup(void) {
  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) 
    u8g.setColorIndex(255);     // RGB=white
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT )
    u8g.setColorIndex(3);       // max intensity
  else if ( u8g.getMode() == U8G_MODE_BW )
    u8g.setColorIndex(1);       // pixel on, black
}

void loop(void) {
  // picture loop  
  u8g.firstPage();  
  do { draw(); }  
  while( u8g.nextPage() );
  // rebuild the picture after some delay
  delay(100);
}


