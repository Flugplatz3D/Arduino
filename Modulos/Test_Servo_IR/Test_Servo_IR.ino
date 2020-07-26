#include <Servo.h>
#include <IRremote.h>

Servo myservo;
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define LED_PIN 13

void setup()
{
  myservo.attach(2);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
  myservo.writeMicroseconds(1410);
}

void loop()
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    switch (results.value)
    {
      case 16712445:
        {
          Serial.println("parar");
          digitalWrite(LED_PIN, LOW);
          myservo.writeMicroseconds(1410);
          break;
        }
      case 16761405:
        {
          myservo.writeMicroseconds(950);
          digitalWrite(LED_PIN, HIGH);
          Serial.println("derecha");
          break;
        }
      case 16720605:
        {
          Serial.println("izquierda");
          digitalWrite(LED_PIN, HIGH);
          myservo.writeMicroseconds(1900);
          break;
        }
    }
    irrecv.resume();
  }
}
