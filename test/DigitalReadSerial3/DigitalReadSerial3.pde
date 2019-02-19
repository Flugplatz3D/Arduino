int pulseX;
bool pp = true;

void setup() {
  Serial.begin(9600);
  pinMode(10,INPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  pulseX = pulseIn(10, HIGH, 15000);
  Serial.println(pulseX, DEC);
  if (pulseX != 0)
  {
    if (pulseX > 1500)
    {
      pp = true;
    } else
    {
      pp = false;
    }
  }
  if (pp == true)
  {
    digitalWrite(11, HIGH);   // set the LED on
    delay(50);              // wait for a second
    digitalWrite(11, LOW);    // set the LED off
    delay(200);
    digitalWrite(13, HIGH);   // set the LED on
    delay(50);              // wait for a second
    digitalWrite(13, LOW);    // set the LED off
    delay(200);
    digitalWrite(12, HIGH);   // set the LED on
    delay(50);              // wait for a second
    digitalWrite(12, LOW);    // set the LED off
    delay(200);
    digitalWrite(12, HIGH);
    delay(50);
    digitalWrite(12, LOW);
    delay(600);
  } else
  {
    delay(100);    
  }
}
