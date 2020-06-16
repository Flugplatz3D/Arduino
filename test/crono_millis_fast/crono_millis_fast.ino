#define LED 13

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  Serial.println(millis());
  delay(150);
  digitalWrite(LED, bitRead(millis(), 9));
}
