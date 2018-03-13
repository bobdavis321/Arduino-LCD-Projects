/*****************************************
 LiquidCrystal Library - Analog meter
 Demonstrates the use a 16x2 LCD display.  
 This sketch displays a simulated analog meter to the LCD
 
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
  B01000,
  B01000,
  B01000,
  B01000,
  B01000,
  B01000,
  B01000,
  B01000
};
byte line3[8]= {
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};
byte line4[8]= {
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
  B00010
};
byte line5[8]= {
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001
};
 
void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print the text to the LCD.
  lcd.createChar(1, line1);
  lcd.createChar(2, line2);
  lcd.createChar(3, line3);
  lcd.createChar(4, line4);
  lcd.createChar(5, line5);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.setCursor(0, 0);
  lcd.print("MiliVolts:");
  // set the cursor to column 12 of line 0
  lcd.setCursor(12, 0);
  int Voltage=analogRead(A0)/2.05;
  // print the temperature:
  lcd.print(Voltage);
  int metervolts=Voltage/3;
  lcd.setCursor(metervolts/10, 1);
  if (metervolts%10/2 == 0) lcd.write(1);
  if (metervolts%10/2 == 1) lcd.write(2);
  if (metervolts%10/2 == 2) lcd.write(3);
  if (metervolts%10/2 == 3) lcd.write(4);
  if (metervolts%10/2 == 4) lcd.write(5);
  delay(100);
}

