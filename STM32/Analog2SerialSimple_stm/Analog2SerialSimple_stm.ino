byte i = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PC13, OUTPUT);
}

void loop() {
  int SensorValue = analogRead(PA0);
  Serial.print("Contador.i->");
  Serial.print(i, DEC);
  Serial.print("...AN0->");
  Serial.println(SensorValue, DEC);
  i++;
  digitalWrite(PC13, HIGH);   // set the LED on
  delay(100);
  digitalWrite(PC13, LOW);    // set the LED off
  delay(10);
}
