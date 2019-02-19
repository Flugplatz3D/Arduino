#define LED_Rojo 9
#define LED_Azul 10
#define ECHOPIN 12                            // Pin to receive echo pulse
#define TRIGPIN 13                            // Pin to send trigger pulse

long distancia;
long tiempo;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGPIN, OUTPUT); /*activación del pin 3 como salida: para el pulso ultrasónico*/
  pinMode(ECHOPIN, INPUT); /*activación del pin 2 como entrada: tiempo del rebote del ultrasonido*/
  pinMode(LED_Azul, OUTPUT);
  pinMode(LED_Rojo, OUTPUT);
  Comando(134); //luz_on
  BorraP();
  Serial.print("HC-SR04");
  delay(2000);
  Comando(135); //luz_off
  BorraP();
}

void loop() {
  Cursor(0, 0);
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIGPIN, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  tiempo = pulseIn(ECHOPIN, HIGH);
  distancia = int(0.017 * tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  Serial.print(distancia);
  Serial.print(" cm ");
  if (distancia > 15)
  {
    digitalWrite(LED_Azul, HIGH);
    digitalWrite(LED_Rojo, LOW);
  }
  else if ( distancia <= 12) {
    digitalWrite(LED_Rojo, HIGH);
    digitalWrite(LED_Azul, LOW);
  }
  else
  { digitalWrite(LED_Azul, LOW);
    digitalWrite(LED_Rojo, LOW);
  }
  delay(50);
}

void BorraP() {
  Serial.write(12);
}

void Comando(byte valor) {
  Serial.write(valor);
}

void Cursor(byte fila, byte columna) {
  Serial.write(138);
  Serial.write(fila);
  Serial.write(columna);
}
