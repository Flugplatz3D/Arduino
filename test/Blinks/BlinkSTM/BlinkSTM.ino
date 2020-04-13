#define Led PB1 //PC13

void setup() {
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(Led, OUTPUT);
}

void loop() {
  digitalWrite(Led, HIGH);
  delay(100);
  digitalWrite(Led, LOW);
  delay(100);
  digitalWrite(Led, HIGH);
  delay(100);
  digitalWrite(Led, LOW);
  delay(100);
  digitalWrite(Led, HIGH);
  delay(100);
  digitalWrite(Led, LOW);
  delay(1000);
}
