//Arduino - pins L293 - ATMega328p
#define AIN1 12
#define AIN2 13
#define BIN1 11
#define BIN2 10

int i = 0;

void setup() {
  pinMode(AIN1, OUTPUT);
  digitalWrite(AIN1, LOW);
  pinMode(AIN2, OUTPUT);
  digitalWrite(AIN2, LOW);
  pinMode(BIN1, OUTPUT);
  digitalWrite(BIN1, LOW);
  pinMode(BIN2, OUTPUT);
  digitalWrite(BIN2, LOW);
  delay(2000);
}

void loop() {

  for (i = 0; i < 200  ; i++)
  {
    digitalWrite(BIN2, HIGH);
    delay(25);
    digitalWrite(BIN2, LOW);
    delay(75);
  }

}
