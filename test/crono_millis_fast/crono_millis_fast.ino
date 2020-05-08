void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  Serial.println(millis());
  delay(150);
  digitalWrite(13, !digitalRead(13));
}
