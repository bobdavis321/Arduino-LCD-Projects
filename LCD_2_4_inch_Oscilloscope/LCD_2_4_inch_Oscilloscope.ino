//****************************************
// Three color analog Oscilloscope
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
int Input=0;
int OldInput=0;
int MaxSample=0;
int MinSample=0;
int Sample[320];
int OldSample[320];
int StartTime=0;
int EndTime=0;

void DrawMarkers(){
  myGLCD.setColor(0, 200, 0);
  myGLCD.drawLine(0, 0, 0, 240);
  myGLCD.drawLine(54, 0, 54, 240);
  myGLCD.drawLine(107, 0, 107, 240);
  myGLCD.drawLine(160, 0, 160, 240);
  myGLCD.drawLine(213, 0, 213, 240);
  myGLCD.drawLine(266, 0, 266, 240);
  myGLCD.drawLine(319, 0, 319, 240);
  myGLCD.drawLine(0, 0, 319, 0);
  myGLCD.drawLine(0, 50, 319, 50);
  myGLCD.drawLine(0, 100, 319, 100);
  myGLCD.drawLine(0, 150, 319, 150);
  myGLCD.drawLine(0, 200, 319, 200);
  myGLCD.drawLine(0, 239, 319, 239);
}

void setup() {
  myGLCD.InitLCD();
  myGLCD.clrScr();
}

void loop() {
  // set color(Red, Green, Blue) range = 0 to 255
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setFont(BigFont);
  char buf[12]; 
  while(1) {
  DrawMarkers(); 
  // wait for a trigger of a positive going input
  OldInput=analogRead(A0);
  Input=analogRead(A0);
  while (Input < OldInput){
    Input=analogRead(A0);
  }
  // collect the analog data into an array
  // do not do division here, it makes it slower!
  StartTime = micros();
  for(int xpos=0; xpos<319; xpos++) {
    Sample[xpos]=analogRead(A0);
  } 
  EndTime = micros();
  // display the collected analog data from array
  // Sample/4.1 because 1024 becomes 250 = 5 volts
  for(int xpos=0; xpos<319; xpos++) {
    myGLCD.setColor(0, 0, 0);
    myGLCD.drawLine (xpos, OldSample[xpos]/4.1, xpos+1, OldSample[xpos+1]/4.1);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawLine (xpos, Sample[xpos]/4.1, xpos+1, Sample[xpos+1]/4.1);
  }
//  Determine sample voltage peak to peak
  MaxSample = Sample[100];
  MinSample = Sample[100];
  for(int xpos=0; xpos<319; xpos++) {
    OldSample[xpos] = Sample[xpos];  
    if (Sample[xpos] > MaxSample) MaxSample=Sample[xpos];
    if (Sample[xpos] < MinSample) MinSample=Sample[xpos];
    
    }
//  Display sample voltage and time    
  myGLCD.setColor(0, 0, 255);
  int SampleSize=MaxSample-MinSample;
  myGLCD.print("MV=", 1, 220);
  myGLCD.print(itoa(SampleSize, buf, 10), 44, 220);
  int SampleTime=StartTime-EndTime;
  myGLCD.print("uS=", 181, 220);
  myGLCD.print(itoa(SampleTime, buf, 10), 230, 220);
    } 
}


