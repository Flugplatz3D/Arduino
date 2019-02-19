word i = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);   // set the LED on
  delay(10);
  digitalWrite(13, LOW);    // set the LED off
  delay(100);
  Comando(134); //luz_on
  Comando(131); //cursor_on
}
void loop() {
  Cursor(1,1);
  int SensorValue = analogRead(0);
  Serial.print("Contador->");
  Serial.println(i, DEC);
  Cursor(2,1);
  Serial.print("Bateria->");
  Serial.println(SensorValue, DEC);
  i++;
  if (i==0) BorraP();
  //delay(20);
}

void BorraP(){
  Serial.write(12);
}

void Comando(byte valor){
  Serial.write(valor);
}

void Cursor(byte fila, byte columna){
  Serial.write(138);
  Serial.write(fila);
  Serial.write(columna);
}



