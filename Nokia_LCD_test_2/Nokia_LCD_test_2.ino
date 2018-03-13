// Nokia LCD test, adapted from pcdtest by Bob Davis

#include "PCD8544.h"
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
PCD8544 nokia = PCD8544(7, 6, 5, 3, 4);

// a bitmap of a 16x16 fruit icon
//static unsigned char __attribute__ ((progmem)) logo16_glcd_bmp[]={
//0x30, 0xf0, 0xf0, 0xf0, 0xf0, 0x30, 0xf8, 0xbe, 
//0x9f, 0xff, 0xf8, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 
//0x20, 0x3c, 0x3f, 0x3f, 0x1f, 0x19, 0x1f, 0x7b, 
//0xfb, 0xfe, 0xfe, 0x07, 0x07, 0x07, 0x03, 0x00,
//};
// a bitmap of a 16x16 smiley face
static unsigned char __attribute__ ((progmem)) logo16_glcd_bmp[]={
0x0f, 0xf0, 0x18, 0x81, 0x30, 0x0c, 0x60, 0x06, 
0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 
0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 
0x60, 0x06, 0x30, 0x0c, 0x18, 0x81, 0x0f, 0xf0, 
};

static unsigned char __attribute__ ((progmem)) smiles [] = {
0x00, 0x00, 0x00, 0x00, 0xC0, 0x60, 0x30, 0x10, 
0x18, 0x08, 0x0C, 0x04, 0x04, 0x04, 0x04, 0x04,
0x04, 0x04, 0x04, 0x04, 0x04, 0x0C, 0x08, 0x18, 
0x10, 0x30, 0x60, 0xC0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x3E, 0x07, 0x7D, 0x43, 0x41, 0x41, 
0x4F, 0x4F, 0x4E, 0x78, 0x00, 0x00, 0x00, 0x00,
0x78, 0x46, 0x43, 0x41, 0x41, 0x47, 0x4F, 0x4E, 
0x7C, 0x00, 0x00, 0x01, 0x07, 0x7E, 0xF0, 0x00,
0x00, 0x00, 0x7C, 0xE0, 0x80, 0x06, 0x3E, 0xE6, 
0x86, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x86,
0x86, 0x86, 0x86, 0x86, 0x06, 0x06, 0x06, 0xC6, 
0x7C, 0x00, 0x00, 0x80, 0xE0, 0x7E, 0x0F, 0x00,
0x00, 0x00, 0x00, 0x00, 0x03, 0x06, 0x0C, 0x08, 
0x19, 0x13, 0x36, 0x24, 0x6C, 0x6E, 0x6F, 0x6F,
0x6F, 0x6F, 0x6F, 0x6F, 0x27, 0x33, 0x13, 0x19, 
0x0C, 0x0C, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00
};
const int smilesx=32;
const int smilesy=32;


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 

void setup(void) {
  nokia.init();
  // you can change the contrast for the best viewing!
  nokia.setContrast(40);

  // show splashscreen
  nokia.display();
  delay(2000);
  nokia.clear();

// draw vertical lines;
  nokia.drawstring(0, 0, "Vertical Lines");
  nokia.display(); 
  delay(1000);
  nokia.clear();
  for(int i=1; i<84; i+=4){
    nokia.drawline(i, 1, i, 47, BLACK);    
  } 
  nokia.display();   // show the lines
  delay(2000);
  nokia.clear();

// draw horizontal lines;
  nokia.drawstring(0, 0, "Horiz. Lines");
  nokia.display(); 
  delay(1000);
  nokia.clear();
  for(int i=1; i<48; i+=4){
    nokia.drawline(1, i, 83, i, BLACK);    
  } 
  nokia.display();   // show the lines
  delay(2000);
  nokia.clear();
  
// draw mulitple circles
  nokia.drawstring(0, 0, "Circles");
  nokia.display(); 
  delay(1000);
  nokia.clear();
  for(int i=1; i<48; i+=4){
  nokia.drawcircle(41, 23, i, BLACK);
  }
  nokia.display();
  delay(2000);
  nokia.clear();
  
// draw the characters in the character generator
  nokia.drawstring(0, 0, "Characters");
  nokia.display(); 
  delay(1000);
  nokia.clear();
  for (uint8_t i=0; i < 64; i++) {
    nokia.drawchar((i % 14) * 6, (i/14) * 8, i);
  }    
  nokia.display();
  delay(2000);
  for (uint8_t i=0; i < 64; i++) {
    nokia.drawchar((i % 14) * 6, (i/14) * 8, i + 64);
  }    
  nokia.display();
  delay(2000);
  nokia.clear();
  
  //draw smiley faces randomly across the screen 
  for(int i=0; i<=10; i++){
    int x=random(-32, 76);
    int y=random(-32, 40);
    nokia.drawbitmap(x, y, smiles, smilesx, smilesy, BLACK);
    nokia.display();
    delay(500);
  }
  nokia.clear();

  // draw a bitmap icon and 'animate' movement
  testdrawbitmap(logo16_glcd_bmp, LOGO16_GLCD_HEIGHT, LOGO16_GLCD_WIDTH);
}

void loop(void) {}
#define NUMFLAKES 8
#define XPOS 0
#define YPOS 1
#define DELTAY 2

void testdrawbitmap(const uint8_t *bitmap, uint8_t w, uint8_t h) {
  uint8_t icons[NUMFLAKES][3];
  srandom(666);     // whatever seed
  // initialize
  for (uint8_t f=0; f< NUMFLAKES; f++) {
    icons[f][XPOS] = random() % LCDWIDTH;
    icons[f][YPOS] = 0;
    icons[f][DELTAY] = random() % 5 + 1;
  }
  while (1) {
    // draw each icon
    for (uint8_t f=0; f< NUMFLAKES; f++) {
      nokia.drawbitmap(icons[f][XPOS], icons[f][YPOS], logo16_glcd_bmp, w, h, BLACK);
    }
    nokia.display();
    delay(200);
    // then erase it + move it
    for (uint8_t f=0; f< NUMFLAKES; f++) {
      nokia.drawbitmap(icons[f][XPOS], icons[f][YPOS],  logo16_glcd_bmp, w, h, 0);
      // move it
      icons[f][YPOS] += icons[f][DELTAY];
      // if its gone, reinit
      if (icons[f][YPOS] > LCDHEIGHT) {
	icons[f][XPOS] = random() % LCDWIDTH;
	icons[f][YPOS] = 0;
	icons[f][DELTAY] = random() % 5 + 1;
      }
    }
  }
}


