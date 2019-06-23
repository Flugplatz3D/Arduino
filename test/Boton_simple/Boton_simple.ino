const int buttonPin = 12;
const int ledPin = 13;
int boton = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  boton = digitalRead(buttonPin);
  Serial.println(boton);
  if (boton != 0)
  {
    //    digitalWrite(ledPin,!digitalRead(ledPin));
    digitalWrite(ledPin, LOW);
  }
  else
  {
    digitalWrite(ledPin, HIGH);
  }
  delay(50);
}
