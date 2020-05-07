
#define LedPlaca 13

byte i = 0;
byte j = 0;
byte k = 0;
double SensorValue = 0;
int an1 = 0;
unsigned long mm = 0;
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
  pinMode(LedPlaca, OUTPUT);
  BorraP();
  Comando(140);
  Comando(4);
  Comando(12);
  Comando(134); //luz_on
  Comando(131); //cursor_on
  Cursor(1, 1);
  Serial.print("  Arduino");
  Cursor(2, 1);
  Serial.print(" ATMega328");
  Cursor(3, 1);
  Serial.print(" SYM 20-AA");
  Cursor(4, 1);
  Serial.print("  LCD4x12");
  delay(3000);
  BorraP();
}
void loop() {
  inString = "";
  //SensorValue = analogRead(0);
  //SensorValue = SensorValue/100;
  time2 = millis();
  segundo = millis() / 100;
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
  Serial.print(inString);
  Cursor(2, 1);
  Serial.print(time2);
  //an1 = analogRead(1);
  //Cursor(3,1);
  //Serial.print(an1, DEC);
  //Serial.println("  ");
  //Cursor(2,1);
  //Serial.print(SensorValue);
  //Serial.println("V");
  //mm = pulseIn(9, HIGH);
  //Cursor(4,1);
  //Serial.print(mm, DEC);
  //Serial.println("   ");
  //  delay(200);
  digitalWrite(LedPlaca, !digitalRead(LedPlaca));
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
