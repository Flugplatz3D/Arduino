byte i = 0;
byte j = 0;
byte k = 0;
double SensorValue = 0;
int an1 = 0;
long mm = 0;
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
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);   // set the LED on
  delay(20);
  digitalWrite(13, LOW);    // set the LED off
  delay(400);
  BorraP();
  
  Comando(140); 
  Comando(4);
  Comando(12);
 
  //Comando(134); //luz_on
  Comando(131); //cursor_on
  Cursor(1,1);
  Serial.print("  Arduino");
  Cursor(2,1);
  Serial.print(" ATMega328");
  Cursor(3,1);
  Serial.print(" SYM 20-AA");
  Cursor(4,1);
  Serial.print("  LCD4x12");
  delay(5000);
  BorraP();
}
void loop() {
  inString = "";
  SensorValue = analogRead(0);
  SensorValue = SensorValue/100;
  time2=millis();
  segundo = millis()/1000;
  minuto = segundo/60;
  hora = minuto/60;
  minutot = minuto - (hora*60);
  segundot = segundo - (minuto*60);
  inString += hora;  
  inString += ":";
  inString += minutot;
  inString += ":";
  inString += segundot;
  inString += "  ";
  Cursor(1,1);
  Serial.println(inString);
  //Serial.println(millis()/1000, DEC);
  an1 = analogRead(1);
  an1 = an1 / 4;
  Cursor(3,1);
  Serial.print(an1, DEC);
  Serial.println("  ");
  analogWrite(9, an1);
  Cursor(2,1);
  Serial.print(SensorValue);
  Serial.println("V");
  if (an1 > 128)
  {
    Comando(134); //luz_on
  }
  else
  {
    Comando(135); //luz_off
  }
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



