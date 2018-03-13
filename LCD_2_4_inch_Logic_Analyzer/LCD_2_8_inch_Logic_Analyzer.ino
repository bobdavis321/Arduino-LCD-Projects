//****************************************
// Three color Logic Analizer
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
//int MaxSample=0;
//int MinSample=0;
byte Sample0[320];
byte OldSample0[320];
byte Sample1[320];
byte OldSample1[320];
int StartSample=0;
int EndSample=0;

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
  // wait for trigger of a positive input
  Input=digitalRead(A0);
  while (Input == 0){
    Input=digitalRead(A0);
  }
  // collect the data into arrays
  StartSample = micros();
  for(int xpos=0; xpos<319; xpos++) {
    Sample0[xpos]=digitalRead(A0);
    Sample1[xpos]=digitalRead(A1);
  } 
  EndSample = micros();
 // make data into displayable information 
    for(int xpos=0; xpos<319; xpos++) {
    Sample0[xpos] = (Sample0[xpos]*50);  
    Sample1[xpos] = ((Sample1[xpos]*50)+100);  
    }
  // display the collected data from array
  for(int xpos=0; xpos<319; xpos++) {
    myGLCD.setColor(0, 0, 0);
    myGLCD.drawLine (xpos, OldSample0[xpos], xpos+1, OldSample0[xpos+1]);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawLine (xpos, Sample0[xpos], xpos+1, Sample0[xpos+1]);
    myGLCD.setColor(0, 0, 0);
    myGLCD.drawLine (xpos, OldSample1[xpos], xpos+1, OldSample1[xpos+1]);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawLine (xpos, Sample1[xpos], xpos+1, Sample1[xpos+1]);
    }
  // store samples to oldsamples
  for(int xpos=0; xpos<319; xpos++) {
    OldSample0[xpos] = Sample0[xpos];  
    OldSample1[xpos] = Sample1[xpos];  
    }
  // display the sample time  
  myGLCD.setColor(0, 0, 255);
  int SampleTime=StartSample-EndSample;
  myGLCD.print("Time=", 161, 220);
  myGLCD.print(itoa(SampleTime, buf, 10), 224, 220);
    } 
}


