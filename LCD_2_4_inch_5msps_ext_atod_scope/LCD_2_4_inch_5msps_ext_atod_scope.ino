//****************************************
// Three color 3MspS ext AtoD Scope
// By Bob Davis
// UTFT_(C)2012 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//

#include <UTFT.h>

// Declare which fonts we will be using
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

// Note that control pins are now assigned to 8-11
UTFT myGLCD(ILI9325C,8,9,10,11);  
int Input=0;
byte Sample[320];
int StartSTime=0;
int EndSTime=0;
float SampleTime=0;

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
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  pinMode(18, INPUT);
  pinMode(19, INPUT);
}

void loop() {
  // set color(Red, Green, Blue) range = 0 to 255
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setFont(BigFont);
  char buf[12]; 
  while(1) {
    DrawMarkers(); 
// wait for trigger of a positive input
  while (Input == 0){
    Input = digitalRead(A1);
    }

// collect the analog data into an array
// Read analog port as a parallel port using PINC
// Code with no loop is about 50% faster!
  StartSTime = micros();
    Sample[0]=PINC;
    Sample[1]=PINC;     Sample[2]=PINC;    Sample[3]=PINC;    
    Sample[4]=PINC;     Sample[5]=PINC;    Sample[6]=PINC;
    Sample[7]=PINC;     Sample[8]=PINC;    Sample[9]=PINC;
    Sample[10]=PINC;    Sample[11]=PINC;    Sample[12]=PINC;
    Sample[13]=PINC;    Sample[14]=PINC;    Sample[15]=PINC;
    Sample[16]=PINC;    Sample[17]=PINC;    Sample[18]=PINC;
    Sample[19]=PINC;    Sample[20]=PINC;    Sample[21]=PINC;
    Sample[22]=PINC;    Sample[23]=PINC;    Sample[24]=PINC;
    Sample[25]=PINC;    Sample[26]=PINC;    Sample[27]=PINC;
    Sample[28]=PINC;    Sample[29]=PINC;    Sample[30]=PINC;
    Sample[31]=PINC;    Sample[32]=PINC;    Sample[33]=PINC;
    Sample[34]=PINC;    Sample[35]=PINC;    Sample[36]=PINC;
    Sample[37]=PINC;    Sample[38]=PINC;    Sample[39]=PINC;
    Sample[40]=PINC;    Sample[41]=PINC;    Sample[42]=PINC;
    Sample[43]=PINC;    Sample[44]=PINC;    Sample[45]=PINC;
    Sample[46]=PINC;    Sample[47]=PINC;    Sample[48]=PINC;
    Sample[49]=PINC;    Sample[50]=PINC;    Sample[51]=PINC;
    Sample[52]=PINC;    Sample[53]=PINC;    Sample[54]=PINC;
    Sample[55]=PINC;    Sample[56]=PINC;    Sample[57]=PINC;
    Sample[58]=PINC;    Sample[59]=PINC;    Sample[60]=PINC;
    Sample[61]=PINC;    Sample[62]=PINC;    Sample[63]=PINC;
    Sample[64]=PINC;    Sample[65]=PINC;    Sample[66]=PINC;
    Sample[67]=PINC;    Sample[68]=PINC;    Sample[69]=PINC;
    Sample[70]=PINC;    Sample[71]=PINC;    Sample[72]=PINC;
    Sample[73]=PINC;    Sample[74]=PINC;    Sample[75]=PINC;
    Sample[76]=PINC;    Sample[77]=PINC;    Sample[78]=PINC;
    Sample[79]=PINC;    Sample[80]=PINC;    Sample[81]=PINC;
    Sample[82]=PINC;    Sample[83]=PINC;    Sample[84]=PINC;
    Sample[85]=PINC;    Sample[86]=PINC;    Sample[87]=PINC;
    Sample[88]=PINC;    Sample[89]=PINC;    Sample[90]=PINC;
    Sample[91]=PINC;    Sample[92]=PINC;    Sample[93]=PINC;
    Sample[94]=PINC;    Sample[95]=PINC;    Sample[96]=PINC;
    Sample[97]=PINC;    Sample[98]=PINC;    Sample[99]=PINC;
    Sample[100]=PINC;    Sample[101]=PINC;    Sample[102]=PINC;
    Sample[103]=PINC;    Sample[104]=PINC;    Sample[105]=PINC;
    Sample[106]=PINC;    Sample[107]=PINC;    Sample[108]=PINC;
    Sample[109]=PINC;    Sample[110]=PINC;    Sample[111]=PINC;
    Sample[112]=PINC;    Sample[113]=PINC;    Sample[114]=PINC;
    Sample[115]=PINC;    Sample[116]=PINC;    Sample[117]=PINC;
    Sample[118]=PINC;    Sample[119]=PINC;    Sample[120]=PINC;
    Sample[121]=PINC;    Sample[122]=PINC;    Sample[123]=PINC;
    Sample[124]=PINC;    Sample[125]=PINC;    Sample[126]=PINC;
    Sample[127]=PINC;    Sample[128]=PINC;    Sample[129]=PINC;
    Sample[130]=PINC;    Sample[131]=PINC;    Sample[132]=PINC;
    Sample[133]=PINC;    Sample[134]=PINC;    Sample[135]=PINC;
    Sample[136]=PINC;    Sample[137]=PINC;    Sample[138]=PINC;
    Sample[139]=PINC;    Sample[140]=PINC;    Sample[141]=PINC;
    Sample[142]=PINC;    Sample[143]=PINC;    Sample[144]=PINC;
    Sample[145]=PINC;    Sample[146]=PINC;    Sample[147]=PINC;
    Sample[148]=PINC;    Sample[149]=PINC;    Sample[150]=PINC;
    Sample[151]=PINC;    Sample[152]=PINC;    Sample[153]=PINC;
    Sample[154]=PINC;    Sample[155]=PINC;    Sample[156]=PINC;
    Sample[157]=PINC;    Sample[158]=PINC;    Sample[159]=PINC;
    Sample[160]=PINC;    Sample[161]=PINC;    Sample[162]=PINC;
    Sample[163]=PINC;    Sample[164]=PINC;    Sample[165]=PINC;
    Sample[166]=PINC;    Sample[167]=PINC;    Sample[168]=PINC;
    Sample[169]=PINC;    Sample[170]=PINC;    Sample[171]=PINC;
    Sample[172]=PINC;    Sample[173]=PINC;    Sample[174]=PINC;
    Sample[175]=PINC;    Sample[176]=PINC;    Sample[177]=PINC;
    Sample[178]=PINC;    Sample[179]=PINC;    Sample[180]=PINC;
    Sample[181]=PINC;    Sample[182]=PINC;    Sample[183]=PINC;
    Sample[184]=PINC;    Sample[185]=PINC;    Sample[186]=PINC;
    Sample[187]=PINC;    Sample[188]=PINC;    Sample[189]=PINC;
    Sample[190]=PINC;    Sample[191]=PINC;    Sample[192]=PINC;
    Sample[193]=PINC;    Sample[194]=PINC;    Sample[195]=PINC;
    Sample[196]=PINC;    Sample[197]=PINC;    Sample[198]=PINC;
    Sample[199]=PINC;    Sample[200]=PINC;    Sample[201]=PINC;
    Sample[202]=PINC;    Sample[203]=PINC;    Sample[204]=PINC;
    Sample[205]=PINC;    Sample[206]=PINC;    Sample[207]=PINC;
    Sample[208]=PINC;    Sample[209]=PINC;    Sample[210]=PINC;
    Sample[211]=PINC;    Sample[212]=PINC;    Sample[213]=PINC;
    Sample[214]=PINC;    Sample[215]=PINC;    Sample[216]=PINC;
    Sample[217]=PINC;    Sample[218]=PINC;    Sample[219]=PINC;    
    Sample[220]=PINC;    Sample[221]=PINC;    Sample[222]=PINC;
    Sample[223]=PINC;    Sample[224]=PINC;    Sample[225]=PINC;
    Sample[226]=PINC;    Sample[227]=PINC;    Sample[228]=PINC;
    Sample[229]=PINC;    Sample[230]=PINC;    Sample[231]=PINC;
    Sample[232]=PINC;    Sample[233]=PINC;    Sample[234]=PINC;
    Sample[235]=PINC;    Sample[236]=PINC;    Sample[237]=PINC;
    Sample[238]=PINC;    Sample[239]=PINC;    Sample[240]=PINC;
    Sample[241]=PINC;    Sample[242]=PINC;    Sample[243]=PINC;
    Sample[244]=PINC;    Sample[245]=PINC;    Sample[246]=PINC;
    Sample[247]=PINC;    Sample[248]=PINC;    Sample[249]=PINC;
    Sample[250]=PINC;    Sample[251]=PINC;    Sample[252]=PINC;
    Sample[253]=PINC;    Sample[254]=PINC;    Sample[255]=PINC;
    Sample[256]=PINC;    Sample[257]=PINC;    Sample[258]=PINC;
    Sample[259]=PINC;    Sample[260]=PINC;    Sample[261]=PINC;
    Sample[262]=PINC;    Sample[263]=PINC;    Sample[264]=PINC;
    Sample[265]=PINC;    Sample[266]=PINC;    Sample[267]=PINC;
    Sample[268]=PINC;    Sample[269]=PINC;    Sample[270]=PINC;
    Sample[271]=PINC;    Sample[272]=PINC;    Sample[273]=PINC;
    Sample[274]=PINC;    Sample[275]=PINC;    Sample[276]=PINC;
    Sample[277]=PINC;    Sample[278]=PINC;    Sample[279]=PINC;
    Sample[280]=PINC;    Sample[281]=PINC;    Sample[282]=PINC;
    Sample[283]=PINC;    Sample[284]=PINC;    Sample[285]=PINC;
    Sample[286]=PINC;    Sample[287]=PINC;    Sample[288]=PINC;
    Sample[289]=PINC;    Sample[290]=PINC;    Sample[291]=PINC;
    Sample[292]=PINC;    Sample[293]=PINC;    Sample[294]=PINC;
    Sample[295]=PINC;    Sample[296]=PINC;    Sample[297]=PINC;
    Sample[298]=PINC;    Sample[299]=PINC;    Sample[300]=PINC;
    Sample[301]=PINC;    Sample[302]=PINC;    Sample[303]=PINC;
    Sample[304]=PINC;    Sample[305]=PINC;    Sample[306]=PINC;
    Sample[307]=PINC;    Sample[308]=PINC;    Sample[309]=PINC;
    Sample[310]=PINC;    Sample[311]=PINC;    Sample[312]=PINC;
    Sample[313]=PINC;    Sample[314]=PINC;    Sample[315]=PINC;
    Sample[316]=PINC;    Sample[317]=PINC;    Sample[318]=PINC;
    Sample[319]=PINC;   
   EndSTime = micros();
// display the collected analog data from array
  for(int xpos=0; xpos<319; xpos++) {
    // Erase old stuff
    myGLCD.setColor(0, 0, 0);
    myGLCD.drawLine (xpos+1, 1, xpos+1, 220);
    // Draw new data
    if (xpos%10==0) DrawMarkers(); 
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawLine (xpos, Sample[xpos]*4, xpos+1, Sample[xpos+1]*4);  }  
  // display the sample time  
  myGLCD.setColor(0, 0, 255);
  SampleTime = EndSTime - StartSTime;
  myGLCD.print("uSeconds=          ", 10, 220);
  myGLCD.print(ltoa(SampleTime, buf, 10), 170, 220);
    } 
}


