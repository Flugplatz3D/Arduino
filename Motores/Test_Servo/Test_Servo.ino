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
  myservo.write(30);  // enviamos el valor escalado al servo.
  delay(500);
  digitalWrite(Led, !digitalRead(Led));
  myservo.write(60);  // enviamos el valor escalado al servo.
  delay(500);
  digitalWrite(Led, !digitalRead(Led));
  myservo.write(90);  // enviamos el valor escalado al servo.
  delay(500);
  digitalWrite(Led, !digitalRead(Led));
  myservo.write(120);  // enviamos el valor escalado al servo.
  delay(500);
  digitalWrite(Led, !digitalRead(Led));
  myservo.write(150);  // enviamos el valor escalado al servo.
  delay(2000);
  digitalWrite(Led, !digitalRead(Led));
}
