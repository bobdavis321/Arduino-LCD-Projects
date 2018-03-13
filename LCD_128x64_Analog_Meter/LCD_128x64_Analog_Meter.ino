/*********************************
128 by 64 Analog Meter
By Bob Davis
Uses Universal 8bit Graphics Library, http://code.google.com/p/u8glib/
  Copyright (c) 2012, olikraus@gmail.com All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:
  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.

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
***************************************************/
#include "U8glib.h"
// 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, di=17, rw=16
U8GLIB_ST7920_128X64_4X u8g(8, 9, 10, 11, 4, 5, 6, 7, 18, 17, 16);  

void u8g_prepare(void) {
  u8g.setFont(u8g_font_6x10);
  u8g.setFontRefHeightExtendedText();
  u8g.setDefaultForegroundColor();
  u8g.setFontPosTop();
}

void setup(void) {
  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) 
    u8g.setColorIndex(255);     // white
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT )
    u8g.setColorIndex(3);         // max intensity
  else if ( u8g.getMode() == U8G_MODE_BW )
    u8g.setColorIndex(1);         // pixel on
//  pinMode(13, OUTPUT);           
//  digitalWrite(13, HIGH);  
}

void loop(void) {
  int  Analog0 = analogRead(A0)/2.05;
  u8g.drawLine(42, 48, Analog0, 0);

//  nokia.drawstring(0, 0, "Analog 0");
//  int analog0 = analogRead(A0)/2.05;
//  nokia.drawstring(64, 0, itoa(analog0, buf, 10));
// nokia.drawline(x1, y1, x2, y2, color); 
//  nokia.drawline(42, 48, analog0/5, 0, BLACK);    

  delay(100);

}


