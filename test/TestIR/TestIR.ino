#include <IRremote.h>

int RECV_PIN = 11;
#define LED_PIN 13

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); 
  digitalWrite(LED_PIN, HIGH);
}

void loop() {
  if (irrecv.decode(&results)) {
    //Serial.print(results.value, HEX);
    //Serial.print("    ");
    Serial.println(results.value);
    switch (results.value)
    {
      case 16712445:
        {
          Serial.println("parar");
          break;
        }
      case 16736925:
        {
          Serial.println("avanzar");
          break;
        }
      case 16754775:
        {
          Serial.println("retroceder");
          break;
        }
      case 16761405:
        {
          Serial.println("derecha");
          break;
        }
      case 16720605:
        {
          Serial.println("izquierda");
          break;
        }
    }
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
