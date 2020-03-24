byte i = 0;
int SensorValue0, SensorValue1;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  SensorValue0 = analogRead(0);
  SensorValue1 = analogRead(1);
  Serial.print("AN0->");
  Serial.print(SensorValue0, DEC);
  Serial.print("  AN1->");
  Serial.println(SensorValue1, DEC);
  i++;
  delay(50);
}
