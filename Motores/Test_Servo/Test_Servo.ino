#include <Servo.h>

Servo myservo;  //creamos un objeto servo

void setup()
{
  myservo.attach(13);
}

void loop()
{
    myservo.write(30);  // enviamos el valor escalado al servo.
  delay(500);
  myservo.write(60);  // enviamos el valor escalado al servo.
  delay(500);
  myservo.write(90);  // enviamos el valor escalado al servo.
  delay(500);
  myservo.write(120);  // enviamos el valor escalado al servo.
  delay(500);
  myservo.write(150);  // enviamos el valor escalado al servo.
  delay(2000);
}
