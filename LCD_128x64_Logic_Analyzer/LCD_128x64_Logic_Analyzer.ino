/***********************************
128 by 64 LCD Logic Analyzer
By Bob Davis
Uses Universal 8bit Graphics Library, http://code.google.com/p/u8glib/
  Copyright (c) 2012, olikraus@gmail.com   All rights reserved.

********************************************/
#include "U8glib.h"

// 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, di=17,rw=16
U8GLIB_ST7920_128X64_4X u8g(8, 9, 10, 11, 4, 5, 6, 7, 18, 17, 16); 

int Sample[128];
int Sample0[128];
int Sample1[128];
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
//  OldInput=digitalRead(A0);
  Input=digitalRead(A0);
  while (Input != 1){
    Input=digitalRead(A0);
  }
// collect the analog data into an array
  for(int xpos=0; xpos<128; xpos++) {
    Sample[xpos]=PINC;
  } 
// Process the data to get it ready to display
  for(int xpos=0; xpos<128; xpos++) {
    Sample0[xpos]=(((Sample[xpos]&B00000001)*8)+11);
    Sample1[xpos]=(((Sample[xpos]&B00000010)*4)+22);
  }  

// display the collected analog data from array
  for(int xpos=0; xpos<128; xpos++) {
    u8g.drawLine (xpos, Sample0[xpos], xpos+1, Sample0[xpos+1]);
    u8g.drawLine (xpos, Sample1[xpos], xpos+1, Sample1[xpos+1]);
  }  
}

void setup(void) {
  // assign default color value
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) 
    u8g.setColorIndex(255);     // RGB=white
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT )
    u8g.setColorIndex(3);       // max intensity
  else if ( u8g.getMode() == U8G_MODE_BW )
    u8g.setColorIndex(1);       // pixel on, black
}

void loop(void) {
// picture loop  
//  u8g.firstPage();  
  do { draw(); }  
  while( u8g.nextPage() );
  // rebuild the picture after some delay
  delay(100);
}


