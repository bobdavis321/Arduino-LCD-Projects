/********************************************* 
  Title:       Simple Arduino Oscilloscope
  Purpose:     Use a Nokia LCD screen with the arduino UNO
  Created by:  Fileark see Fileark.com, Edited by Bob Davis
  Note:        This code uses the Adafruit PDC8544 LCD library  
********************************************/
#include "PCD8544.h"
PCD8544 nokia = PCD8544(7,6,5,3,4); 

void setup(void) {
  nokia.init();
}

void loop() {  
  int samplerate = analogRead(A5)/10;  // range of 0 to 100
  nokia.clear();         // clear the LCD 
  for(int ypos = 0; ypos < 85; ypos++){   // fill screen left to right
    nokia.setPixel(ypos, analogRead(A0)/20.5, BLACK); // 5V=full scale
    delay (samplerate);    }     // delay for sampling rate  
  nokia.display();       // show the data
} 



