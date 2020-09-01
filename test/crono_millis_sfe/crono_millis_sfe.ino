byte m = 0;
unsigned long segundo = 0;
unsigned long minuto = 0;
unsigned long hora = 0;
unsigned long segundot = 0;
unsigned long minutot = 0;

unsigned long time1 = 0;
unsigned long time2 = 0;
String inString = "";

void setup() {
  Serial.begin(9600);
  Comando(134); //luz_on
  BorraP();
  Serial.print("Hola Mundo");
  delay(3000);
  Comando(135); //luz_off
  BorraP();
}

void loop() {
  //BorraP();
  Cursor(0,0);
  Serial.print(millis(),DEC);
  time1 = millis();
  time2 = time1;
  inString = "";
  segundo = time1 / 1000;
  minuto = segundo / 60;
  hora = minuto / 60;
  minutot = minuto - (hora * 60);
  segundot = segundo - (minuto * 60);
  inString += hora;
  inString += ":";
  inString += minutot;
  inString += ":";
  inString += segundot;
  Cursor(1,0);
  Serial.print(inString);
  digitalWrite(13, bitRead(time2, 8));
  delay(100);
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
