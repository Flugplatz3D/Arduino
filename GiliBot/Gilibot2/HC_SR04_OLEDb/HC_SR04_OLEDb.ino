#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SparkFun_TB6612.h>

#define ECHOPIN 10                            // Pin to receive echo pulse
#define TRIGPIN 11                            // Pin to send trigger pulse
#define OLED_RESET 4
#define AIN1 2
#define BIN1 7
#define AIN2 4
#define BIN2 8
#define PWMA 5
#define PWMB 6
#define STBY 9

// these constants are used to allow you to make your motor configuration
// line up with function names like forward.  Value can be 1 or -1
const int offsetA = 1;
const int offsetB = 1;
int i;

// Initializing motors.  The library will allow you to initialize as many
// motors as you have memory for.  If you are using functions like forward
// that take 2 motors as arguements you can either write new functions or
// call the function more than once.
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

Adafruit_SSD1306 display(OLED_RESET);
long tiempo;
long resultado;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print("Gilibot2");
  display.setTextSize(1);
  display.setCursor(0, 22);
  display.print("MVC-Version 1.0");
  display.display();
  pinMode(TRIGPIN, OUTPUT); /*activación del pin 3 como salida: para el pulso ultrasónico*/
  pinMode(ECHOPIN, INPUT); /*activación del pin 2 como entrada: tiempo del rebote del ultrasonido*/
  for (i = 0; i < 75; i++)
  {
    motor1.drive(i, 5);
    motor2.drive(i, 5);
  }
  delay(500);
  for (i = 75; i > 0; i--)
  {
    motor1.drive(i, 5);
    motor2.drive(i, 5);
  }
  motor1.brake();
  motor2.brake();
  delay(500);
}

void loop() {
  display.clearDisplay();
  display.setTextSize(2);
  volcarDatos(distancia(), 1);
  display.setTextSize(1);
  volcarDatos(millis(), 2);
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

void volcarDatos(long valor, byte linea)
{
  switch (linea)
  {
    case 1:
      {
        display.setCursor(0, 0);
        display.print(valor);
        break;
      }
    case 2:
      {
        display.setCursor(0, 22);
        display.print(valor);
        break;
      }
  }
}

