#include <DHT.h>

#define DHTPIN D1
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

float h = 0;
float t = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  h = dht.readHumidity();
  t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
  }
  else
  {
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.print("*C ");
    Serial.print("Humedad: ");
    Serial.print(h);
    Serial.println("%  ");
  }
  delay(5000);
}
