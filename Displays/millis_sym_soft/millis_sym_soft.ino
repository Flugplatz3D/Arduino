#include <SoftwareSerial.h>

unsigned long segundo = 0;
unsigned long minuto = 0;
unsigned long hora = 0;  
unsigned long segundot = 0;
unsigned long minutot = 0;
char output[16];
SoftwareSerial mySerial(2, 3); // RX, TX
//SoftwareSerial mySerial(PA0, PA1); // RX, TX

void setup() {
  mySerial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(20);
  digitalWrite(13, LOW);
  delay(400);
  BorraP();

  Comando(140);
  Comando(2);
  Comando(16);

  Comando(134); //luz_on
  Comando(131); //cursor_on
  Cursor(1, 1);
  mySerial.print("    Arduino");
  Cursor(2, 1);
  mySerial.print("   ATMega328");
  delay(2000);
  BorraP();
}

void loop() {
  segundo = millis() / 1000;
  minuto = segundo / 60;
  hora = minuto / 60;
  minutot = minuto - (hora * 60);
  segundot = segundo - (minuto * 60);
  Cursor(1, 1);
  sprintf(output, "%02d:%02d:%02d", (int)hora, (int)minutot, (int)segundot);
  mySerial.println(output);
  Cursor(2, 1);
  mySerial.println(millis() / 10);
  delay(50);
}

void BorraP() {
  mySerial.write(12);
}

void Comando(byte valor) {
  mySerial.write(valor);
}

void Cursor(byte fila, byte columna) {
  mySerial.write(138);
  mySerial.write(fila);
  mySerial.write(columna);
}
