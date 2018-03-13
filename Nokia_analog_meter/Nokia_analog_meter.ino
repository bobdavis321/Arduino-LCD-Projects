/********************************************* 
  Title:       Nokia Analog Meter
  Purpose:     Use a Nokia LCD screen with the arduino UNO
  Created by:  Bob Davis
  Note:        This code uses the Adafruit PDC8544 LCD library  
********************************************/
#include "PCD8544.h"

//Define the pins you are connecting the LCD too. 
//PCD8544(SCLK, DIN/MOSI, D/C, SCE/CS, RST); 
PCD8544 nokia = PCD8544(7,6,5,3,4); 

void setup(void)
{
  nokia.init(); //Initialize lcd
  // set display to normal mode
  nokia.command(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL);
}

void loop(void)
{
  char buf[12]; 
  nokia.clear(); //clears the display
  // Write a string to the LCD buffer using this format. 
  // nokia.drawstring(x, y, "string"); x = 0-84, y = 0-48
  nokia.drawstring(0, 0, "Analog 0");
  int analog0 = analogRead(A0)/2.05;
  nokia.drawstring(64, 0, itoa(analog0, buf, 10));
  // nokia.drawline(x1, y1, x2, y2, color); 
  nokia.drawline(42, 48, analog0/5, 0, BLACK);    
  //Now push the buffer to the LCD for display
  nokia.display(); 
}

