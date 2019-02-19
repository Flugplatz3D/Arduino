//pines Canales 1,2 y 3 del receptor RC
#define canal1 6
#define canal2 7
#define canal3 8

//pines control L298
#define dirRI 11 //1b
#define dirFI 10 //1a
#define speedI 9 //e1

#define dirRD 5
#define dirFD 4
#define speedD 3

#define Faro1 12
#define Faro2 13

String inString = "";
long mxA = 0, mxB = 0;
long tmpA = 0, tmpB = 0;
int motI = 0, motD = 0;
unsigned long pulsoA = 0, pulsoB = 0, pulsoC = 0;
unsigned long iniA = 0, iniB = 0;

void setup() {
  Serial.begin(9600);
  pinMode(canal1, INPUT);
  pinMode(canal2, INPUT);
  pinMode(canal3, INPUT);
  pinMode (dirFI, OUTPUT);
  pinMode (dirRI, OUTPUT);
  pinMode (speedI, OUTPUT);
  pinMode (dirRD, OUTPUT);
  pinMode (dirFD, OUTPUT);
  pinMode (speedD, OUTPUT);
  pinMode(Faro1, OUTPUT);
  pinMode(Faro2, OUTPUT);
  digitalWrite(Faro1, HIGH);
  digitalWrite(Faro2, HIGH);
  while (iniA == 0 || iniB == 0)
  {
    //Espera al encendido del mando capturando el valor
    //inicial de la señal con el joystick centrado
    iniA = pulseIn(canal1, HIGH);
    iniB = pulseIn(canal2, HIGH);
  }
}

void loop() {
  pulsoA = pulseIn(canal1, HIGH);
  pulsoB = pulseIn(canal2, HIGH);
  pulsoC = pulseIn(canal3, HIGH);
  //  pulsoC = pulseIn(canal3, HIGH);
  if (pulsoA != 0 && pulsoB != 0) //solo entra si sigue recibiendo señal
  {
    //se calcula y guarda el valor real de pulso para despues
    //saber en que direccion deben girar los motores
    tmpA = pulsoA - iniA;
    tmpB = pulsoB - iniB;
    mxA = tmpA;
    mxB = tmpB;
    //Valor absoluto calculado para mandar a los PWM del arduino
    tmpA = abs(tmpA);
    tmpB = abs(tmpB);
    //Offset para no responder a la palanca con pequeñas variaciones de la posicion central
    if (tmpA < 30) tmpA = 0;
    if (tmpB < 30) tmpB = 0;
    //Factor de division para bajar la resolucion del joystick
    tmpA = tmpA * 0.8;
    tmpB = tmpB * 0.8;
    //Establecer direccion de giro de los motores en base a la posicion de eje Y del Joystick
    if (tmpB > 0)
    {
      if (mxB > 0)
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

    if (tmpA > 255) tmpA = 255;
    if (tmpB > 255) tmpB = 255;

    motI = tmpB;
    motD = tmpB;

    //Calculo de la mezcla de los motores para obtener el movimiento diferencial
    //Esta parte es muy mejorable.
    //Por ejemplo, para pivotar sobre el eje del tanque que no está implemetado

    if (tmpA > 0)
    {
      if (mxA < 0)
      {
        if (tmpA < motI)
        {
          motI = motI - tmpA ;
        }
        else
        {
          motI = 0;
        }
      }
      else
      {
        if (tmpA < motD)
        {
          motD = motD - tmpA;
        }
        else
        {
          motD = 0;
        }
      }
    }
    //Envio de los valores calculados a los PWM del driver
    analogWrite (speedD, motD);
    analogWrite (speedI, motI);
    if (pulsoC < 1500)
    {
      digitalWrite(Faro1, HIGH);
      digitalWrite(Faro2, HIGH);
    }
    else
    {
      digitalWrite(Faro1, LOW);
      digitalWrite(Faro2, LOW);
    }
    //para depurar
    inString = "";
    inString += motI;
    inString += " : ";
    inString += motD;
    inString += " : ";
    inString += pulsoC;
    Serial.println(inString);
  }
}

void Reverse()
{
  digitalWrite(dirFI, LOW);
  digitalWrite(dirRI, HIGH);
  digitalWrite(dirFD, LOW);
  digitalWrite(dirRD, HIGH);
}

void Front()
{
  digitalWrite(dirFI, HIGH);
  digitalWrite(dirRI, LOW);
  digitalWrite(dirFD, HIGH);
  digitalWrite(dirRD, LOW);
}

void Stop()
{
  digitalWrite(dirFI, LOW);
  digitalWrite(dirRI, LOW);
  digitalWrite(dirFD, LOW);
  digitalWrite(dirRD, LOW);
}
