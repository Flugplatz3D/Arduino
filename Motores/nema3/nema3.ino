/*
Example sketch to control a stepper motor with A4988 stepper motor driver,
AccelStepper library and Arduino: acceleration and deceleration.
https://www.makerguides.com/a4988-stepper-motor-driver-arduino-tutorial/
*/

// Include the AccelStepper library:
#include <AccelStepper.h>

// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin 11
#define stepPin 12
#define motorInterfaceType 1
#define LedMini 13

// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
  // Set the maximum speed and acceleration:
  stepper.setMaxSpeed(10000);
  stepper.setAcceleration(3000);
  delay(1000);
  Flash();
  delay(1000);
}

void loop() {

  // Set the target position:
  stepper.moveTo(6400);
  // Run to target position with set speed and acceleration/deceleration:
  stepper.runToPosition();

  delay(1000);

  digitalWrite(LedMini, !digitalRead(LedMini));

  // Move back to zero:
  stepper.moveTo(0);
  stepper.runToPosition();

  delay(1000);

  digitalWrite(LedMini, !digitalRead(LedMini));
}

void Flash()
{
  for (int i = 0; i < 25  ; i++)
  {
    digitalWrite(LedMini, HIGH);
    delay(25);
    digitalWrite(LedMini, LOW);
    delay(75);
  }
}
