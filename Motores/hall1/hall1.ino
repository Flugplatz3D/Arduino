const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0;
int cuenta = 0;
unsigned long time1 = 0;
unsigned long time2 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  Serial.println("Esperando iman...");
  time1 = millis();
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    time1 = millis() - time1;
    cuenta ++;
    Serial.print(cuenta);
    Serial.print(" - " );
    Serial.println(time1);
    while (buttonState == LOW)
    {
      buttonState = digitalRead(buttonPin);
      delay(25);
    }
  }
  //    Serial.println(buttonState);
}
