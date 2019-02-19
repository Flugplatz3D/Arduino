byte i = 0;
byte j = 0;
byte k = 0;
double SensorValue = 0;
int an1 = 0;
long mm = 0;


void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);   // set the LED on
  delay(10);
  digitalWrite(13, LOW);    // set the LED off
  delay(300);
  BorraP();
  
  Comando(140); 
  Comando(4);
  Comando(12);
 
  Comando(134); //luz_on
  Comando(131); //cursor_on
  Cursor(1,1);
  Serial.print("123456789012345678901234567890123456789012345678");
  delay(5000);
  BorraP();
  Cursor(1,1);
  Serial.print("uno");
  Cursor(2,1);
  Serial.print("dos");
  Cursor(3,1);
  Serial.print("tres");
  Cursor(4,1);
  Serial.print("cuatro");
  delay(5000);
  BorraP();
}
void loop() {
  SensorValue = analogRead(0);
  SensorValue = SensorValue/100;
  Cursor(1,1);
  //Serial.print("ms->");
  Serial.println(millis(), DEC);
  an1 = analogRead(1);
  an1 = an1 / 4;
  Cursor(3,1);
  Serial.print(an1, DEC);
  Serial.println("  ");
  analogWrite(9, an1);
  Cursor(2,1);
  Serial.print(SensorValue);
  Serial.println("V");
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



