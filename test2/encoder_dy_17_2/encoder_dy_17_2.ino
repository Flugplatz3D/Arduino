#define LED 17
#define intPin 2
#define controlPin 3

int i = 0, j = 0;
unsigned long time1 = 0;
unsigned long time2 = 0;
char output[50];
byte control = 0;

void intSR()
{
  control = digitalRead(controlPin);
  if (control == 0)
  {
    if (i > 0) i--;
    digitalWrite(LED, HIGH);
  }
  else
  {
    if (i < 99) i++;
    digitalWrite(LED, LOW);
  }
  time1 = millis();
}

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(controlPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(intPin), intSR, RISING);
  //  attachInterrupt(digitalPinToInterrupt(intPin), intSR, FALLING);
}

void loop() {
  if (j != i)
  {
    time2 = time1 - time2;
    sprintf(output, "%u - %u - %lu", i, time2, time1);
    Serial.println(output);
    j = i;
    time2 = time1;
  }
}
