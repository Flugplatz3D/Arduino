//#include <SoftwareSerial.h>
char c;
int  LED = 13;

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  while (!Serial.available());
  c = Serial.read();
  if (c == '1') 
  {
    digitalWrite(LED, HIGH);
  }
  if (c == '0') 
  {
    digitalWrite(LED, LOW);
  } 
}
