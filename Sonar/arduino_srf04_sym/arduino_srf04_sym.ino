#define ECHOPIN 2                            // Pin to receive echo pulse
#define TRIGPIN 3                            // Pin to send trigger pulse
//frente/0/nc/E/S/5
unsigned int distance = 0;

void setup(){
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  BorraP();
  Comando(140); 
  Comando(4);
  Comando(12);
  Comando(131); //cursor_on
  Comando(134); //luz_on
  digitalWrite(13, HIGH);   // set the LED on
  delay(20);
  digitalWrite(13, LOW);    // set the LED off
  delay(400);
  Cursor(1,1);
  Serial.print("Arduino");
  Cursor(2,1);
  Serial.print("SRF-04");
  delay(3000);
  BorraP();
}

void loop(){
  digitalWrite(TRIGPIN, LOW);                   // Set the trigger pin to low for 2uS
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  // Send a 10uS high to trigger ranging
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   // Send pin low again
  distance = pulseIn(ECHOPIN, HIGH);        // Read in times pulse
  distance= distance/58;                        // Calculate distance from time of pulse
  Cursor(1,1);
  Serial.print(millis(), DEC);
  Cursor(2,1);
  Serial.print(distance);
  Serial.print("   ");  
  delay(50);                                    // Wait 50mS before next ranging
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

