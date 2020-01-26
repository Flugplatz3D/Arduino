const int buttonPin = 7;
int boton = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  boton = digitalRead(buttonPin);
  if (boton == 0)
  {
    delay(100);
    Serial.print(millis());
    Serial.println(" - pulsado");
    delay(5000);
    Serial.print(millis());
    Serial.println(" - fin");
  }
}
