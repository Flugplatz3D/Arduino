byte m = 0;
unsigned long segundo = 0;
unsigned long minuto = 0;
unsigned long hora = 0;
unsigned long segundot = 0;
unsigned long minutot = 0;
int an1 = 0;

unsigned long time1 = 0;
unsigned long time2 = 0;
String inString = "";

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  BorraP();
  Comando(140); 
  Comando(4);
  Comando(12);
  Comando(131); //cursor_on
  Comando(134); //luz_on
  digitalWrite(13, HIGH); // set the LED on
  delay(20);
  digitalWrite(13, LOW); // set the LED off
  delay(400);
  Cursor(1,1);
  Serial.print("  Arduino");
  Cursor(2,1);
  Serial.print("  NoXT 328");
  Cursor(4,1);
  Serial.print("Test Millis");
  delay(5000);
  BorraP();
}

void loop() {
  Cursor(1,1);
  time1 = millis();
  time2 = time1;
  Serial.print(time1, DEC);
  Cursor(2,1);
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
  Serial.println(inString);
  digitalWrite(13, bitRead(time2,9));
  an1 = analogRead(0);
  Cursor(4,1);
  Serial.print(an1, DEC);
  Serial.println("  ");  
  delay(50);
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
