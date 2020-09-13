#define LED0 11
#define LED1 12
#define LED2 13

void setup() {
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  digitalWrite(LED0, bitRead(millis(), 8));
  digitalWrite(LED1, bitRead(millis(), 9));
  digitalWrite(LED2, bitRead(millis(), 10));
}
