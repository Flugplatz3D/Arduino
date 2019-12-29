int sensorPinLeft = A0;
int sensorPinFront = A2;
int sensorPinRight = A4;
int sensorLeft = 0;
int sensorFront = 0;
int sensorRight = 0;
int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorLeft = analogRead(sensorPinLeft);
  sensorFront = analogRead(sensorPinFront);
  sensorRight = analogRead(sensorPinRight);
  //outputValue = map(sensorValue, 0, 1023, 0, 255);
  Serial.print("I ");
  Serial.print(sensorLeft);
  Serial.print(" F ");
  Serial.print(sensorFront);
  Serial.print(" D ");
  Serial.println(sensorRight);
  //delay(200);
  digitalWrite(ledPin, !digitalRead(ledPin));
}
