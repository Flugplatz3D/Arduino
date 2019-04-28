float EMA_ALPHA = 0.05;
int EMA_LP = 0;
int EMA_HP = 0;

int sensorPin = A0;
int ledPin = 2;
int placaPin = 13;
int sensorValue = 0;
int sensorValueF = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  sensorValueF = EMALowPassFilter(sensorValue);
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.println(sensorValueF);
  //  delayMicroseconds(1800);
  //  delay(19);
  //  delayMicroseconds(9800);
  if (sensorValueF < 800)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW );
  }
}

int EMALowPassFilter(int value)
{
  EMA_LP = EMA_ALPHA * value + (1 - EMA_ALPHA) * EMA_LP;
  return EMA_LP;
}
