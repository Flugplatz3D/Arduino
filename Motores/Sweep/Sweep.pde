// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo1;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created
//Servo myservo2;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created  
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo1.attach(12);  // attaches the servo on pin 12 to the servo object
//  myservo2.attach(11);  // attaches the servo on pin 11 to the servo object
  Serial.begin(9600);
  pinMode(13, OUTPUT);
} 
 
 
void loop() 
{
  int SensorValue = analogRead(0);
  Serial.print("AN0->");
  Serial.println(SensorValue, DEC);
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
//    myservo2.write(pos); 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
/*  digitalWrite(13, HIGH);   // set the LED on
  delay(15);              // wait for a second
  digitalWrite(13, LOW);    // set the LED off
  delay(1000);  
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos); 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }*/
  digitalWrite(13, HIGH);   // set the LED on
  delay(5);              // wait for a second
  digitalWrite(13, LOW);    // set the LED off
  delay(1500);  
} 
