#define LedPlaca 13
#define stepPin 3
#define dirPin 4

const int steps = 2000;
int pulso = 900;

void setup() {
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
}

void loop() {
  digitalWrite(dirPin, HIGH);  // Establezco una dirección

  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPin, HIGH);
    digitalWrite(LedPlaca, HIGH);
    delayMicroseconds(pulso);
    digitalWrite(stepPin, LOW);
    digitalWrite(LedPlaca, LOW);
    delayMicroseconds(pulso);
  }
  delay(1000);

  digitalWrite(dirPin, LOW);  // Cambio la dirección

  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepPin, HIGH);
    digitalWrite(LedPlaca, HIGH);
    delayMicroseconds(pulso);
    digitalWrite(stepPin, LOW);
    digitalWrite(LedPlaca, LOW);
    delayMicroseconds(pulso);
  }
  delay(1000);

}
