#include "PCD8544.h"

//Define the pins you are connecting the LCD too. 
//PCD8544(SCLK, DIN/MOSI, D/C, SCE/CS, RST); 
PCD8544 nokia = PCD8544(7,6,5,3,4); 

void setup(void)
{
  nokia.init(); //Initialize lcd
  // set display to normal mode
  nokia.command(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL);
  nokia.clear(); //clears the display
}

void loop(void)
{
 // Write a string to the LCD buffer use this format. 
 // nokia.drawstring(x, y, "string"); x = 0-84, y = 0-48
 nokia.drawstring(0, 0, "Hi! This is   a Nokia LCD");
 nokia.drawstring(0, 16, "This is line 3");
 nokia.drawstring(0, 24, "This is line 4");
 nokia.drawstring(0, 32, "This is line 5");
 nokia.drawstring(0, 40, "This is line 6");
 
 //Now push the buffer to the LCD for display
 nokia.display(); 
} 

