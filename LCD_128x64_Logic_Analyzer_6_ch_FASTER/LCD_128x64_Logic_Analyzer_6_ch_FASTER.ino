/***********************************
128 by 64 LCD Logic Analyzer 6 channel and 3Mb/s
By Bob Davis
Uses Universal 8bit Graphics Library, http://code.google.com/p/u8glib/
  Copyright (c) 2012, olikraus@gmail.com   All rights reserved.

********************************************/
#include "U8glib.h"

// 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, di=17,rw=16
//U8GLIB_ST7920_128X64_4X u8g(8, 9, 10, 11, 4, 5, 6, 7, 18, 17, 16); 
//  **** NOTE **** I Moved the three control pins !!!
U8GLIB_ST7920_128X64_4X u8g(8, 9, 10, 11, 4, 5, 6, 7, 1, 2, 3); 

byte Sample[128];
int Input=0;
int OldInput=0;
int xpos=0;
 
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
// No loop is about 50% faster!
    Sample[1]=PINC;    Sample[2]=PINC;    Sample[3]=PINC;
    Sample[4]=PINC;    Sample[5]=PINC;    Sample[6]=PINC;
    Sample[7]=PINC;    Sample[8]=PINC;    Sample[9]=PINC;
    Sample[10]=PINC;   Sample[11]=PINC;    Sample[12]=PINC;
    Sample[13]=PINC;   Sample[14]=PINC;    Sample[15]=PINC;
    Sample[16]=PINC;   Sample[17]=PINC;    Sample[18]=PINC;
    Sample[19]=PINC;   Sample[20]=PINC;    Sample[21]=PINC;
    Sample[22]=PINC;   Sample[23]=PINC;    Sample[24]=PINC;
    Sample[25]=PINC;   Sample[26]=PINC;    Sample[27]=PINC;
    Sample[28]=PINC;    Sample[29]=PINC;    Sample[30]=PINC;
    Sample[31]=PINC;    Sample[32]=PINC;    Sample[33]=PINC;
    Sample[34]=PINC;    Sample[35]=PINC;    Sample[36]=PINC;
    Sample[37]=PINC;    Sample[38]=PINC;    Sample[39]=PINC;
    Sample[40]=PINC;    Sample[41]=PINC;    Sample[42]=PINC;
    Sample[43]=PINC;    Sample[44]=PINC;    Sample[45]=PINC;
    Sample[46]=PINC;    Sample[47]=PINC;    Sample[48]=PINC;
    Sample[49]=PINC;    Sample[50]=PINC;    Sample[51]=PINC;
    Sample[52]=PINC;    Sample[53]=PINC;    Sample[54]=PINC;
    Sample[55]=PINC;    Sample[56]=PINC;    Sample[57]=PINC;
    Sample[58]=PINC;    Sample[59]=PINC;    Sample[60]=PINC;
    Sample[61]=PINC;    Sample[62]=PINC;    Sample[63]=PINC;
    Sample[64]=PINC;    Sample[65]=PINC;    Sample[66]=PINC;
    Sample[67]=PINC;    Sample[68]=PINC;    Sample[69]=PINC;
    Sample[70]=PINC;    Sample[71]=PINC;    Sample[72]=PINC;
    Sample[73]=PINC;    Sample[74]=PINC;    Sample[75]=PINC;
    Sample[76]=PINC;    Sample[77]=PINC;    Sample[78]=PINC;
    Sample[79]=PINC;    Sample[80]=PINC;    Sample[81]=PINC;
    Sample[82]=PINC;    Sample[83]=PINC;    Sample[84]=PINC;
    Sample[85]=PINC;    Sample[86]=PINC;    Sample[87]=PINC;
    Sample[88]=PINC;    Sample[89]=PINC;    Sample[90]=PINC;
    Sample[91]=PINC;    Sample[92]=PINC;    Sample[93]=PINC;
    Sample[94]=PINC;    Sample[95]=PINC;    Sample[96]=PINC;
    Sample[97]=PINC;    Sample[98]=PINC;    Sample[99]=PINC;
    Sample[100]=PINC;    Sample[101]=PINC;    Sample[102]=PINC;
    Sample[103]=PINC;    Sample[104]=PINC;    Sample[105]=PINC;
    Sample[106]=PINC;    Sample[107]=PINC;    Sample[108]=PINC;
    Sample[109]=PINC;    Sample[110]=PINC;    Sample[111]=PINC;
    Sample[112]=PINC;    Sample[113]=PINC;    Sample[114]=PINC;
    Sample[115]=PINC;    Sample[116]=PINC;    Sample[117]=PINC;
    Sample[118]=PINC;    Sample[119]=PINC;    Sample[120]=PINC;
    Sample[121]=PINC;    Sample[122]=PINC;    Sample[123]=PINC;
    Sample[124]=PINC;    Sample[125]=PINC;    Sample[126]=PINC;
    Sample[127]=PINC;

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


