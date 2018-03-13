/*****************************************
 LiquidCrystal Library - 40 x 2 4 analog
 Demonstrates the use a 40x2 LCD display.  
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
  lcd.print("Analog0:     Analog2:     Analog4:");
  lcd.setCursor(0, 1);
  lcd.print("Analog1:     Analog3:     Analog5:");
}

void loop() {
  // set the cursor to column 9 of line 0
  lcd.setCursor(9, 0);
  int Analog0=analogRead(A0)/2.05;
  // print the temperature:
  lcd.print(Analog0);
  // set the cursor to column 9 of line 1
  lcd.setCursor(9, 1);
  int Analog1=analogRead(A1)/2.05;
  // print the temperature:
  lcd.print(Analog1);
  // set the cursor to column 22 of line 0
  lcd.setCursor(22, 0);
  int Analog2=analogRead(A2)/2.05;
  // print the temperature:
  lcd.print(Analog2);
  // set the cursor to column 22 of line 1
  lcd.setCursor(22, 1);
  int Analog3=analogRead(A3)/2.05;
  // print the temperature:
  lcd.print(Analog3);
  // set the cursor to column 35 of line 0
  lcd.setCursor(35, 0);
  int Analog4=analogRead(A4)/2.05;
  // print the temperature:
  lcd.print(Analog4);
  // set the cursor to column 35 of line 1
  lcd.setCursor(35, 1);
  int Analog5=analogRead(A5)/2.05;
  // print the temperature:
  lcd.print(Analog5);

}

