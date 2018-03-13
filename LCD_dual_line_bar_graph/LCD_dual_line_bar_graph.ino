/*****************************************
 LiquidCrystal Library - Bar Graph
 Demonstrates the use a 16x2 LCD display.  
 This sketch displays a simulated bar graph to the LCD
 
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD En pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * Variable resistor wiper to LCD VO pin (pin 3)
 
 Adapted from code written by David A. Mellis
 Modified by Limor Fried, Tom Igoe, Bob Davis
 ****************************************/
 
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with interface pin #'s
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte line1[8]= {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000
};
byte line2[8]= {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000
};
byte line3[8]= {
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100
};
byte line4[8]= {
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110
};
byte line5[8]= {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
 
void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // create the text for the LCD.
  lcd.createChar(1, line1);
  lcd.createChar(2, line2);
  lcd.createChar(3, line3);
  lcd.createChar(4, line4);
  lcd.createChar(5, line5);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Volts:");
  int Voltage=analogRead(A0)/2.05;
  // print the voltage:
  lcd.setCursor(8, 0);
  lcd.print(Voltage);
  // overwrite first digit and add a .
  lcd.setCursor(7, 0);
  if (Voltage >= 100) lcd.print(Voltage/100);
  lcd.print(".");
  if (Voltage < 100) lcd.print(Voltage);
  // print the bar graph
  lcd.setCursor(0,1);
  int metervolts=Voltage/3;
  // draw lower spaces as solid
  for (int pos=0; pos < metervolts/10; pos++) {  
  lcd.write(5);
  }
  lcd.setCursor(metervolts/10, 1);
  if (metervolts%10/2 == 0) lcd.write(1);
  if (metervolts%10/2 == 1) lcd.write(2);
  if (metervolts%10/2 == 2) lcd.write(3);
  if (metervolts%10/2 == 3) lcd.write(4);
  if (metervolts%10/2 == 4) lcd.write(5);
  delay(500);
}

