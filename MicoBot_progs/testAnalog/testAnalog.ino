int sensorPinA0 = A0;    // select the input pin for the potentiometer
int ledPin = 13;         // select the pin for the LED
int sensorValue = 0;     // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  Serial.print(millis(), DEC);
  Serial.print("...Sensor.AN0->");
  sensorValue = analogRead(sensorPinA0);
  Serial.println(sensorValue, DEC);
  delay(100);
}
