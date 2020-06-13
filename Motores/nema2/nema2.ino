#define LedPlaca 13
#define stepPinX 2
#define dirPinX 5
#define enPin 8
#define stepPinY 3
#define dirPinY 6

const int steps = 400;
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
}

void loop() {
  digitalWrite(dirPinX, HIGH);  // Establezco una dirección
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPinX, HIGH);
    digitalWrite(LedPlaca, HIGH);
    delayMicroseconds(pulso);
    digitalWrite(stepPinX, LOW);
    digitalWrite(LedPlaca, LOW);
    delayMicroseconds(pulso);
  }
  delay(2000);
  digitalWrite(dirPinX, LOW);  // Cambio la dirección
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPinX, HIGH);
    digitalWrite(LedPlaca, HIGH);
    delayMicroseconds(pulso);
    digitalWrite(stepPinX, LOW);
    digitalWrite(LedPlaca, LOW);
    delayMicroseconds(pulso);
  }
  delay(2000);
  digitalWrite(dirPinY, HIGH);  // Establezco una dirección
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPinY, HIGH);
    digitalWrite(LedPlaca, HIGH);
    delayMicroseconds(pulso);
    digitalWrite(stepPinY, LOW);
    digitalWrite(LedPlaca, LOW);
    delayMicroseconds(pulso);
  }
  delay(2000);
  digitalWrite(dirPinY, LOW);  // Cambio la dirección
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPinY, HIGH);
    digitalWrite(LedPlaca, HIGH);
    delayMicroseconds(pulso);
    digitalWrite(stepPinY, LOW);
    digitalWrite(LedPlaca, LOW);
    delayMicroseconds(pulso);
  }
  delay(2000);
  digitalWrite(dirPinY, HIGH);  // Establezco una dirección
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPinY, HIGH);
    digitalWrite(LedPlaca, HIGH);
    delayMicroseconds(pulso);
    digitalWrite(stepPinY, LOW);
    digitalWrite(LedPlaca, LOW);
    delayMicroseconds(pulso);
  }
  delay(2000);
  digitalWrite(dirPinY, LOW);  // Cambio la dirección
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPinY, HIGH);
    digitalWrite(LedPlaca, HIGH);
    delayMicroseconds(pulso);
    digitalWrite(stepPinY, LOW);
    digitalWrite(LedPlaca, LOW);
    delayMicroseconds(pulso);
  }
  delay(2000);
}
