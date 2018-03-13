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
 nokia.drawstring(0, 0, "Analog 0");
 char buf[14];
 int analog0 = analogRead(A0)/2.05;
 nokia.drawstring(64, 0, itoa(analog0, buf, 10));
 nokia.drawstring(0, 8, "Analog 1");
 int analog1 = analogRead(A1)/2.05;
 nokia.drawstring(64, 8, itoa(analog1, buf, 10));
 nokia.drawstring(0, 16, "Analog 2");
 int analog2 = analogRead(A2)/2.05;
 nokia.drawstring(64, 16, itoa(analog2, buf, 10));
 nokia.drawstring(0, 24, "Analog 3");
 int analog3 = analogRead(A3)/2.05;
 nokia.drawstring(64, 24, itoa(analog3, buf, 10));
 nokia.drawstring(0, 32, "Analog 4");
 int analog4 = analogRead(A4)/2.05;
 nokia.drawstring(64, 32, itoa(analog4, buf, 10));
 nokia.drawstring(0, 40, "Analog 5");
 int analog5 = analogRead(A5)/2.05;
 nokia.drawstring(64, 40, itoa(analog5, buf, 10));

 //Now push the buffer to the LCD for display
 nokia.display(); 
} 

