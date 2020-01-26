#define LED 17
const int buttonPin = 7;
int boton = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  boton = digitalRead(buttonPin);
  if (boton == 0)
  {
    digitalWrite(LED, LOW);
    delay(100);
    Serial.print(millis());
    Serial.println(" - pulsado");
    delay(5000);
    Serial.print(millis());
    Serial.println(" - fin");
    digitalWrite(LED, HIGH);
  }
}
