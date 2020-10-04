unsigned long segundo = 0;
unsigned long minuto = 0;
unsigned long hora = 0;
unsigned long segundot = 0;
unsigned long minutot = 0;

unsigned long time1 = 0;
char output[12];

#define LedPlaca 17

void setup() {
  Serial.begin(9600);
  pinMode(LedPlaca, OUTPUT);
  digitalWrite(LedPlaca, LOW);
  delay(2000);
  digitalWrite(LedPlaca, HIGH);
}

void loop() {
  time1 = millis();
  segundo = time1 / 1000;
  minuto = segundo / 60;
  hora = minuto / 60;
  minutot = minuto - (hora * 60);
  segundot = segundo - (minuto * 60);
  sprintf(output, "%02d:%02d:%02d", (int)hora, (int)minutot, (int)segundot);
  Serial.println(output);
  delay(100);
  digitalWrite(LedPlaca, !digitalRead(LedPlaca));
}
