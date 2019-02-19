// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// Rev.4 (06/2012)
// J.Rodrigo ( www.jrodrigo.net )
// more info at www.ardublog.com

#include <Ultrasonic.h>

Ultrasonic ultrasonic(13, 12); // (Trig PIN,Echo PIN)

void setup() {
  Serial.begin(9600);
  Comando(134); //luz_on
  BorraP();
  Serial.print("HC-SR04_lib");
  delay(2000);
  //Comando(135); //luz_off
  BorraP();
}

void loop()
{
  Cursor(0, 0);
  Serial.print(ultrasonic.Ranging(CM)); // CM or INC
  Serial.print(" cm  " );
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
