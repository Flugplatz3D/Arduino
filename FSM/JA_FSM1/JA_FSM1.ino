#include <FiniteStateMachine.h>
//http://playground.arduino.cc/Code/FiniteStateMachine

State noop = State(noopUpdate);  //no operation
State chocar = State(chocarEnter, chocarUpdate, NULL);
State parar = State(pararEnter, pararUpdate, NULL);

unsigned long parcial = 0;

FSM stateMachine = FSM(noop); //initialize state machine, start in state: noop

//#define LED PB1
//#define LED PC13
//#define LED PC14
#define LED 13
#define beep 2250

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  delay(2000);
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
  tone(9, beep, 100);
  delay(2000);
  tone(9, beep, 100);
  stateMachine.transitionTo(parar);
}
void pararEnter() {
//  digitalWrite(LED, HIGH );
  Serial.println(__FUNCTION__);
  tone(9, beep, 100);
  delay(2000);
  tone(9, beep, 100);
//  digitalWrite(LED, LOW );
}

void pararUpdate() {
  Serial.print(millis());
  Serial.print(" - ");
  Serial.println(__FUNCTION__);
  delay(10);
  digitalWrite(LED, !digitalRead(LED));
  if (millis() - parcial > 10000)
  {
    parcial = millis();
    stateMachine.transitionTo(chocar);
  }
}