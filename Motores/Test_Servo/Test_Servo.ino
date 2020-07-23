#include <Servo.h>

Servo myservo;  //creamos un objeto servo

#define Led 13

void setup()
{
  myservo.attach(2);
  pinMode(Led, OUTPUT);
}

void loop()
{
  digitalWrite(Led, HIGH);
  myservo.write(83);  // enviamos el valor escalado al servo.
  delay(3000);
  digitalWrite(Led, LOW);
  myservo.write(60);  // enviamos el valor escalado al servo.
  delay(500);
  myservo.write(110);  // enviamos el valor escalado al servo.
  delay(500);
}
