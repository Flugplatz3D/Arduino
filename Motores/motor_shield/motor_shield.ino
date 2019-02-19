int dirA = 12;
int dirB = 13;  // not used in this example
int speedA = 10;
int speedB = 11; // not used in this example

void setup()
{
  pinMode (dirA, OUTPUT);
  pinMode (dirB, OUTPUT);
  pinMode (speedA, OUTPUT);
  pinMode (speedB, OUTPUT);
}

void loop()
{
  // move the motor A to one direction increasing speed
  digitalWrite (dirA, HIGH);
  for (int j = 0; j < 255; j += 10) {
    analogWrite (speedA, j);
    delay (100);
  }

  delay(1000); // keep the motor rolling for one second

  // move the motor A to one direction decreasing speed
  digitalWrite (dirA, HIGH);
  for (int j = 255; j >= 0; j -= 10) {
    analogWrite (speedA, j);
    delay (100);
  }

  delay(1000); // keep the motor rolling for one second

  // move the motor A to one direction increasing speed
  digitalWrite (dirA, LOW);
  for (int j = 0; j < 255; j += 10) {
    analogWrite (speedA, j);
    delay (100);
  }

  delay(1000); // keep the motor rolling for one second

  // move the motor A to one direction decreasing speed
  digitalWrite (dirA, LOW);
  for (int j = 255; j >= 0; j -= 10) {
    analogWrite (speedA, j);
    delay (100);
  }
  delay(1000); // keep the motor rolling for one second

  // stop the motor
  digitalWrite(speedA, LOW);

  delay(1000); // keep the motor stopped for one second

}
