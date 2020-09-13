#define LED0 0
#define LED1 1
#define LED2 2
#define LED3 3

void setup() {
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  digitalWrite(LED0, bitRead(millis(), 7));
  digitalWrite(LED1, bitRead(millis(), 8));
  digitalWrite(LED2, bitRead(millis(), 9));
  digitalWrite(LED3, bitRead(millis(), 10));
}
