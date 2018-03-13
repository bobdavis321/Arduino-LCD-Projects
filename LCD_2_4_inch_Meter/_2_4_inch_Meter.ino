//
// Three color analog meter simulation
// By Bob Davis
// UTFT_(C)2012 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//

#include <UTFT.h>

// Declare which fonts we will be using
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

UTFT myGLCD(ILI9325C,19,18,17,16);  
int Mv;
int OldMv;

void setup()
{
  myGLCD.InitLCD();
  myGLCD.clrScr();
}

void loop()
{
  // set color(Red, Green, Blue) range = 0 to 255
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setFont(BigFont);
  char buf[12]; 
  while(1) {
    // display millivolts in green text
    Mv=analogRead(A0)/2.05;
    myGLCD.setColor(0, 255, 0);
    myGLCD.print(itoa(Mv, buf, 10), 16, 200);
    // Turn old line red
    if (OldMv != Mv) {
      myGLCD.setColor(255, 0, 0);
      myGLCD.drawLine(160, 240, OldMv, 0);
    }
    // Draw new white line
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawLine(160, 240, Mv, 0);
    OldMv=Mv;  
  }; // do nothing
}


