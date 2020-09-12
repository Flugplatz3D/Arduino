#define LED 3

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
//    delay(500);
//    digitalWrite(LED, !digitalRead(LED));
  digitalWrite(LED, bitRead(millis(), 9));
}
