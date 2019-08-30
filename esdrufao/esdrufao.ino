//Arduino - pins L293 - ATMega328p
#define AIN1 3
#define AIN2 2
#define BIN1 5
#define BIN2 4

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
  for (i = 0; i < 1000  ; i++)
  {
    digitalWrite(AIN1, HIGH);
    delay(1);
    digitalWrite(AIN1, LOW);
    delay(3);
  }
  for (i = 0; i < 1000  ; i++)
  {
    digitalWrite(AIN2, HIGH);
    delay(1);
    digitalWrite(AIN2, LOW);
    delay(3);
  }
  for (i = 0; i < 1000  ; i++)
  {
    digitalWrite(BIN1, HIGH);
    delay(1);
    digitalWrite(BIN1, LOW);
    delay(3);
  }
  for (i = 0; i < 1000  ; i++)
  {
    digitalWrite(BIN2, HIGH);
    delay(1);
    digitalWrite(BIN2, LOW);
    delay(3);
  }
}

void loop() {



}
