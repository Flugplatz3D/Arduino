//byte i=0;
long i=0;
unsigned long time1=0;
unsigned long time2=0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  Serial.print("Contador->");
  Serial.println(i, DEC);
  i++;
  if (i==500)
  {
    time2=millis();
    Serial.print(time2, DEC);
    Serial.print("->");
    time1=time2-time1;
    Serial.println(time1, DEC);    
    time1=time2;
    i=0;
    digitalWrite(13, HIGH);   // set the LED on
    delay(5000);              // wait for a second
    digitalWrite(13, LOW);    // set the LED off
  }
  else
  {
    digitalWrite(13, HIGH);   // set the LED on
    delay(1);              // wait for a second
    digitalWrite(13, LOW);    // set the LED off
    delay(50);
  }
}

