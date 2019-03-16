#include <FiniteStateMachine.h>
//http://playground.arduino.cc/Code/FiniteStateMachine

int i = 0;

State noop = State(noopUpdate);  //no operation
State fade = State(fadeEnter, fadeUpdate, NULL);
State fade2 = State(fadeEnter2, fadeUpdate2, NULL);

/** the state machine controls which of the states get attention and execution time */
FSM stateMachine = FSM(noop); //initialize state machine, start in state: noop

void setup() {
  Serial.begin(9600);
  Serial.println("\nFSM Alexander Brevig\n");
  delay(2000);
}

void loop() {
  //do not remove the stateMachine.update() call, it is what makes this program 'tick'
  if (millis() > 10000 && i == 0)
  {
    i = 1;
    stateMachine.transitionTo(fade);
  }
  if (millis() > 20000 && i == 1)
  {
    i = 2;
    stateMachine.transitionTo(fade2);
  }
  if (millis() > 30000 && i == 2)
  {
    i = 3;
    stateMachine.transitionTo(fade);
  }
  stateMachine.update();
  delay(500);
}

//[noop state:update] the state machine is in a state that does nothing
void noopUpdate() {
  //this function gets called as long as the user have not pressed any buttons after startup
  Serial.print(millis());
  Serial.println(__FUNCTION__);
}

void fadeEnter() {
  Serial.println(__FUNCTION__);
}

void fadeUpdate() {
  Serial.println(__FUNCTION__);
}

void fadeEnter2() {
  Serial.println(__FUNCTION__);
}

void fadeUpdate2() {
  Serial.print(millis());
  Serial.println(__FUNCTION__);
}
