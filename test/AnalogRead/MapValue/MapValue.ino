#define LED 17

char output[30];
int MapValue = 0;
int SensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  SensorValue = analogRead(A0);
  MapValue = map(SensorValue, 0, 1023, 100, 2000);
  sprintf(output, "AN0 -> %d [%d] .. %lu", (int)SensorValue, (int)MapValue, millis());
  Serial.println(output);
  digitalWrite(LED, !digitalRead(LED));
  delay(MapValue);
}
