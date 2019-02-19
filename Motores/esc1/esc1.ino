int an0 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  delay(200);
  Serial.println("Test ESC1");
  delay(3000);
}
void loop() {
  an0 = analogRead(0);
  an0 = an0/4;
  digitalWrite(13, bitRead(millis(),9));
  Serial.print(millis());
  Serial.print("  ");
  Serial.println(an0, DEC);
  analogWrite(10, an0);  
  delay(100);
}
