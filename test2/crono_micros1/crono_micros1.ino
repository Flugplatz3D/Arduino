#define LED 17
#define buttonPin 2

int buttonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  digitalWrite(LED , !buttonState);
//  Serial.println(buttonState);
//  delay(100);
}
