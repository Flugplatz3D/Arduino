#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#define ECHOPIN 10                            // Pin to receive echo pulse
#define TRIGPIN 11                            // Pin to send trigger pulse
#define OLED_RESET 4

Adafruit_SH1106 display(OLED_RESET);
long distancia;
long tiempo;

void setup() {
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x64)
  // init done
  // Clear the buffer.
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  pinMode(TRIGPIN, OUTPUT); /*activación del pin 3 como salida: para el pulso ultrasónico*/
  pinMode(ECHOPIN, INPUT); /*activación del pin 2 como entrada: tiempo del rebote del ultrasonido*/
}

void loop() {
  digitalWrite(TRIGPIN, LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(TRIGPIN, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo = pulseIn(ECHOPIN, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
//  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
//  deja de hacerlo, LOW, la longitud del pulso entrante*/
  distancia = int(0.017 * tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  /*Monitorización en centímetros por el monitor serial*/
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print(tiempo);
  display.setCursor(0, 18);
  display.print(distancia);
  display.display();
  //delay(50);
}
