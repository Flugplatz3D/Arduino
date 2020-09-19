//#define LED PC13
#define LED PB1
#define intPin PB3 //PA0-PA8 PB0 PB12 PB13 PA15

int i = 0, j = 0;
unsigned long time1 = 0;
unsigned long time2 = 0;
char output[50];

void intSR()
{
  i++;
  time1 = millis();
}

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  //  attachInterrupt(digitalPinToInterrupt(intPin), intSR, RISING);
  attachInterrupt(digitalPinToInterrupt(intPin), intSR, FALLING);
  //  attachInterrupt(digitalPinToInterrupt(intPin), intSR, CHANGE);
}

void loop() {
  if (j != i)
  {
    j = i;
    time2 = time1 - time2;
    sprintf(output, "%u - %u - %lu", i, time2, time1);
    Serial.println(output);
    time2 = time1;
    digitalWrite(LED, !digitalRead(LED));
  }
}
