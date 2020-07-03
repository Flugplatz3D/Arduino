#define dirPinRight 9
#define stepPinRight 10
#define dirPinLeft 11
#define stepPinLeft 12
#define LedMini 13

//16 microsteps

int steps = 3200;
int pulso = 100;

void setup() {
  pinMode(dirPinRight, OUTPUT);
  pinMode(stepPinRight, OUTPUT);
  pinMode(dirPinLeft, OUTPUT);
  pinMode(stepPinLeft, OUTPUT);
  delay(2000);
  Flash();
  delay(2000);
}

void loop() {
  digitalWrite(dirPinRight, LOW);
  digitalWrite(dirPinLeft, HIGH);
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPinRight, HIGH);
    digitalWrite(stepPinLeft, HIGH);
    digitalWrite(LedMini, HIGH);
    delayMicroseconds(pulso);
    digitalWrite(stepPinLeft, LOW);
    digitalWrite(stepPinRight, LOW);
    digitalWrite(LedMini, LOW);
    delayMicroseconds(pulso);
  }
  delay(1000);
  digitalWrite(dirPinRight, HIGH);
  digitalWrite(dirPinLeft, LOW);
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPinRight, HIGH);
    digitalWrite(stepPinLeft, HIGH);
    digitalWrite(LedMini, HIGH);
    delayMicroseconds(pulso);
    digitalWrite(stepPinLeft, LOW);
    digitalWrite(stepPinRight, LOW);
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
