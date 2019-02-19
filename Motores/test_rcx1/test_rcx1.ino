#define canal1 2
#define canal2 3
//#define canal3 4

String inString = "";
unsigned long ch1 = 0, ch2 = 0, ch3 = 0;

void setup() {
  Serial.begin(19200);
  pinMode(canal1, INPUT);
  pinMode(canal2, INPUT);
//  pinMode(canal3, INPUT);
}

void loop() {
  ch1 = pulseIn(canal1, HIGH);
  ch2 = pulseIn(canal2, HIGH);
//  ch3 = pulseIn(canal3, HIGH);
  inString = "";
  inString += " ch1 -> ";
  inString += ch1;
  inString += " : ch2 -> ";
  inString += ch2;
//  inString += " : ch3 -> ";
//  inString += ch3;
  Serial.println(inString);
  //delay(100);
}
