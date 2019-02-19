#define canal1 12
#define ledArduino 13

unsigned long pulsoI = 0;
unsigned long iniA = 0;
double expA = 0;
long tmpA = 0;
String inString = "";

void setup()
{
  Serial.begin(9600);
  pinMode(canal1, INPUT);
  pinMode(ledArduino, OUTPUT);
  delay(50);
  digitalWrite(ledArduino, HIGH);
  delay(50);
  digitalWrite(ledArduino, LOW);
  delay(50);
  digitalWrite(ledArduino, HIGH);
  delay(50);
  digitalWrite(ledArduino, LOW);
  delay(50);
  digitalWrite(ledArduino, HIGH);
  delay(200);
  digitalWrite(ledArduino, LOW);
  iniA = pulseIn(canal1, HIGH, 20000);
}

void loop()
{
  pulsoI = pulseIn(canal1, HIGH, 20000);
  tmpA = pulsoI - iniA;
  tmpA = abs(tmpA);
  expA = exp(tmpA/92.036770286);
  inString = "";
  inString += pulsoI;
  inString += " | ";
  inString += iniA;
  inString += " | ";
  inString += tmpA;
  inString += " | ";
  inString += (int)expA;
  Serial.println(inString);
  delay(100);
}





