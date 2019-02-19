//pines control TB6612FNG
#define AIN1 2
#define AIN2 4
#define PWMA 5
#define PWMB 6
#define BIN1 7
#define BIN2 8
#define STBY 9

#define LED 13

int motI = 0, motD = 0;

void setup() {
  pinMode (LED, OUTPUT);
  pinMode (AIN1, OUTPUT);
  pinMode (AIN2, OUTPUT);
  pinMode (PWMA, OUTPUT);
  pinMode (BIN1, OUTPUT);
  pinMode (BIN2, OUTPUT);
  pinMode (PWMB, OUTPUT);
  pinMode (STBY, OUTPUT);
  delay(1000);
  digitalWrite(LED, HIGH);
  delay(100);
  digitalWrite(LED, LOW);
  delay(100);
  digitalWrite(LED, HIGH);
  delay(100);
  digitalWrite(LED, LOW);
}

void loop() {
  Front();
  motI = 255;
  analogWrite (PWMB, motI);
  delay(1000);
  analogWrite (PWMB, 0);
  delay(1000);
  Reverse();
  analogWrite (PWMB, motI);
  delay(1000);
  analogWrite (PWMB, 0);
  delay(1000);
  Front();
  motD = 255;
  analogWrite (PWMA, motD);
  delay(1000);
  analogWrite (PWMA, 0);
  delay(1000);
  Reverse();
  analogWrite (PWMA, motD);
  delay(1000);
  analogWrite (PWMA, 0);
  delay(1000);
  Front();
  motI = 255;
  motD = 255;
  analogWrite (PWMA, motD);
  analogWrite (PWMB, motI);
  delay(1000);
  analogWrite (PWMA, 0);
  analogWrite (PWMB, 0);
  delay(1000);
  Reverse();
  motI = 255;
  motD = 255;
  analogWrite (PWMA, motD);
  analogWrite (PWMB, motI);
  delay(1000);
  analogWrite (PWMA, 0);
  analogWrite (PWMB, 0);
  delay(1000);
}

void Front()
{
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  digitalWrite(STBY, HIGH);
}

void Reverse()
{
  digitalWrite(AIN1, HIGH );
  digitalWrite(AIN2, LOW );
  digitalWrite(BIN1, HIGH );
  digitalWrite(BIN2, LOW );
  digitalWrite(STBY, HIGH);
}
