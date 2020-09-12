#define LED 3

int MapValue = 0;
int SensorValue = 0;

void setup() {
  pinMode(LED, OUTPUT);
  Flash();
  delay(2000);
  for (int i = 0; i < 10  ; i++)
  {
    Flash();
  }
  delay(2000);
}

void loop() {
  SensorValue = analogRead(A1);
  MapValue = map(SensorValue, 0, 1023, 50, 1000);
  digitalWrite(LED, !digitalRead(LED));
  delay(MapValue);
}

void Flash()
{
  digitalWrite(LED, HIGH);
  delay(50);
  digitalWrite(LED, LOW);
  delay(100);
}
