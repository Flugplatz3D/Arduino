long distancia;
long tiempo;
void setup(){
  Serial.begin(9600);
  pinMode(9, OUTPUT); /*activaci�n del pin 9 como salida: para el pulso ultras�nico*/
  pinMode(8, INPUT); /*activaci�n del pin 8 como entrada: tiempo del rebote del ultrasonido*/
}

void loop(){
  digitalWrite(9,LOW); /* Por cuesti�n de estabilizaci�n del sensor*/
  delayMicroseconds(5);
  digitalWrite(9, HIGH); /* env�o del pulso ultras�nico*/
  delayMicroseconds(10);
  tiempo=pulseIn(8, HIGH); /* Funci�n para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el env�o
  del pulso ultras�nico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
  deja de hacerlo, LOW, la longitud del pulso entrante*/
  distancia= int(0.017*tiempo); /*f�rmula para calcular la distancia obteniendo un valor entero*/
  /*Monitorizaci�n en cent�metros por el monitor serial*/
  Serial.println("Distancia ");
  Serial.println(distancia);
  Serial.println(" cm");
  delay(1000);
}