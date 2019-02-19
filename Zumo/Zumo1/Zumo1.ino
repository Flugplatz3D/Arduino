#define ECHOPIN 2                            // Pin to receive echo pulse
#define TRIGPIN 3                            // Pin to send trigger pulse

int distancia = 0;
int distancia_a = 0;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGPIN, OUTPUT); /*activación del pin 3 como salida: para el pulso ultrasónico*/
  pinMode(ECHOPIN, INPUT); /*activación del pin 2 como entrada: tiempo del rebote del ultrasonido*/
  Serial.println();
  Serial.println("v1");
}

void loop() {
  /*Monitorización en centímetros por el monitor serial*/
  Serial.print("Distancia ");
  Serial.print(LeeSensor());
  Serial.println(" cm");
  delay(250);
}

int LeeSensor()
{
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  distancia = int(0.017 * pulseIn(ECHOPIN, HIGH));
  if (distancia == 0)
  {
    distancia = distancia_a;
  }
  else
  {
    distancia_a = distancia;
  }
  return distancia;
}
