#define dirRI 11 //1b
#define dirFI 10 //1a
#define speedI 9 //e1

#define dirRD 5
#define dirFD 4
#define speedD 3

#define ledArduino 13

void setup() {
  pinMode (dirFI, OUTPUT);
  pinMode (dirRI, OUTPUT);
  pinMode (speedI, OUTPUT);
  pinMode (dirRD, OUTPUT);
  pinMode (dirFD, OUTPUT);
  pinMode (speedD, OUTPUT);
  pinMode(ledArduino, OUTPUT);
  for (int i = 0; i < 10; i++)
  {
    delay(200);
    digitalWrite(ledArduino, HIGH);
    delay(200);
    digitalWrite(ledArduino, LOW);
  }
}

void loop() {
  Front();
  for (int j = 0; j < 255; j += 10) {
    analogWrite (speedI, j);
    delay (100);
  }
  delay(1000);
  for (int j = 255; j >= 0; j -= 10) {
    analogWrite (speedI, j);
    delay (100);
  }
  delay(1000);
  Reverse();
  for (int j = 0; j < 255; j += 10) {
    analogWrite (speedI, j);
    delay (100);
  }
  delay(1000);
  for (int j = 255; j >= 0; j -= 10) {
    analogWrite (speedI, j);
    delay (100);
  }
  delay(1000);
  Front();
  for (int j = 0; j < 255; j += 10) {
    analogWrite (speedD, j);
    delay (100);
  }
  delay(1000);
  for (int j = 255; j >= 0; j -= 10) {
    analogWrite (speedD, j);
    delay (100);
  }
  delay(1000);
  Reverse();
  for (int j = 0; j < 255; j += 10) {
    analogWrite (speedD, j);
    delay (100);
  }
  delay(1000);
  for (int j = 255; j >= 0; j -= 10) {
    analogWrite (speedD, j);
    delay (100);
  }
  delay(1000);
}

void Front()
{
  digitalWrite(dirFI, LOW);
  digitalWrite(dirRI, HIGH);
  digitalWrite(dirFD, LOW);
  digitalWrite(dirRD, HIGH);
}

void Reverse()
{
  digitalWrite(dirFI, HIGH);
  digitalWrite(dirRI, LOW);
  digitalWrite(dirFD, HIGH);
  digitalWrite(dirRD, LOW);
}
