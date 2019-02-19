#define LED_Rojo 9
#define LED_Azul 10
#define ECHOPIN 12    // Pin to receive echo pulse
#define TRIGPIN 13    // Pin to send trigger pulse

#define STOP 0
#define FWD_DER 128
#define FWD_IZQ 128
#define REV_DER -128
#define REV_IZQ -128

//Declaracion del nombre de ESTADOS y de EVENTOS 913300269
#define ST_LEE_SENSOR  	0x01
#define ESTADO2  	0x02
#define ESTADO3  	0x03
#define ST_AVANZAR  0x04

#define EV_Null     0x40
#define EV_Reset	0x41
#define EV_Front	0x42
#define EV_Stop		0x43
#define EV_Rear		0x44

//unsigned int An0;
unsigned int Radar;
unsigned int miEstado;
unsigned int miEvento;
long distancia;
long tiempo;

void setup() {
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(LED_Azul, OUTPUT);
  pinMode(LED_Rojo, OUTPUT);
  Comando(135); //luz_off
  BorraP();
  Serial.print("FSM_Mio2");
  delay(1500);
  BorraP();
  miEstado = ST_LEE_SENSOR;
  Radar = 9; //parado la primera lectura
}

void LeerEventos() {
  miEvento = 0;
  if (Radar > 10)
  {
    miEvento = EV_Front;
  }
  else if (Radar < 8)
  {
    miEvento = EV_Rear;
  }
  else
  {
    miEvento = EV_Stop;
  }
};

void FSMEstados()
{
  switch (miEstado)
  {
    case ST_LEE_SENSOR:
      {
        switch (miEvento)
        {
          case EV_Stop:
            {
              miEstado = ST_LEE_SENSOR;
              break;
            }
          case EV_Rear:
            {
              miEstado = ESTADO3;
              break;
            }
          case EV_Front:
            {
              miEstado = ST_AVANZAR;
              break;
            }
        }
        break;
        FuncST1();
      }
    case ESTADO2:
      {
        switch (miEvento)
        {
          case EV_Stop:
            {} break;
          case EV_Reset:
            {} break;
        }
        break;
        FuncST2();
      }
    case ESTADO3:
      {
        switch (miEvento)
        {
          case EV_Reset:
            {} break;
        }
        break;
        FuncST3();
      }
    case ST_AVANZAR:
      {
        switch (miEvento)
        {
          case EV_Front:
            {
              miEstado = ST_LEE_SENSOR;
              break;
            }
          default:
            {}
        }
        break;
        FuncST4();
      }
  }
}

void loop() {
  LeerEventos();
  FSMEstados();
}

void FuncST1() {
  Radar = LeeSensorUS();
};

void FuncST2() {
  BorraP();
  digitalWrite(LED_Azul, LOW);
  digitalWrite(LED_Rojo, LOW);
  Cursor(0, 0);
  Serial.print(Radar, DEC);
  Serial.print("  ");
  Cursor(1, 0);
  Serial.print("Parar");
};

void FuncST3() {
  BorraP();
  digitalWrite(LED_Azul, HIGH);
  digitalWrite(LED_Rojo, LOW);
  Cursor(0, 0);
  Serial.print(Radar, DEC);
  Serial.print("  ");
  Cursor(1, 0);
  Serial.print("Retroceder");
};

void FuncST4() {
  BorraP();
  digitalWrite(LED_Azul, LOW);
  digitalWrite(LED_Rojo, HIGH);
  Cursor(0, 0);
  Serial.print(Radar, DEC);
  Serial.print("  ");
  Cursor(1, 0);
  Serial.print("Avanzar");
};

int LeeSensorUS()
{
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIGPIN, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  tiempo = pulseIn(ECHOPIN, HIGH);
  distancia = int(0.017 * tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  return distancia;
}

void BorraP() {
  Serial.write(12);
}

void Comando(byte valor) {
  Serial.write(valor);
}

void Cursor(byte fila, byte columna) {
  Serial.write(138);
  Serial.write(fila);
  Serial.write(columna);
}
