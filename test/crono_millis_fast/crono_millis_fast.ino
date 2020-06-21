#define LED 13

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  Serial.println(millis());
  delay(200);
  digitalWrite(LED, bitRead(millis(), 10));
}
