unsigned long i = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PB1, OUTPUT);
  delay(2000);
  for (i = 1 ; i <= 100000; i++)
  {
    Serial.print(i);
    Serial.print(" -> ");
    Serial.println(MyFunction(i) );
  }
}

void loop() {
  delay(250);
  digitalWrite(PB1, !digitalRead(PB1));
}

unsigned long MyFunction(unsigned long number) {
  //  int factorial = number;
  //  while (number > 1) {
  //    factorial = factorial * (number - 1);
  //    number--;
  //  }
  return number;
}
