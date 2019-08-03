void setup() {
  pinMode(13, OUTPUT);
}
void loop() {
  digitalWrite(13, bitRead(millis(), 9));
}
