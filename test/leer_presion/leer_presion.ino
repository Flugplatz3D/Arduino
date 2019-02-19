float presionActual;                                                                    // Temperatura actual del compresor.

// Variables control datos serie.
char trama [30];
String readString = String(30);
int bytesLeidos;
String control;

const int sensorPresion = A0;                                                          // Lectura sensor presion.
const int ledStatus = 13;

void setup() {

  pinMode(ledStatus, OUTPUT);
  digitalWrite(ledStatus, LOW);
  Serial.begin(9600);                                                                 // Inicializa com por hardware.
  readString = "";

}

void loop() {

  if (Serial.available() > 0) {
    leerPuertoSerie(); //subrutina leer datos serie
  }

  presionActual = lecturaPresion();
  envioNextion();
  delay(100);
}

// Conexion con Nextion.

void envioNextion () {
  int presionParteEntera = presionActual;
  int presionParteDecimal = (presionActual - presionParteEntera) * 100;
  int presionAnalogica = presionActual * 100;
  int presionAnalogicaNextion = map(presionAnalogica, 0, 1000, 0, 271);

  if (presionAnalogicaNextion < 45) {
    presionAnalogicaNextion += 314;
  }
  else {
    presionAnalogicaNextion -= 46;
  }


  Serial.print("z0.val=");
  Serial.print(presionAnalogicaNextion);
  ff();
  Serial.print("n0.val=");
  Serial.print( presionParteEntera);
  ff();
  Serial.print("n1.val=");
  Serial.print( presionParteDecimal);
  ff();
}


// Proceso lectura presion
float lecturaPresion () {
  int presionActual = analogRead(sensorPresion);                                // leer valor analogico sensor presion.
  if (presionActual < 101) presionActual = 101;                                 // Sensor a 0 bares da 0.5Vdc de salida (los obviamos).
  if (presionActual > 920) presionActual = 920;                                 // Serson da 4.5Vdc a 12 bares.
  if (presionActual > 784) presionActual = 784;                                // Sersor limitado a max 10 bares.
  float lecturaSensor = (presionActual - 101) * (12.00 / 819.00);
  // se multiplica por 100 a int y se pasa de nuevo a float para tener solo 2 decimales.
  int ajusteMedida = lecturaSensor * 100;
  return ((float)ajusteMedida / 100);
}


//Convierte de string a hex.
int StrToHex(char str[])
{
  return (int) strtol(str, 0, 16);
}

// leer datos serie.
void leerPuertoSerie () {

  int conta = 0;
  char c = Serial.read();                                                    // Lee dato.
  if (c == '*') {                                                             // Las tramas comienzan con *
    readString = "";
    bytesLeidos = 0;
    do {                                                                     // Blucle hasta final de la trama que es un #.
      if (Serial.available() > 0) {                                         // Si hay dato dispobible ...
        bytesLeidos++;
        c = Serial.read();                                                   // Leemos dato.
        Serial.print(c);                                                     // impresion de testeo. Borrar.
        if (c != '#')trama[bytesLeidos - 1] = c;                             // Si no llego a final de la trama, suma caracter a lo ya reribido.
      }
    } while (c != '#');                                                      // Si no llego ninal trama volvemos hacer el bucle.
    imprimetrama();

  }

}

//Bucle de control
void imprimetrama () {

  Serial.print (" Dato leido : ");
  for (int i = 0; i < bytesLeidos; i++) {
    Serial.print(trama[i]);
  }
}

// Â· 0xff
void ff() {
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}
