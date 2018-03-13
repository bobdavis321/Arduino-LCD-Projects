/*****************************************
 LiquidCrystal Library - Temperature
 Demonstrates the use a 16x2 LCD display.  
 This sketch prints "Indoor" and "Outdoor" to the LCD
 and shows the temperatures.
 
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

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print the text to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("Indoor:");
  lcd.setCursor(0, 1);
  lcd.print("Outdoor:");
}

void loop() {
  // set the cursor to column 12 of line 0
  lcd.setCursor(12, 0);
  int Temperature=analogRead(A0)/2.05;
  // print the temperature:
  lcd.print(Temperature);
  // set the cursor to column 12 of line 1
  lcd.setCursor(12, 1);
  int Temperature2=analogRead(A1)/2.05;
  // print the temperature:
  lcd.print(Temperature2);
}

