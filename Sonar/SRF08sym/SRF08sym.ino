/*
* SRF08.ino - example interfacing with sonar sensor SRF08
 *	library uses Wire.h 
 *		SDA - Analog Pin 4
 *		SCL - Analog Pin 5
 *
 * Authors:
 *	- Zach Foresta - Foureza87@yahoo.com (April 2009)
 *	- Leo Colomb - @LeoColomb (May 2012)
 *
 * For component setup - http://www.arduino.cc/playground/Main/SonarSrf08
 */

#include <Wire.h>
#include <SonarSRF08.h>

// Use the softwareserial library to create a new "soft" serial port
// for the display. This prevents display corruption when uploading code.
#include <SoftwareSerial.h>

SonarSRF08 MySonar;

// Attach the serial display's RX line to digital pin 2
SoftwareSerial mySerial(3,2); // pin 2 = TX, pin 3 = RX (unused)

#define CommandRegister 0x00
int New_Address = 248; // 0xF8
#define ResultRegister  0x02
#define GainRegister 0x00 // Setup Analogue Gain -- http://www.robot-electronics.co.uk/htm/srf08tech.html section "Analogue Gain"
#define RangeLocation 0xFF // Setup Range Location -- http://www.robot-electronics.co.uk/htm/srf08tech.html section "Changing the Range"

int DEBUG = 1;
char unit = 'c'; // 'i' for inches, 'c' for centimeters, 'm' for micro-seconds
float sensorReading = 0;
int time = 70;


void setup()
{
  mySerial.begin(9600);
  BorraP();
  Comando(140); 
  Comando(4);
  Comando(12);
  Comando(134); //luz_on
  Comando(131); //cursor_on
  Cursor(1,1);
  mySerial.print("Arduino");
  Cursor(2,1);
  mySerial.print("SRF08");
  MySonar.connect();  
  MySonar.changeAddress(CommandRegister, New_Address, GainRegister, RangeLocation);
  New_Address += 4; 
  // offset address not sure why this is but it works for this address
  delay(3000);
  BorraP();
}

void loop()
{
  // set units, gain, and range location for reading out distance
  MySonar.setUnit(CommandRegister, New_Address, unit, GainRegister, RangeLocation);
  // pause
  delay(time);
  // set register for reading
  MySonar.setRegister(New_Address, ResultRegister);
  // read data from result register
  sensorReading = MySonar.readData(New_Address, 2);
  // print out distance
  Cursor(1,1);
  mySerial.print("Valor SRF08");
  Cursor(2,1);
  mySerial.print(sensorReading);
  mySerial.print("  ");
  Cursor(4,1);
  mySerial.print(millis(), DEC);
  // pause
  delay(time);
}
void BorraP(){
  mySerial.write(12);
}

void Comando(byte valor){
  mySerial.write(valor);
}

void Cursor(byte fila, byte columna){
  mySerial.write(138);
  mySerial.write(fila);
  mySerial.write(columna);
}





