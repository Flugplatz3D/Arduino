//Arduino - pins L293 - MicroPro
#define AIN1 2
#define AIN2 3
#define BIN1 4
#define BIN2 5

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
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  //  digitalWrite(9, HIGH);
  //  digitalWrite(10, HIGH);
  analogWrite (9, 255);
  analogWrite (10, 230);
  delay(2000);
  for (i = 0; i < 20  ; i++)
  {
    Flash();
  }
  delay(2000);
}

void loop() {
  for (i = 0; i < 5  ; i++)
  {
    Flash();
  }
  delay(1000);
  digitalWrite(AIN1, HIGH);
  digitalWrite(BIN1, HIGH);
  delay(1000);
  digitalWrite(AIN1, LOW);
  digitalWrite(BIN1, LOW);
  delay(4000);
}

void Flash()
{
  digitalWrite(LED, HIGH);
  delay(25);
  digitalWrite(LED, LOW);
  delay(100);
}
