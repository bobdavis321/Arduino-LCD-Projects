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

int Sample[128];
int Input=0;
int OldInput=0;

void u8g_prepare(void) {
  u8g.setFont(u8g_font_6x10);
  u8g.setFontRefHeightExtendedText();
  u8g.setDefaultForegroundColor();
  u8g.setFontPosTop();
}
void DrawMarkers(void) {
  u8g.drawFrame (0,0,128,64);
  u8g.drawPixel (22,11);
  u8g.drawPixel (43,11);
  u8g.drawPixel (64,11);
  u8g.drawPixel (85,11);
  u8g.drawPixel (106,11);
  u8g.drawPixel (22,22);
  u8g.drawPixel (43,22);
  u8g.drawPixel (64,22);
  u8g.drawPixel (85,22);
  u8g.drawPixel (106,22);
  u8g.drawPixel (22,32);
  u8g.drawPixel (43,32);
  u8g.drawPixel (64,32);
  u8g.drawPixel (85,32);
  u8g.drawPixel (106,32);
  u8g.drawPixel (22,43);
  u8g.drawPixel (43,43);
  u8g.drawPixel (64,43);
  u8g.drawPixel (85,43);
  u8g.drawPixel (106,43);
  u8g.drawPixel (22,53);
  u8g.drawPixel (43,53);
  u8g.drawPixel (64,53);
  u8g.drawPixel (85,53);
  u8g.drawPixel (106,53);
}

void draw(void) {
  u8g_prepare();
  DrawMarkers(); 
// wait for a trigger of a positive going input
//  OldInput=analogRead(A0);
//  Input=analogRead(A0);
  while (Input < OldInput){
    OldInput=analogRead(A0);
    Input=analogRead(A0);
  }
// collect the analog data into an array
// do not do division by 10.24 here, it makes it slower!
  for(int xpos=0; xpos<128; xpos++) {
    Sample[xpos]=analogRead(A0);
  } 
// display the collected analog data from array
// Sample/10.24 because 1024 becomes 100 = 5 volts
  for(int xpos=1; xpos<128; xpos++) {
    u8g.drawLine (xpos, Sample[xpos]/10.24, xpos+1, Sample[xpos+1]/10.24);
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


