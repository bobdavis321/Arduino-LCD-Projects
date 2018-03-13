/************************************
 1.8 TFT Oscope
 Reads the value of analog input on A0, 
 and shows the value on the screen.
 Created 15 January 2014 by Bob Davis
**************************************/

#include <TFT.h>  // Arduino LCD library
#include <SPI.h>
 
 // pin definition for the Uno
#define rst  8  
#define dc   9
#define cs   10

TFT TFTscreen = TFT(cs, dc, rst);

// set up variables
int xPos = 0;
int value = 0;
int maxvalue=100;
int minvalue=100;
int sensor[160];
char buf[12];

void setup(){
  // initialize the display
  TFTscreen.begin();
  // clear the screen 
  TFTscreen.background(0, 0, 0); 
  // Set the font size
  TFTscreen.setTextSize(2);
}

void loop(){
  // quickly collect the data
  for (int xpos = 0; xpos <160; xpos++){
  sensor[xpos] = analogRead(A0);
  }
  // determine the peak to peak voltage
  maxvalue=sensor[1];
  minvalue=sensor[1];
  for (int xpos = 0; xpos <160; xpos++){
  if (sensor[xpos] > maxvalue) maxvalue=sensor[xpos];
  if (sensor[xpos] < minvalue) minvalue=sensor[xpos];
  }
  value=maxvalue-minvalue;  
  // erase the screen to start again
  TFTscreen.background(0, 0, 0); 
  // display the collected data
  for (int xpos = 0; xpos <159; xpos++){
  // select the color = B,G,R
  TFTscreen.stroke(50, 50, 255);
  // draw the line (xPos1, yPos1, xPos2, yPos2);
  TFTscreen.line(xpos, sensor[xpos]/8, xpos+1, sensor[xpos+1]/8);
  // Set font color to green
  TFTscreen.stroke(0, 255, 0);
  // Write the text value of the sensor
  if (xpos==0) TFTscreen.text( itoa(value/2, buf, 10), 10, 110);
  if (xpos==0) TFTscreen.text( "mv", 50, 110);
  }
}

