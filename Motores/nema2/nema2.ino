#define LedPlaca 13
#define stepPinX 2
#define dirPinX 5
#define enPin 8
#define stepPinY 3
#define dirPinY 6

const int steps = 200;
int pulso = 1500;

void setup() {
  pinMode(dirPinX, OUTPUT);
  pinMode(stepPinX, OUTPUT);
  pinMode(dirPinY, OUTPUT);
  pinMode(stepPinY, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, HIGH);
  delay(4000);
  digitalWrite(enPin, LOW);
  delay(250);
}

void loop() {
  digitalWrite(dirPinX, HIGH);
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPinX, HIGH);
    digitalWrite(LedPlaca, HIGH);
    delayMicroseconds(pulso);
    digitalWrite(stepPinX, LOW);
    digitalWrite(LedPlaca, LOW);
    delayMicroseconds(pulso);
  }
  delay(1000);
  digitalWrite(dirPinX, LOW);
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPinX, HIGH);
    digitalWrite(LedPlaca, HIGH);
    delayMicroseconds(pulso);
    digitalWrite(stepPinX, LOW);
    digitalWrite(LedPlaca, LOW);
    delayMicroseconds(pulso);
  }
  delay(1000);

  digitalWrite(dirPinY, HIGH);
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPinY, HIGH);
    digitalWrite(LedPlaca, HIGH);
    delayMicroseconds(pulso);
    digitalWrite(stepPinY, LOW);
    digitalWrite(LedPlaca, LOW);
    delayMicroseconds(pulso);
  }
  delay(1000);
  digitalWrite(dirPinY, LOW);
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPinY, HIGH);
    digitalWrite(LedPlaca, HIGH);
    delayMicroseconds(pulso);
    digitalWrite(stepPinY, LOW);
    digitalWrite(LedPlaca, LOW);
    delayMicroseconds(pulso);
  }
  delay(1000);

  digitalWrite(dirPinX, HIGH);
  digitalWrite(dirPinY, HIGH);
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPinX, HIGH);
    digitalWrite(stepPinY, HIGH);
    digitalWrite(LedPlaca, HIGH);
    delayMicroseconds(pulso);
    digitalWrite(stepPinX, LOW);
    digitalWrite(stepPinY, LOW);
    digitalWrite(LedPlaca, LOW);
    delayMicroseconds(pulso);
  }
  delay(1000);
  digitalWrite(dirPinX, LOW);
  digitalWrite(dirPinY, LOW);
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPinX, HIGH);
    digitalWrite(stepPinY, HIGH);
    digitalWrite(LedPlaca, HIGH);
    delayMicroseconds(pulso);
    digitalWrite(stepPinX, LOW);
    digitalWrite(stepPinY, LOW);
    digitalWrite(LedPlaca, LOW);
    delayMicroseconds(pulso);
  }
  digitalWrite(enPin, HIGH);
  delay(5000);
  digitalWrite(enPin, LOW);
  delay(250);
}
