#include <OneWire.h>
#include <DallasTemperature.h>
#include <TM1638.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// define un modulo en data pin 8, clock pin 9 y strobe pin 7
TM1638 module(8, 9, 7);
unsigned long time1 = 0;
int Temp;
String Temp1, Temp2;

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup(void) 
{
  // Start up the library
  sensors.begin();
}

void loop(void)
{ 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  sensors.requestTemperatures(); // Send the command to get temperatures

  Temp = sensors.getTempCByIndex(0) * 10;
  Temp1 = String(Temp,DEC);

  Temp = sensors.getTempCByIndex(1) * 10;
  Temp2 = String(Temp,DEC);
  module.setDisplayToString(Temp1 + ' ' + Temp2,0,false);
}





