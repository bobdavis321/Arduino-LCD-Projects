// UTFT_ViewFont (C)2012 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// modified by John Boxall, April 2013

#include <UTFT.h>

// Declare which fonts we will be using
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

UTFT myGLCD(ILI9325C,19,18,17,16);  

void setup()
{
  myGLCD.InitLCD();
  myGLCD.clrScr();
}

void loop()
{
  myGLCD.setColor(255, 0, 0);
  myGLCD.setBackColor(0, 0, 0);

  myGLCD.setFont(BigFont);
  myGLCD.print(" !\"#$%&'()*+,-./", CENTER, 0);
  myGLCD.print("0123456789:;<=>?", CENTER, 16);
  myGLCD.print("@ABCDEFGHIJKLMNO", CENTER, 32);
  myGLCD.print("PQRSTUVWXYZ[\\]^_", CENTER, 48);
  myGLCD.print("`abcdefghijklmno", CENTER, 64);
  myGLCD.print("pqrstuvwxyz{|}~ ", CENTER, 80);

  myGLCD.setColor(0, 255, 0);

  myGLCD.setFont(SmallFont);
  myGLCD.print(" !\"#$%&'()*+,-./0123456789:;<=>?", CENTER, 120);
  myGLCD.print("@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_", CENTER, 132);
  myGLCD.print("`abcdefghijklmnopqrstuvwxyz{|}~ ", CENTER, 144);

  myGLCD.setColor(0, 0, 255);

  myGLCD.setFont(SevenSegNumFont);
  myGLCD.print("0123456789", CENTER, 190);
  while(1) {}; // do nothing
}


