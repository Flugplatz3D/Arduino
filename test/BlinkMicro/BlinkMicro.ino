#define LED 17

void setup() {
  pinMode(LED, OUTPUT);
}
void loop() {
  digitalWrite(LED, bitRead(millis(), 10));
}
