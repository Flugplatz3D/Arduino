#include <SoftwareSerial.h>

unsigned long segundo = 0;
unsigned long minuto = 0;
unsigned long hora = 0;
unsigned long segundot = 0;
unsigned long minutot = 0;
char output[12];
String inString = "";
SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
  mySerial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);   // set the LED on
  delay(20);
  digitalWrite(13, LOW);    // set the LED off
  delay(400);
  BorraP();

  Comando(140);
  Comando(4);
  Comando(12);

  Comando(134); //luz_on
  Comando(131); //cursor_on
  Cursor(1, 1);
  mySerial.print("  Arduino");
  Cursor(2, 1);
  mySerial.print(" ATMega328");
  Cursor(3, 1);
  mySerial.print(" SYM 20-AA");
  Cursor(4, 1);
  mySerial.print("  LCD4x12");
  delay(2000);
  BorraP();
}

void loop() {
  inString = "";
  segundo = millis() / 1000;
  minuto = segundo / 60;
  hora = minuto / 60;
  minutot = minuto - (hora * 60);
  segundot = segundo - (minuto * 60);
  inString += hora;
  inString += ":";
  inString += minutot;
  inString += ":";
  inString += segundot;
  inString += "  ";
  Cursor(1, 1);
  mySerial.println(inString);
  Cursor(2, 1);
  sprintf(output, "%02d:%02d:%02d", (int)hora, (int)minutot, (int)segundot);
  mySerial.println(output);
  Cursor(3, 1);
  mySerial.println(millis() / 10);
  //  delay(150);
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
