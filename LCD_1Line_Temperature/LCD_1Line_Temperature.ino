/*****************************************
 LiquidCrystal - Temperature
 
 Demonstrates the use a 16x1 LCD display.  
 It is organized as row 0 has 8 characters, 
 row 1 has 8 characters
 
 This sketch prints "Temperature" to the LCD
 and shows the temperature.
 
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
 Modified by Limor Fried, Tom Igoe, Tom Igoe
 ****************************************/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with interface pin #'s
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(8, 2);
  // Print the first 8 characters to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("Temperat");
  // Print the last 3 characters to the LCD.
  lcd.setCursor(0, 1);
  lcd.print("ure:");
}

void loop() {
  // set the cursor to column 5 of line 1
  lcd.setCursor(5, 1);
  int Temperature=analogRead(A0)/2.05;
  // print the temperature:
  lcd.print(Temperature);
}

