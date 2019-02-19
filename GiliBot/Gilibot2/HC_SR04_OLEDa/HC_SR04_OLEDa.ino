#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#define ECHOPIN 10                            // Pin to receive echo pulse
#define TRIGPIN 11                            // Pin to send trigger pulse
#define OLED_RESET 4

Adafruit_SH1106 display(OLED_RESET);
long tiempo;
long resultado;

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
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print(distancia());
  display.setCursor(0, 18);
  display.print(millis());
  display.display();
}

long distancia()
{
  digitalWrite(TRIGPIN, LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(TRIGPIN, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo = pulseIn(ECHOPIN, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío*/
  return tiempo;
}
