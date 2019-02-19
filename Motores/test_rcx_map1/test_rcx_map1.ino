#define canal1 2
#define canal2 3
#define minRead -390
#define maxRead 390
#define offset 15

String inString = "";
int ch1, ch2, motD, motI, ini1, ini2;

void setup() {
  Serial.begin(9600);
  pinMode(canal1, INPUT);
  pinMode(canal2, INPUT);
  ini1 = pulseIn(canal1, HIGH);
  ini2 = pulseIn(canal2, HIGH);
}

void loop() {
  ch1 = ini1 - pulseIn(canal1, HIGH);
  ch2 = ini2 - pulseIn(canal2, HIGH);
  if (abs(ch1) < offset) ch1 = 0;
  if (abs(ch2) < offset) ch2 = 0;
  ch1 = constrain(ch1, minRead, maxRead);
  ch2 = constrain(ch2, minRead, maxRead);
  motI = ch2 - ch1;
  motD = ch2 + ch1;
  motI = constrain(motI, minRead, maxRead);
  motD = constrain(motD, minRead, maxRead);
  motI = map(motI, minRead, maxRead, -255, 255);
  motD = map(motD, minRead, maxRead, -255, 255);
  inString = "";
  inString += "I ";
  inString += motI;
  inString += " D ";
  inString += motD;
  Serial.println(inString);
}
