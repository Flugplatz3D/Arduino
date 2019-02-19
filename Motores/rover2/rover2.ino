#define canal1 6
#define canal2 7
#define canal3 8

#define minRead -390
#define maxRead 390
#define offset 20

//pines control L298
#define dirFI 10 //1a
#define dirRI 11 //1b
#define pinMotorI 9 //e1
#define dirFD 4 //2a
#define dirRD 5 //2b
#define pinMotorD 3 //e2

#define Faro1 12
#define Faro2 13

String inString = "";
int pulso1, pulso2, pulso3, motorD, motorI, ini1, ini2;

void setup() {
  Serial.begin(9600);
  pinMode(canal1, INPUT);
  pinMode(canal2, INPUT);
  pinMode(canal3, INPUT);
  pinMode(dirFI, OUTPUT);
  pinMode(dirRI, OUTPUT);
  pinMode(pinMotorI, OUTPUT);
  pinMode(dirRD, OUTPUT);
  pinMode(dirFD, OUTPUT);
  pinMode(pinMotorD, OUTPUT);
  pinMode(Faro1, OUTPUT);
  pinMode(Faro2, OUTPUT);
  while (ini1 == 0 || ini2 == 0)
  {
    //Espera al encendido del mando capturando el valor
    //inicial de la señal con el joystick centrado
    ini1 = pulseIn(canal1, HIGH);
    ini2 = pulseIn(canal2, HIGH);
  }
}

void loop() {
  pulso1 = ini1 - pulseIn(canal1, HIGH);
  pulso2 = ini2 - pulseIn(canal2, HIGH);
  pulso3 = pulseIn(canal3, HIGH);
  if (pulso1 != 0 && pulso2 != 0) //solo entra si sigue recibiendo señal
  {
    if (abs(pulso1) < offset) pulso1 = 0;
    if (abs(pulso2) < offset) pulso2 = 0;
    pulso1 = constrain(pulso1, minRead, maxRead);
    pulso2 = constrain(pulso2, minRead, maxRead);
    motorI = pulso2 - pulso1;
    motorD = pulso2 + pulso1;
    motorI = constrain(motorI, minRead, maxRead);
    motorD = constrain(motorD, minRead, maxRead);
    motorI = map(motorI, minRead, maxRead, -255, 255);
    motorD = map(motorD, minRead, maxRead, -255, 255);
    if (motorI != 0)
    {
      if (motorI > 0)
      {
        FrontI();
      }
      else
      {
        ReverseI();
        motorI = abs(motorI);
      }
    }
    else
    {
      StopI();
    }
    if (motorD != 0)
    {
      if (motorD > 0)
      {
        FrontD();
      }
      else
      {
        ReverseD();
        motorD = abs(motorD);
      }
    }
    else
    {
      StopD();
    }
  }
  //Envio de los valores calculados a los PWM del driver
  analogWrite (pinMotorD, motorD);
  analogWrite (pinMotorI, motorI);
  if (pulso3 > 1500)
  {
    digitalWrite(Faro1, LOW);
    digitalWrite(Faro2, LOW);
  }
  else
  {
    digitalWrite(Faro1, HIGH);
    digitalWrite(Faro2, HIGH);
  }
  inString = "";
  inString += "I ";
  inString += motorI;
  inString += " D ";
  inString += motorD;
  Serial.println(inString);
}

void FrontI()
{
  digitalWrite(dirFI, LOW);
  digitalWrite(dirRI, HIGH);
}

void FrontD()
{
  digitalWrite(dirFD, LOW);
  digitalWrite(dirRD, HIGH);
}

void ReverseI()
{
  digitalWrite(dirFI, HIGH);
  digitalWrite(dirRI, LOW);
}

void ReverseD()
{
  digitalWrite(dirFD, HIGH);
  digitalWrite(dirRD, LOW);
}

void StopI()
{
  digitalWrite(dirFI, LOW);
  digitalWrite(dirRI, LOW);
}

void StopD()
{
  digitalWrite(dirFD, LOW);
  digitalWrite(dirRD, LOW);
}
