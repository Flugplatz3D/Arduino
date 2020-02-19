#include <FiniteStateMachine.h>
//http://playground.arduino.cc/Code/FiniteStateMachine

State noop = State(noopUpdate);  //no operation
State chocar = State(chocarEnter, chocarUpdate, NULL);
State parar = State(pararEnter, pararUpdate, NULL);

unsigned long parcial = 0;

float EMA_ALPHA = 0.05;
int EMA_LP = 0;
int EMA_HP = 0;

int sensorPin = A0;
int sensorValue = 0;
int sensorValueF = 0;

FSM stateMachine = FSM(noop); //initialize state machine, start in state: noop

#define LED 13

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  delay(1000);
  Serial.println("");
  parcial = millis();
  stateMachine.transitionTo(chocar);
}

void loop() {
  stateMachine.update();
}

//[noop state:update] the state machine is in a state that does nothing
void noopUpdate() {
}

void chocarEnter() {
  Serial.println(__FUNCTION__);
  delay(2000);
}

void chocarUpdate() {
  Serial.print(millis());
  Serial.print(" - ");
  Serial.println(__FUNCTION__);
  delay(2000);
  stateMachine.transitionTo(parar);
}
void pararEnter() {
  //  digitalWrite(LED, HIGH );
  Serial.println(__FUNCTION__);
  delay(2000);
  //  digitalWrite(LED, LOW );
}

void pararUpdate() {
  Serial.print(millis());
  Serial.print(" - ");
  Serial.println(__FUNCTION__);
  delay(25);
  digitalWrite(LED, !digitalRead(LED));
  if (millis() - parcial > 8000)
  {
    parcial = millis();
    stateMachine.transitionTo(chocar);
  }
}

int ReadSensor(int pin)
{
  sensorValue = analogRead(pin);
  return EMALowPassFilter(sensorValue);
}

int EMALowPassFilter(int value)
{
  EMA_LP = EMA_ALPHA * value + (1 - EMA_ALPHA) * EMA_LP;
  return EMA_LP;
}
