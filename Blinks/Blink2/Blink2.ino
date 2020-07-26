byte i = 0;
byte j = 0;
byte k = 0;

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(13, OUTPUT);     
}

void loop() {
    for (i = 0; i < 255; i ++)
    {
    analogWrite(9, i);
    delay(10);
    }
    delay(2000);
    for (i = 0; i < 255; i ++)
    {
    analogWrite(10, i);
    delay(10);
    }
    delay(2000);
    for (i = 0; i < 255; i ++)
    {
    analogWrite(11, i);
    delay(10);
    }
    delay(2000);
    for (i = 255; i > 0; -- i)
    {
    analogWrite(9, i);
    delay(10);
    }
    delay(2000);
    for (i = 255; i > 0; -- i)
    {
    analogWrite(10, i);
    delay(10);
    }
    delay(2000);
    for (i = 255; i > 0; -- i)
    {
    analogWrite(11, i);
    delay(10);
    }
    analogWrite(9, 0);
    analogWrite(10, 0);
    analogWrite(11, 0);
    delay(3000);
}
