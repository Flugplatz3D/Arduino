//Arduino - pins L293 - MicroPro
#define AIN1 3
#define AIN2 2
#define BIN1 5
#define BIN2 4

#define LED 13

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
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  delay(2000);
  for (i = 0; i < 20  ; i++)
  {
    Flash();
  }
  delay(2000);
}

void loop() {
  for (i = 0; i < 1000  ; i++)
  {
    digitalWrite(AIN1, HIGH);
    digitalWrite(BIN1, HIGH);
    delay(1);
    digitalWrite(AIN1, LOW);
    digitalWrite(BIN1, LOW);
    delay(1);
  }
  delay(1000);
  Flash();
  for (i = 0; i < 500  ; i++)
  {
    digitalWrite(AIN2, HIGH);
    digitalWrite(BIN2, HIGH);
    delay(1);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN2, LOW);
    delayMicroseconds(1080);
  }
  delay(1000);
}

void Flash()
{
  digitalWrite(LED, HIGH);
  delay(25);
  digitalWrite(LED, LOW);
  delay(100);
}
