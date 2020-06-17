#define dirPin 11
#define stepPin 12
#define LedMini 13

const int steps = 200;
int pulso = 1500;

void setup() {
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  delay(2000);
  Flash();
  delay(2000);
}

void loop() {
  digitalWrite(dirPin, HIGH);
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPin, HIGH);
    digitalWrite(LedMini, HIGH);
    delayMicroseconds(pulso);
    digitalWrite(stepPin, LOW);
    digitalWrite(LedMini, LOW);
    delayMicroseconds(pulso);
  }
  delay(1000);
  digitalWrite(dirPin, LOW);
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPin, HIGH);
    digitalWrite(LedMini, HIGH);
    delayMicroseconds(pulso);
    digitalWrite(stepPin, LOW);
    digitalWrite(LedMini, LOW);
    delayMicroseconds(pulso);
  }
  delay(1000);
}

void Flash()
{
  for (int i = 0; i < 25  ; i++)
  {
    digitalWrite(LedMini, HIGH);
    delay(25);
    digitalWrite(LedMini, LOW);
    delay(75);
  }
}
