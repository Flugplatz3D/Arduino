// Use the softwareserial library to create a new "soft" serial port
// for the display. This prevents display corruption when uploading code.
#include <SoftwareSerial.h>

// Attach the serial display's RX line to digital pin 2
SoftwareSerial mySerial(3,2); // pin 2 = TX, pin 3 = RX (unused)

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(13, OUTPUT);
  mySerial.begin(9600);
  int i=0;
  Flash();
  delay(1000);
}

void loop() {
  mySerial.write(254);
  mySerial.write(128);
  Flash();
  mySerial.write("Hola");
  delay(500);
}
void Flash()
{
  digitalWrite(13, HIGH);   // set the LED on
  delay(20);              // wait for a second
  digitalWrite(13, LOW);    // set the LED off
  delay(100);              // wait for a second
  digitalWrite(13, HIGH);   // set the LED on
  delay(20);              // wait for a second
  digitalWrite(13, LOW);    // set the LED off
  delay(100);              // wait for a second
}
