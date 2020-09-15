#define LED 3
byte i = 0;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  delay(1000);
  //  digitalWrite(LED, !digitalRead(LED));
  digitalWrite(LED, bitRead(i, 0));
  i++;
}
