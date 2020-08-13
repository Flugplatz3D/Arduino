#define LED 13
#define Externo 10
#define Interno 50000000
unsigned long parcial = 0;
float resultado = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.println(Externo);
  Serial.println(Interno);
  delay(1000);
}

void loop() {
  parcial = millis();
  Serial.print("\nParcial -> ");
  Serial.println(parcial);
  for (unsigned long i = 1; i <= Externo; i++)
  {
    resultado = 0;
    for (unsigned long j = 1; j <= Interno; j++)
    {
      resultado = (j * 0.25) / 8;
      //      Serial.print(i);
      //      Serial.print("\t");
      //      Serial.print(j);
      //      Serial.print("\t");
      //delayMicroseconds(1);
    }
    Serial.println(resultado);
  }
  Serial.print("Milisegundos -> ");
  Serial.println(millis() - parcial);
  delay(5000);
}
