#include <SoftwareSerial.h>

#define LED 17
#define intPin 2
#define controlPin 3

int i = 0, j = 0;
unsigned long time1 = 0;
unsigned long time2 = 0;
char output[50];
byte control = 0;
SoftwareSerial mySerial(4, 5); // RX, TX

void intSR()
{
  control = digitalRead(controlPin);
  if (control == 0)
  {
    if (i > 0) i--;
    digitalWrite(LED, HIGH);
  }
  else
  {
    if (i < 99) i++;
    digitalWrite(LED, LOW);
  }
  time1 = millis();
}

void setup() {
//  Serial.begin(9600);
  mySerial.begin(9600);
  delay(300);
  BorraP();
  Comando(134); //Luz ON
  mySerial.print("Hola Mundo");
  pinMode(LED, OUTPUT);
  pinMode(controlPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(intPin), intSR, RISING);
  //  attachInterrupt(digitalPinToInterrupt(intPin), intSR, FALLING);
}

void loop() {
  if (j != i)
  {
    time2 = time1 - time2;
//    sprintf(output, "%u-%u-%lu", i, time2, time1);
//    Serial.println(output);
    BorraP();
    //Cursor(0, 0);
    mySerial.print(i);
    Cursor(1, 0);
    mySerial.print(time1);
    j = i;
    time2 = time1;
  }
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
