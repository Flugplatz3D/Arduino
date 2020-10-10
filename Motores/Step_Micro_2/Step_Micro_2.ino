// Código Arduino/Genuino para ubicar un motor por pasos/steeper motor 28BYJ-48 en diferentes posiciones preestablecidas

#include <AccelStepper.h>  // Incluimos la biblioteca AccelStepper
#define HALFSTEP 8 // Definimos HALFSTEP 8 para poder usar el motor por pasos/steeper motor 28BYJ-48
#define LED 17

#define motorPin1 6 // Pin 1 en el pin IN1 del driver ULN2003
#define motorPin2 7 // Pin 2 en el pin IN2 del driver ULN2003
#define motorPin3 8 // Pin 3 en el pin IN3 del driver ULN2003
#define motorPin4 9 // Pin 4 en el pin IN4 del driver ULN2003

AccelStepper stepper(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);

void setup()
{
  pinMode(LED, OUTPUT);
  delay(2000);
  for (int i = 0; i < 10  ; i++)
  {
    Flash();
  }
  delay(2000);
  stepper.setMaxSpeed(750.0); // velocidad máxima
  stepper.setAcceleration(750.0); // aceleración
}

void loop()
{
  digitalWrite(LED, LOW);
  stepper.runToNewPosition(3000);
  delay(1000);
  digitalWrite(LED, HIGH);
  stepper.runToNewPosition(0);
  delay(1000);
}

void Flash()
{
  digitalWrite(LED, LOW);
  delay(50);
  digitalWrite(LED, HIGH );
  delay(100);
}
