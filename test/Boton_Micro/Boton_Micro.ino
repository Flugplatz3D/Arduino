const int buttonPin = 10;
int boton = 0;
bool pulsado = true;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  boton = digitalRead(buttonPin);
  if (boton == 0 && !pulsado)
  {
    pulsado = true;
    Serial.println("pulsado");
    delay(50);
  }
  else
  {
    pulsado = false;
  }
}
