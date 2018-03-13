//****************************************
// Three color ext AtoD Scope
// By Bob Davis
// UTFT_(C)2012 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// Switches on D12 & D13 determine sweep speed and trigger level
//*******************************************

#include <UTFT.h>
// Declare which fonts we will be using
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
//extern uint8_t SevenSegNumFont[];

// Note that the control pins are now assigned to 8-11
UTFT myGLCD(ILI9325C,8,9,10,11);  
int Input=0;
byte Sample[320];
byte OldSample[320];
int StartSample=0;
int EndSample=0;
int MaxSample=0;
int MinSample=0;
int mode=0;
int dTime=1;
int Trigger=10;
int SampleSize=0;
int SampleTime=0;

void DrawMarkers(){
  myGLCD.setColor(0, 220, 0);
  myGLCD.drawLine(0, 0, 0, 240);
  myGLCD.drawLine(60, 0, 60, 240);
  myGLCD.drawLine(120, 0, 120, 240);
  myGLCD.drawLine(180, 0, 180, 240);
  myGLCD.drawLine(239, 0, 239, 240);
  myGLCD.drawLine(319, 0, 319, 240);
  myGLCD.drawLine(0, 0, 319, 0);
  myGLCD.drawLine(0, 60, 319, 60);
  myGLCD.drawLine(0, 120, 319, 120);
  myGLCD.drawLine(0, 180, 319, 180);
  myGLCD.drawLine(0, 239, 319, 239);
}

void setup() {
  myGLCD.InitLCD();
  myGLCD.clrScr();
  pinMode(12, INPUT);
  digitalWrite(12, HIGH);
  pinMode(13, INPUT);
  digitalWrite(13, HIGH);
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  pinMode(18, INPUT);
  pinMode(19, INPUT);
}

void loop() {
// Set the background color(Red, Green, Blue) 
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setFont(BigFont);
  char buf[12]; 
  while(1) {
    DrawMarkers();
    if (digitalRead(13) == 0) mode++;
    if (mode > 9) mode=0;
// Select delay times for scan modes
    if (mode == 0) dTime=0;
    if (mode == 1) dTime=1;
    if (mode == 2) dTime=2;
    if (mode == 3) dTime=5;
    if (mode == 4) dTime=10;
    if (mode == 5) dTime=20;
    if (mode == 6) dTime=50;
    if (mode == 7) dTime=100;
    if (mode == 8) dTime=200;
    if (mode == 9) dTime=500;
// Select trigger level
    if (digitalRead(12) == 0) Trigger=Trigger+10;
    if (Trigger > 50) Trigger=0;
// Wait for input to be greater than trigger
  while (Input <= Trigger){
    Input = PINC;
    }

// Collect the analog data into an array
  if (mode == 0) {
// Read analog port as a parallel port no delay
  StartSample = micros();
  for(int xpos=0; xpos<319; xpos++) {
    Sample[xpos]=PINC;
//    uint8_t Sample[xpos];
  } 
  EndSample = micros();
  }
  if (mode >= 1) {
// Read analog port as a parallel port variable delay
  StartSample = micros();
  for(int xpos=0; xpos<319; xpos++) {
    Sample[xpos]=PINC;
    delayMicroseconds(dTime);
  } 
  EndSample = micros();
  }

// Display the collected analog data from array
  for(int xpos=0; xpos<318; xpos++) {
// Erase the old stuff
    myGLCD.setColor(0, 0, 0);
    myGLCD.drawLine (xpos+1, 256-OldSample[xpos+1]*4, xpos+2, 256-OldSample[xpos+2]*4);  
    if (xpos==0) myGLCD.drawLine (xpos+1, 1, xpos+1, 239);
// Draw the new data
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawLine (xpos, 256-Sample[xpos]*4, xpos+1, 256-Sample[xpos+1]*4); 
  }  

//  Determine sample voltage peak to peak
  MaxSample = Sample[100];
  MinSample = Sample[100];
  for(int xpos=0; xpos<319; xpos++) {
    OldSample[xpos] = Sample[xpos];  
    if (Sample[xpos] > MaxSample) MaxSample=Sample[xpos];
    if (Sample[xpos] < MinSample) MinSample=Sample[xpos];
    }
// display the sample time, delay time and trigger level  
  myGLCD.setColor(0, 0, 255);
  SampleTime=EndSample-StartSample;
  myGLCD.print("uSec.", 240, 10);
  myGLCD.print("     ", 240, 30);
  myGLCD.print(itoa(SampleTime, buf, 10), 240, 30);
  myGLCD.print("Delay", 240, 70);
  myGLCD.print("     ", 240, 90);
  myGLCD.print(itoa(dTime, buf, 10), 240, 90);
  myGLCD.print("Trig.", 240, 130);
  myGLCD.print(itoa(Trigger, buf, 10), 240, 150);
// Range of 0 to 64 * 78 = 4992 mV
  SampleSize=(MaxSample-MinSample)*78;
  myGLCD.print("mVolt", 240, 190);
  myGLCD.print(itoa(SampleSize, buf, 10), 240, 210);
    } 
}


