#include <SoftwareSerial.h>

SoftwareSerial mySerial(PA0, PA1); // RX, TX
unsigned long segundo = 0;
unsigned long minuto = 0;
unsigned long hora = 0;
unsigned long segundot = 0;
unsigned long minutot = 0;
unsigned long time1 = 0;
char output[12];
#define LedPlaca PC13

void setup()
{
  pinMode(LedPlaca, OUTPUT);
  digitalWrite(LedPlaca, LOW);
  delay(2000);
  digitalWrite(LedPlaca, HIGH);
  mySerial.begin(9600);
  BorraP();
  Comando(134); //Luz ON
  mySerial.print("Hola Mundo");
  delay(3000);
  BorraP();
}

void loop()
{
  time1 = millis();
  segundo = time1 / 1000;
  minuto = segundo / 60;
  hora = minuto / 60;
  minutot = minuto - (hora * 60);
  segundot = segundo - (minuto * 60);
  Cursor(0, 0);
  mySerial.print(time1);
  Cursor(1, 0);
  sprintf(output, "%02d:%02d:%02d", (int)hora, (int)minutot, (int)segundot);
  mySerial.print(output);
//  delay(500);
  digitalWrite(LedPlaca, !digitalRead(LedPlaca));
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
