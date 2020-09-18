#define LED0 0
#define LED1 1
#define LED2 2
#define LED3 3

byte i = 0;

void setup() {
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  delay(125);
  digitalWrite(LED0, bitRead(i, 0));
  digitalWrite(LED1, bitRead(i, 1));
  digitalWrite(LED2, bitRead(i, 2));
  digitalWrite(LED3, bitRead(i, 3));
  i++;
}
