//#define LED PB1
//#define LED 17
#define LED 13
//#define LED PC13
unsigned long segundo = 0;
unsigned long minuto = 0;
unsigned long hora = 0;
unsigned long segundot = 0;
unsigned long minutot = 0;
unsigned long time1 = 0;
char output[30];

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  time1 = millis();
  segundo = time1 / 1000;
  minuto = segundo / 60;
  hora = minuto / 60;
  minutot = minuto - (hora * 60);
  segundot = segundo - (minuto * 60);
  sprintf(output, "%02d:%02d:%02d - %lu", (int)hora, (int)minutot, (int)segundot, time1);
  Serial.println(output);
  delay(500);
  digitalWrite(LED, !digitalRead(LED));
}
