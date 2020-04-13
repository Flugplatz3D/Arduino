#define LedPlaca 13
#define Led 2

void setup() {
  pinMode(Led, OUTPUT);
  pinMode(LedPlaca, OUTPUT);
}

void loop() {
  delay(250);
  digitalWrite(Led, !digitalRead(Led));
  digitalWrite(LedPlaca, !digitalRead(LedPlaca));
}
