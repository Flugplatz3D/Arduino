#define LED 13

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  Serial.println(millis());
  delay(50);
  digitalWrite(LED, !digitalRead(LED));
}
