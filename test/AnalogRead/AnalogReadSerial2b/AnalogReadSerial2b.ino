byte i = 0;
unsigned long Suma = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  Suma = 0;
  for (i = 0; i < 100; i++)
  {
    Suma = Suma + analogRead(0);
  }
  Suma = Suma / 100;
  Serial.println(Suma, DEC);
  delay(100);
}