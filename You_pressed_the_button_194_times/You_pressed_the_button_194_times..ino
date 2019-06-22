/*
  Keyboard Message test

  For the Arduino Leonardo and Micro.

  Sends a text string when a button is pressed.

  The circuit:
  - pushbutton attached from pin 4 to +5V
  - 10 kilohm resistor attached from pin 4 to ground

  created 24 Oct 2011
  modified 27 Mar 2012
  by Tom Igoe
  modified 11 Nov 2013
  by Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/KeyboardMessage
*/

#include "Keyboard.h"

const int buttonPin = 4;          // input pin for pushbutton
int previousButtonState = HIGH;   // for checking the state of a pushButton
int counter = 0;                  // button push counter

void setup() {
  // make the pushButton pin an input:
  pinMode(buttonPin, INPUT);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  // read the pushbutton:
  int buttonState = digitalRead(buttonPin);
  // if the button state has changed,
//  if ((buttonState != previousButtonState)
//      // and it's currently pressed:
//      && (buttonState == HIGH)) {
    // increment the button counter
    counter++;
    // type out a message
    Keyboard.print("You pressed the button ");
    Keyboard.print(counter);
    Keyboard.println(" times.");
    delay(500);
//  }
  // save the current button state for comparison next time:
  previousButtonState = buttonState;
}

You pressed the button 5 times.
You pressed the button 6 times.
You pressed the button 7 times.
You pressed the button 8 times.
You pressed the button 9 times.
You pressed the button 10 times.
You pressed the button 11 times.
You pressed the button 12 times.
You pressed the button 13 times.
You pressed the button 14 times.
You pressed the button 15 times.
You pressed the button 16 times.
You pressed the button 17 times.
You You pressed the button 35 times.
You pressed the button 36 times.
You pressed the button 37 times.
You pressed the button 38 times.
You pressed the button 39 times.
You pressed the button 40 times.
You pressed the button 51 times.
You pressed the button 52 times.
You pressed the button 53 times.
You pressed the button 54 times.
You pressed the button 55 times.
You pressed the button 70 times.
You pressed the button 72 times.
You pressed the button 73 times.
You pressed the button 75 times.
You pressed the button 76 times.
You pressed the button 78 times.
You pressed the button 79 times.You pressed the button 157 times.
You pressed the button 158 times.
You pressed the button 159 times.
You pressed the button 160 times.
You pressed the button 161 times.
You pressed the button 162 times.
You pressed the button 163 times.
You pressed the button 164 times.
You pressed the button 165 times.
You pressed the button 166 times.
You pressed the button 167 times.
You pressed the button 168 times.
You pressed the button 169 times.
You pressed the button 170 times.
You pressed the button 171 times.

You pressed the button 80 times.
You pressed the button 81 times.
pressed the button 106 times.
You pressed the button 107 times.
You pressed the button 108 times.
You pressed the button 109 times.
You pressed the button 154 times.
You pressed the button 155 times.You ptton 172 times.
You pressed the button 173 times.
You pressed the button 174 times.
You pressed the button 175 times.
You pressed the button 176 times.
You pressed the button 177 times.
You pressed the button 178 times.
You pressed the button 179 times.
You pressed the button 180 times.
You pressed the button 181 times.
You pressed the button 182 times.
You pressed the button 183 times.
You pressed the button 184 times.
You pressed the button 185 times.
You pressed the button 186 times.
You pressed the button 187 times.
You pressed the button 188 times.
You pressed the button 189 times.
You pressed the button 190 times.
You pressed the button 191 times.
You pressed the button 192 times.

You pressed the button 156 times.
