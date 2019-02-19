int sensorPin = A1;    // select the input pin for the potentiometer
int ledPin = 13;
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(sensorPin);
  sensorValue = analogRead(sensorPin);
  // map it to the range of the analog out:
  //outputValue = map(sensorValue, 0, 1023, 0, 255);
  Serial.print("sensor = ");
  Serial.println(sensorValue);
  delay(100);
}
