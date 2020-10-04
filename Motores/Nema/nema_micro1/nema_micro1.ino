#define LedMicro 17
#define stepPin 15
#define dirPin 14

const int steps = 800;
int pulso = 1500;

void setup() {
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  delay(1000);
  Flash();
  delay(2000);
}

void loop() {
  digitalWrite(dirPin, HIGH);  // Establezco una dirección

  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPin, HIGH);
    digitalWrite(LedMicro, LOW);
    delayMicroseconds(pulso);
    digitalWrite(stepPin, LOW);
    digitalWrite(LedMicro, HIGH);
    delayMicroseconds(pulso);
  }
  delay(1000);

  digitalWrite(dirPin, LOW);  // Cambio la dirección

  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPin, HIGH);
    digitalWrite(LedMicro, LOW);
    delayMicroseconds(pulso);
    digitalWrite(stepPin, LOW);
    digitalWrite(LedMicro, HIGH);
    delayMicroseconds(pulso);
  }
  delay(1000);
}

void Flash()
{
  for (int i = 0; i < 30  ; i++)
  {
    digitalWrite(LedMicro, LOW);
    delay(25);
    digitalWrite(LedMicro, HIGH);
    delay(50);
  }
}
