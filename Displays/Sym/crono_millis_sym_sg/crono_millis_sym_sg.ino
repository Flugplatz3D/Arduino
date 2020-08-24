#define LED 0

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
  pinMode(LED, OUTPUT);
  BorraP();
  Comando(140); 
  Comando(4);
  Comando(12);
  Comando(131); //cursor_on
  digitalWrite(LED, HIGH);   // set the LED on
  delay(20);
  digitalWrite(LED, LOW);    // set the LED off
  delay(400);
  Cursor(1,1);
  Serial.print("  Sanguino");
  Cursor(2,1);
  Serial.print(" ATMega644");
  Cursor(3,1);
  Serial.print(" SYM 20-AA");
  Cursor(4,1);
  Serial.print("  LCD4x12");
  delay(3000);
  BorraP();
}

void loop() {
  Cursor(1,1);
  time2=millis();
  Serial.print(time2, DEC);
  Cursor(2,1);
  inString = "";
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
  Serial.println(inString);
  m = time2/1000;
  if (m==0)
  {
    digitalWrite(LED, HIGH);   // set the LED on
    delay(5);              // wait for a second
    digitalWrite(LED, LOW);    // set the LED off
  }
  //delay(100);
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

