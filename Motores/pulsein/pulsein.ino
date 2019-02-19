#define canal1 11
#define canal2 12
#define ledArduino 13
#define dirFI 5
#define dirRI 6
#define speedI 9
#define dirFD 7
#define dirRD 8
#define speedD 10

unsigned long pulsoI = 0, pulsoD = 0;
unsigned long iniA = 0, iniB = 0;
long mxA = 0, mxB = 0;
long tmpA = 0, tmpB = 0;
int motI = 0, motD = 0;
String inString = "";

void setup()
{
  Serial.begin(9600);
  pinMode(canal1, INPUT);
  pinMode(canal2, INPUT);
  pinMode(ledArduino, OUTPUT);
  pinMode (dirFI, OUTPUT);
  pinMode (dirRI, OUTPUT);
  pinMode (dirRD, OUTPUT);
  pinMode (dirFD, OUTPUT);
  while (iniA == 0 || iniB == 0)
  {
    iniA = pulseIn(canal1, HIGH, 20000);
    iniB = pulseIn(canal2, HIGH, 20000);
    delay(50);
    digitalWrite(ledArduino, HIGH);
    delay(50);
    digitalWrite(ledArduino, LOW);	
  }
}

void Front()
{
  digitalWrite(dirFI, LOW);
  digitalWrite(dirRI, HIGH);
  digitalWrite(dirFD, LOW);
  digitalWrite(dirRD, HIGH);
}

void Stop()
{
  digitalWrite(dirFI, LOW);
  digitalWrite(dirRI, LOW);
  digitalWrite(dirFD, LOW);
  digitalWrite(dirRD, LOW);
}

void Reverse()
{
  digitalWrite(dirFI, HIGH);
  digitalWrite(dirRI, LOW);
  digitalWrite(dirFD, HIGH);
  digitalWrite(dirRD, LOW);
}

void loop()
{
  pulsoI = pulseIn(canal1, HIGH, 20000);
  pulsoD = pulseIn(canal2, HIGH, 20000);
  if (pulsoI != 0 && pulsoD != 0)
  {
    tmpA = pulsoI - iniA;
    tmpB = pulsoD - iniB;
    mxA = tmpA;
    mxB = tmpB;
    tmpA = abs(tmpA);
    tmpB = abs(tmpB);
    if (tmpA <= 50) tmpA = 0;	
    if (tmpB <= 50) tmpB = 0;
    if (tmpA > 0)
    {
      if (mxA > 0)
      {
        Front();
      }
      else
      {
        Reverse();
      }
    }
    else
    {
      Stop();
    }

    if (tmpA > 0) tmpA = tmpA - 50;
    if (tmpA > 255) tmpA = 255;

    motI = tmpA;
    motD = tmpA;

    if (tmpB > 0) tmpB = tmpB - 50;
    if (tmpB > 255) tmpB = 255;

    if (tmpB > 0)
    {
      if (mxB < 0)
      {
        if (tmpB < motD)
        {
          motD = motD - tmpB;
        }
        else
        {
          motD = 0;
        }
      }
      else
      {
        if (tmpB < motI)
        {
          motI = motI - tmpB;
        }
        else
        {                          
          motI = 0;
        }
      }
    }
    analogWrite (speedI, motI);
    analogWrite (speedD, motD);

    inString = "";
    inString += pulsoI;  
    inString += " : ";
    inString += pulsoD;
    inString += " | ";
    inString += iniA;
    inString += " : ";
    inString += iniB;
    inString += " | ";
    inString += tmpA;
    inString += " : ";
    inString += tmpB;
    inString += " | ";
    inString += motI;
    inString += " : ";
    inString += motD;
    Serial.println(inString);

    delay(100);
  }
  else
  {
    Stop();
    analogWrite (0, motI);
    analogWrite (0, motD);
    delay(300);
    digitalWrite(ledArduino, HIGH);
    delay(300);
    digitalWrite(ledArduino, LOW);		
  }
}



