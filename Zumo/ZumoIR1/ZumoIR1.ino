#include <IRremote.h>
#include <ZumoMotors.h>

int RECV_PIN = 11;
#define LED_PIN 13

int var = 1;

IRrecv irrecv(RECV_PIN);
ZumoMotors motors;

decode_results results;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  motors.flipLeftMotor(true);
  motors.flipRightMotor(true);
  digitalWrite(LED_PIN, HIGH);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print(results.value, HEX);
    Serial.print("    ");
    Serial.println(results.value);
    switch (results.value)
    {
      case 16712445:
        {
          Serial.println("parar");
          motors.setRightSpeed(0);
          motors.setLeftSpeed(0);
          break;
        }
      case  16750695:
        {
          Serial.println("parar");
          motors.setRightSpeed(0);
          motors.setLeftSpeed(0);
          break;
        }

      case 16736925:
        {
          Serial.println("avanzar");
          motors.setRightSpeed(255);
          motors.setLeftSpeed(255);
          break;
        }
      case 16754775:
        {
          Serial.println("retroceder");
          motors.setRightSpeed(-255);
          motors.setLeftSpeed(-255);
          break;
        }
      case 16756815:
        {
          Serial.println("derecha");
          motors.setRightSpeed(0);
          motors.setLeftSpeed(180);
          break;
        }
      case 16738455:
        {
          Serial.println("izquierda");
          motors.setRightSpeed(180);
          motors.setLeftSpeed(0);
          break;
        }
      case 16761405:
        {
          Serial.println("derecha mix");
          motors.setRightSpeed(150);
          motors.setLeftSpeed(255);
          break;
        }
      case 16720605:
        {
          Serial.println("izquierda mix");
          motors.setRightSpeed(255);
          motors.setLeftSpeed(150);
          break;
        }

      case 16724175:
        {
          motors.setRightSpeed(150);
          motors.setLeftSpeed(-150);
          break;
        }
      case 16743045:
        {
          motors.setRightSpeed(-150);
          motors.setLeftSpeed(150);
          break;
        }
      case 16728765:
        {
          motors.setRightSpeed(255);
          motors.setLeftSpeed(-255);
          break;
      } 
      case 16732845:
        {
          motors.setRightSpeed(-255);
          motors.setLeftSpeed(255);
          break;
        }
    }
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
