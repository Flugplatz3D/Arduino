#include <Servo.h>

Servo myservo;  //creamos un objeto servo

#define Led 13

void setup()
{
  myservo.attach(5);
  pinMode(Led, OUTPUT);
}

void loop()
{
  digitalWrite(Led, HIGH);
  myservo.writeMicroseconds(1410);  // enviamos el valor escalado al servo.
  delay(3000);
  digitalWrite(Led, LOW);
  myservo.writeMicroseconds(950);  // enviamos el valor escalado al servo.
  delay(500);
  myservo.writeMicroseconds(1900);  // enviamos el valor escalado al servo.
  delay(500);
}
