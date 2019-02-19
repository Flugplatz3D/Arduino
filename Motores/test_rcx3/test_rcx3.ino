//Control de 2 motores chasis tipo oruga con un TB6612FNG
//descodificando la señal de un receptor PWM de Radiocontrol

//pines Canales 1,2 y 3 del receptor RC
#define canal1 10
#define canal2 11
#define canal3 12

//pines control TB6612FNG
#define AIN1 2
#define AIN2 4
#define PWMA 5
#define BIN1 7
#define BIN2 8
#define PWMB 6
#define STBY 9

#define LED 13

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
  pinMode (LED, OUTPUT);
  pinMode (AIN1, OUTPUT);
  pinMode (AIN2, OUTPUT);
  pinMode (PWMA, OUTPUT);
  pinMode (BIN1, OUTPUT);
  pinMode (BIN2, OUTPUT);
  pinMode (PWMB, OUTPUT);
  pinMode (STBY, OUTPUT);
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
    tmpA = tmpA * 0.75;
    tmpB = tmpB * 0.75;
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
          motI = motI - tmpA;
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
    analogWrite (PWMA, motD);
    analogWrite (PWMB, motI);
    if (pulsoC > 1500)
    {
      digitalWrite(LED, HIGH);
    }
    else
    {
      digitalWrite(LED, LOW);
    }
    //para depurar
//    inString = "";
//    inString += motI;
//    inString += " : ";
//    inString += motD;
//    inString += " : ";
//    inString += tmpA;
//    inString += " : ";
//    inString += tmpB;
//    inString += " : ";
//    inString += pulsoC;
//    Serial.println(inString);
  }
}

void Front()
{
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  digitalWrite(STBY, HIGH);
}

void Reverse()
{
  digitalWrite(AIN1, HIGH );
  digitalWrite(AIN2, LOW );
  digitalWrite(BIN1, HIGH );
  digitalWrite(BIN2, LOW );
  digitalWrite(STBY, HIGH);
}

void Stop()
{
  digitalWrite(STBY, LOW);
}
