#define LED PC13
//#define LED PB1
#define intPin PA0 //PA0-PA8
#define controlPin PA1

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
    if (i < 255) i++;
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
  //  attachInterrupt(digitalPinToInterrupt(intPin), intSR, CHANGE);
}

void loop() {
  if (j != i)
  {
    j = i;
    time2 = time1 - time2;
    sprintf(output, "%u - %u - %lu - %d", i, time2, time1, digitalRead(controlPin));
    Serial.println(output);
    time2 = time1;
  }
}
