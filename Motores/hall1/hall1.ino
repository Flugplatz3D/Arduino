const int sensorPin = 2;
int sensorState = 0;
int reads = 0;
int suma = 0;
unsigned long timeActual = 0;
unsigned long timeAnterior = 0;
unsigned long timeResta = 0;
unsigned long timeRestaEMA = 0;
float EMA_ALPHA = 0.5;
int EMA_LP = 400;
float rpm;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  timeActual = millis();
}

void loop() {
  sensorState = digitalRead(sensorPin);
  if (sensorState == HIGH) {
    timeActual = millis();
    timeResta = timeActual - timeAnterior;
    timeAnterior = timeActual;
    timeRestaEMA = EMALowPassFilter(timeResta);
    while (sensorState == HIGH)
    {
      sensorState = digitalRead(sensorPin);
      delay(20);
    }
    suma = suma + timeRestaEMA;
    reads ++;
    if (reads > 3)
    {
      rpm = 60 * (1.0 / ((float)suma / 1000.0));
      Serial.print(timeRestaEMA);
      Serial.print(" - ");
      Serial.println(rpm, 2);
      reads = 1;
      suma = 0;
    }
  }
}

int EMALowPassFilter(int value)
{
  EMA_LP = EMA_ALPHA * value + (1 - EMA_ALPHA) * EMA_LP;
  return EMA_LP;
}
