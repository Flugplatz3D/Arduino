byte i = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  int SensorValue = analogRead(0);
  Serial.print("Contador.i->");
  Serial.print(i, DEC);
  Serial.print("...AN0->");
  Serial.println(SensorValue, DEC);
  i++;
  //digitalWrite(13, HIGH);   // set the LED on
  //delay(10);
  //digitalWrite(13, LOW);    // set the LED off
  delay(100);
}
