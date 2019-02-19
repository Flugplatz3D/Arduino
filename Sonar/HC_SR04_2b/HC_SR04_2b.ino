#define ECHOPIN 10                            // Pin to receive echo pulse
#define TRIGPIN 11                            // Pin to send trigger pulse

long distancia;
long tiempo;

void setup(){
  Serial.begin(9600);
  pinMode(TRIGPIN, OUTPUT); /*activación del pin 3 como salida: para el pulso ultrasónico*/
  pinMode(ECHOPIN, INPUT); /*activación del pin 2 como entrada: tiempo del rebote del ultrasonido*/
}

void loop(){
  digitalWrite(TRIGPIN,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(TRIGPIN, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(ECHOPIN, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
  deja de hacerlo, LOW, la longitud del pulso entrante*/
  distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  /*Monitorización en centímetros por el monitor serial*/
  Serial.print("Distancia ");
  Serial.print(distancia);
  Serial.println(" cm");
  delay(250);
}
