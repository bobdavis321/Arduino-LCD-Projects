/*
 * KS0108 Oscilloscope
 *
 */

#include <ks0108.h>
#include "Arial14.h"         // proportional font
#include "SystemFont5x7.h"   // system font
#include "ArduinoIcon.h"     // bitmap 

int Sample[128];
int Input=0;
int OldInput=0;

void setup(void) {
//  delay(500);                // allow time for LCD to reset
  GLCD.Init(NON_INVERTED);   // initialise the library, non inverted writes pixels onto a clear screen
// GLCD.ClearScreen();  
  GLCD.SelectFont(System5x7); // switch to fixed width system font 
}

void loop(void) {
//  DrawMarkers(); 
// wait for a trigger of a positive going input
  OldInput=analogRead(A5);
  Input=analogRead(A5);
  while (Input < OldInput){
    Input=analogRead(A5);
  }
// collect the analog data into an array
// do not do division by 10.24 here, it makes it slower!
  for(int xpos=0; xpos<128; xpos++) {
    Sample[xpos]=analogRead(A5);
  } 
// display the collected analog data from array
// Sample/10.24 because 1024 becomes 100 = 5 volts
  for(int xpos=1; xpos<127; xpos++) {
    GLCD.DrawLine(xpos,Sample[xpos],xpos+1,Sample[xpos+1],BLACK); 
  }  
  delay(100);
  GLCD.ClearScreen();               // clear the screen  
}


