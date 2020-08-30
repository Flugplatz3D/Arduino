#define LED 17
#define intPin 1

int i = 0, j = 0;

void intSR()
{
  i++;
}

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(intPin), intSR, RISING);
}

void loop() {
  if (j != i)
  {
    Serial.println(i);
    j = i;
    digitalWrite(LED, !digitalRead(LED));
  }
}
