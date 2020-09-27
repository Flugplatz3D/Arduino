#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX
unsigned int i=0;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  //  while (!Serial) {
  //    ; // wait for serial port to connect. Needed for Native USB only
  //  }
  Serial.println("Goodnight moon!");
  delay(3000);
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.write(12);
  mySerial.write(4);
  mySerial.println("Hola Mundo");
  delay(3000);
  mySerial.write(12);
  mySerial.write(20);
}

void loop() // run over and over
{
  Serial.println(millis());
  mySerial.write(1);
  mySerial.print(i);
  delay(100);
  i++;
}
