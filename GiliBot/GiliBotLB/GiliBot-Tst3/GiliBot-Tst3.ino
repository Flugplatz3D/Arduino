int sensorPinLeft = A0;
int sensorPinFront = A1;
int sensorPinRight = A2;
int sensorLeft = 0;
int sensorFront = 0;
int sensorRight = 0;
int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print("I ");
  sensorLeft = analogRead(sensorPinLeft);
  Serial.print(sensorLeft);
  Serial.print(" F ");
  sensorFront = analogRead(sensorPinFront);
  Serial.print(sensorFront);
  Serial.print(" D ");
  sensorRight = analogRead(sensorPinRight);
  Serial.println(sensorRight);
  delay(50);
  digitalWrite(ledPin, !digitalRead(ledPin));
}
