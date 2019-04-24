float EMA_ALPHA = 0.008;
int EMA_LP = 0;
int EMA_HP = 0;

int sensorPin = PA0;
int ledPin = PB11;
int placaPin = PB1;
int sensorValue = 0;
int sensorValueF = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(placaPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  sensorValueF = EMALowPassFilter(sensorValue);
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.println(sensorValueF);
  delayMicroseconds(1800);
  if (sensorValueF < 3700)
  {
    digitalWrite(placaPin, HIGH);
  }
  else
  {
    digitalWrite(placaPin, LOW);
  }
}

int EMALowPassFilter(int value)
{
  EMA_LP = EMA_ALPHA * value + (1 - EMA_ALPHA) * EMA_LP;
  return EMA_LP;
}
