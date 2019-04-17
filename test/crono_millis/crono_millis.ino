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
}

void loop() {
  inString = "";
  time2 = millis();
  Serial.print(time2, DEC);
  Serial.print(" - ");
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
  Serial.println(inString);
  //int SensorValue0 = analogRead(0);
  //Serial.print(" - ");
  //Serial.print(SensorValue0, DEC);
  //int SensorValue1 = analogRead(1);
  //Serial.print(" - ");
  //Serial.println(SensorValue1, DEC);
  //  digitalWrite(13, bitRead(millis(), 9));
  //  Serial.println(millis());
  //    digitalWrite(13, !digitalRead(13));
  delay(150);
  digitalWrite(13, !digitalRead(13));
}
