/***********************************
128 by 64 LCD Logic Analyzer 5 channel and 1.5Mb/s
By Bob Davis
Uses Universal 8bit Graphics Library, http://code.google.com/p/u8glib/
  Copyright (c) 2012, olikraus@gmail.com   All rights reserved.

********************************************/
#include "U8glib.h"

// 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, di=17,rw=16
//U8GLIB_ST7920_128X64_4X u8g(8, 9, 10, 11, 4, 5, 6, 7, 18, 17, 16); 
//  **** NOTE **** I Moved the three control pins !!!
U8GLIB_ST7920_128X64_4X u8g(8, 9, 10, 11, 4, 5, 6, 7, 1, 2, 3); 

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
  u8g.drawPixel (20,1);
  u8g.drawPixel (40,1);
  u8g.drawPixel (60,1);
  u8g.drawPixel (80,1);
  u8g.drawPixel (100,1);
  u8g.drawPixel (20,62);
  u8g.drawPixel (40,62);
  u8g.drawPixel (60,62);
  u8g.drawPixel (80,62);
  u8g.drawPixel (100,62);
}

void draw(void) {
  u8g_prepare();
  DrawMarkers(); 
// wait for a trigger of a positive going input
  Input=digitalRead(A0);
  while (Input != 1){
    Input=digitalRead(A0);
  }
// collect the analog data into an array
  for(int xpos=0; xpos<128; xpos++) {
    Sample[xpos]=PINC;
  } 

// display the collected analog data from array
  for(int xpos=0; xpos<128; xpos++) {
    u8g.drawLine (xpos, ((Sample[xpos]&B00000001)*4)+4, xpos, ((Sample[xpos+1]&B00000001)*4)+4);
    u8g.drawLine (xpos, ((Sample[xpos]&B00000010)*2)+14, xpos, ((Sample[xpos+1]&B00000010)*2)+14);
    u8g.drawLine (xpos, ((Sample[xpos]&B00000100)*1)+24, xpos, ((Sample[xpos+1]&B00000100)*1)+24);
    u8g.drawLine (xpos, ((Sample[xpos]&B00001000)/2)+34, xpos, ((Sample[xpos+1]&B00001000)/2)+34);
    u8g.drawLine (xpos, ((Sample[xpos]&B00010000)/4)+44, xpos, ((Sample[xpos+1]&B00010000)/4)+44);
    u8g.drawLine (xpos, ((Sample[xpos]&B00100000)/8)+54, xpos, ((Sample[xpos+1]&B00100000)/8)+54);
  }  
}

void setup(void) {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

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
//  u8g.firstPage();  
  do { draw(); }  
  while( u8g.nextPage() );
  // rebuild the picture after some delay
  delay(100);
}


