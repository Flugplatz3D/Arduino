int sensorPin = PA0;    // select the input pin for the potentiometer
int ledPin = 2;
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  if (sensorValue < 975)
  {
    digitalWrite(ledPin, HIGH );
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
  Serial.print("sensor = ");
  Serial.println(sensorValue);
  delay(100);
}
