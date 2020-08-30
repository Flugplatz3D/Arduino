#define LED 17
#define intPin 1

int i = 0, j = 0;
unsigned long time1 = 0;
unsigned long time2 = 0;
char output[15];

void intSR()
{
  i++;
  time1 = millis();
}

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(intPin), intSR, RISING);
}

void loop() {
  if (j != i)
  {
    j = i;
    sprintf(output, "%u - %u", i, time1 - time2);
    Serial.println(output);
    time2 = time1;
    digitalWrite(LED, !digitalRead(LED));
  }
}
