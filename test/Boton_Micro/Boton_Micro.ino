const int buttonPin = 10;
int boton = 0;
bool pulsado = false;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  boton = digitalRead(buttonPin);
  if (boton == 0)
  {
    if (!pulsado)
    {
      pulsado = true;
      Serial.print(millis());
      Serial.println(" - pulsado");
      delay(200);
    }
  }
  else
  {
    pulsado = false;
  }
}
