#define LED 17

char output[15];

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  int SensorValue = analogRead(A0);
  sprintf(output, "AN0 -> %d -- %lu", (int)SensorValue, millis());
  Serial.println(output);
  digitalWrite(LED, LOW);   // set the LED on
  delay(10);
  digitalWrite(LED, HIGH);    // set the LED off
  delay(100);
}
