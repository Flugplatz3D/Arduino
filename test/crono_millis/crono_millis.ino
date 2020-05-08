byte m = 0;
unsigned long segundo = 0;
unsigned long minuto = 0;
unsigned long hora = 0;
unsigned long segundot = 0;
unsigned long minutot = 0;

unsigned long time1 = 0;
unsigned long time2 = 0;
String inString = "";

#define LedPlaca 13
#define Led 2

void setup() {
  Serial.begin(9600);
  pinMode(Led, OUTPUT);
  pinMode(LedPlaca, OUTPUT);
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
  delay(300);
  digitalWrite(Led, !digitalRead(Led));
  digitalWrite(LedPlaca, !digitalRead(LedPlaca));
}
