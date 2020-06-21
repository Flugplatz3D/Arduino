#define dirPin 11
#define stepPin 12
#define LedMini 13

const int steps = 800;

void setup() {
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  Serial.begin(9600);
  Serial.println();
  delay(2000);
  Flash();
  delay(2000);
}

void loop() {
  for (int p = 2000; p >= 250; p = p - 250)
  {
    Serial.println(p);
    digitalWrite(dirPin, HIGH);
    for (int x = 0; x < steps ; x++) {
      digitalWrite(stepPin, HIGH);
      digitalWrite(LedMini, HIGH);
      delayMicroseconds(p);
      digitalWrite(stepPin, LOW);
      digitalWrite(LedMini, LOW);
      delayMicroseconds(p);
    }
    delay(500);
    digitalWrite(dirPin, LOW);
    for (int x = 0; x < steps ; x++) {
      digitalWrite(stepPin, HIGH);
      digitalWrite(LedMini, HIGH);
      delayMicroseconds(p);
      digitalWrite(stepPin, LOW);
      digitalWrite(LedMini, LOW);
      delayMicroseconds(p);
    }
    delay(500);
  }
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
