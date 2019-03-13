#include "FiniteStateMachine.h"

/** this is the definitions of the states that our program uses */
State ST_PARAR = State(pararUpdate);  //no operation
State ST_CHOCAR = State(chocarEnter, chocarUpdate, NULL);  //this state fades the LEDs in
State ST_DERECHA = State(derechaUpdate);  //this state flashes the leds FLASH_ITERATIONS times at 1000/FLASH_INTERVAL
State circleMotion = State(circleMotionUpdate); //show the circular animation

FSM stateMachine = FSM(ST_PARAR); //initialize state machine, start in state: ST_PARAR


void setup() {
  // put your setup code here, to run once:

}

void loop() {
//	//CONTROL THE STATE
//    switch (buttonPresses){
//      case 0: stateMachine.transitionTo(ST_PARAR); break;
//      case 1: stateMachine.transitionTo(ST_CHOCAR); break; //first press
//      case 2: stateMachine.transitionTo(ST_DERECHA); break; //second press
//    }
  stateMachine.update();
}

void pararUpdate() {
}

void chocarEnter() {
}

void chocarUpdate() {
}

void derechaUpdate() {
}

void circleMotionUpdate() {
}