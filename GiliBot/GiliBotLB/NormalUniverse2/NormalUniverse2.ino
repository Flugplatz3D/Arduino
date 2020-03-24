//Title: Button Debouncing using a State Machine
//Author: Chris Guichet
//Date: Jan 15, 2018
//
//Description:
//  -A State Machine is a useful tool to organize complex code
//  -Think of it like the next step beyone "If Else" statements
//  -This example code uses a State Machine to handle tac switch debouncing
//  -It also has a "Hold" function to enable interaction with long button presses
//  -The tac switch is used to control a buzzer and an LED, it can multitask
//
//Wiring Instructions:
//  -Wire a SPST momentary switch between a Digital IO Pin 12 and Ground.  
//    (we will use an internal pullup resistor, so no need to worry about wiring a resistor)
//  -Wire an LED and a small resistor (~300 Ohm) in series
//  -Wire the series LED & Resistor between  Digital IO Pin 7 and Ground.
//    (be sure the + terminal of the LED points toward the IO pin)
//
//Code Reading Tip:
//  -Before mentally digesting this code, collapse all folds to get a bird's eye view. Instrucitons:
//  -Ctrl-a (to select all) -> Right Click -> Folding -> Collapse All Folds

//Top Level Variables:
int DEBUG = 1;  //Set to 1 to enable serial monitor debugging info

//Switch Variables (I'm calling this switch "s1"):
int state_s1 = 0;                   //The actual ~state~ of the state machine
int state_prev_s1 = 0;              //Remembers the previous state (useful to know when the state has changed)
int pin_s1 = 12;                    //Input/Output (IO) pin for the switch
int val_s1 = 0;                     //Value of the switch ("HIGH" or "LOW")
unsigned long t_s1 = 0;             //Typically represents the current time of the switch
unsigned long t_0_s1 = 0;           //The time that we last passed through an interesting state
unsigned long bounce_delay_s1 = 10; //The delay to list for bouncing
unsigned long hold_delay_s1 = 1000; //The time required to register a long press (a.k.a. "hold")

//Buzzer Variables (I'm calling this buzzer "bz1"):
int state_bz1 = 0;                  //The actual state of the state machine
int state_prev_bz1 = 0;             //Remember the previous state (useful to know if the state has changed)
int pin_bz1 = 6;                    //Buzzer pin
int val_bz1 = 0;                    //Buzzer value (on or off)
unsigned long t_bz1 = 0;            //Current time of the buzzer state machine (in milli seconds)
unsigned long t_0_bz1 = 0;          //The time that we last passed through a state of interest (in milli seconds)
unsigned long on_delay_bz1 = 500;   //On time for the buzzer as it beeps (in milli seconds)
unsigned long off_delay_bz1 = 500;  //Off time for the buzzer as it beeps (in milli seconds)
int beep_count_bz1 = 0;             //Number of times we've beeped on this journey
int beep_number_bz1 = 4;            //Number of times we should beep before resetting

//LED Variables (Variables similar to those above)
int state_led1 = 0;
int state_prev_led1 = 0;
int pin_led1 = 7;
int val_led1 = 0;
unsigned long t_led1 = 0;
unsigned long t_0_led1 = 0;
unsigned long on_delay_led1 = 500;
unsigned long off_delay_led1 = 500;
int beep_count_led1 = 0;
int beep_number_led1 = 4;

void setup() {
  // initialize digital pins
  pinMode(pin_s1,INPUT_PULLUP); //INPUT_PULLUP will use the Arduino's internal pullup resistor
  pinMode(pin_bz1,OUTPUT);
  pinMode(pin_led1,OUTPUT);

  //if DEBUG is turned on, intiialize serial connection
  if(DEBUG) {Serial.begin(115200);Serial.println("Debugging is ON");}
}

void loop() {
  //Instruct all the state machines to proceed one step (sometimes called a "cycle)
  StateMachine_s1();
  StateMachine_bz1();
  StateMachine_led1();

  //Provide events that can force the state machines to change state
  //I like to program interactions between state machines here in the top level loop
  if (state_s1 == 5) {state_led1 = 2;} //short press
  if (state_s1 == 6) {state_bz1 = 2;}  //long press

  if(DEBUG) {
    //Make a note whenever a state machine changes state
    //("Is the current state different from the previous? Yes? OK well let's tell the world the new state")
    if((state_prev_s1 != state_s1) | (state_prev_led1 != state_led1) | (state_prev_led1 != state_bz1)) {
      Serial.print("Switch State: "); Serial.print(state_s1);
      Serial.print(" | LED State: "); Serial.print(state_led1);
      Serial.print(" | Buzzer State: "); Serial.println(state_bz1);
    }
  }
}


void StateMachine_s1() {
  
  //Almost every state needs these lines, so I'll put it outside the State Machine
  val_s1 = digitalRead(pin_s1);
  state_prev_s1 = state_s1;

  //State Machine Section
  switch (state_s1) {
    case 0: //RESET!
      //Catch all "home base" for the State MAchine
      state_s1 = 1;
    break;

    case 1: //WAIT
      //Wait for the switch to go low
      if (val_s1 == LOW) {state_s1 = 2;}
    break;

    case 2: //ARMING!
      //Record the time and proceed to ARMED
      t_0_s1 = millis();
      state_s1 = 3;
    break;

    case 3: //ARMED
      //Check to see if the proper has delay has passed.  If a bounce occures then RESET
      t_s1 = millis();
      if (t_s1 - t_0_s1 > bounce_delay_s1) {state_s1 = 4;}
      if (val_s1 == HIGH) {state_s1 = 0;}
    break;

    case 4: //DRAWN
      //If switch goes HIGH, then TRIGGER. Also check timer for a "Long Pess"
      t_s1 = millis();
      if (val_s1 == HIGH) {state_s1 = 5;}
      if (t_s1 - t_0_s1 > hold_delay_s1) {state_s1 = 6;}
    break;

    case 5: //TRIGGERED!
      //reset the State Machine
      if (DEBUG) {Serial.println("TRIGGERED!!");}
      state_s1 = 0;
    break;

    case 6: //HOLD!
      //proceed to LOW WAIT
      if (DEBUG) {Serial.println("HOLDED!!");}
      state_s1 = 7;
    break;

    case 7: //LOW WAIT
      //wait for switch to go back HIGH, then reset
      if (val_s1 == HIGH) {state_s1 = 0;}
    break;
  }
  
}

void StateMachine_bz1() {

  //Almost every state needs these lines so I'll put it outside the State Machine
  state_prev_bz1 = state_bz1;

  //State Machine Section
  switch(state_bz1) {
    case 0: //RESET
      //Set Beep Count to 0 then proceed to WAIT
      beep_count_bz1 = 0;
      state_bz1 = 1;
    break;

    case 1: //WAIT
      //do nothing, the main loop can progress this Machine from state 1 to state 2
    break;

    case 2: //TURN ON
      //Start buzzer, record time then proceed to ON, 
      digitalWrite(pin_bz1,HIGH);
      t_0_bz1 = millis();
      state_bz1 = 3;
    break;

    case 3: //ON
      //Wait for time to elapse, then proceed to TURN OFF
      t_bz1 = millis();
      if (t_bz1 - t_0_bz1 > on_delay_bz1) {state_bz1 = 4;}
    break;

    case 4: //TURN OFF
      //Increment the beep counter, turn off buzzer, proceed to OFF
      beep_count_bz1++;
      t_0_bz1 = millis();
      digitalWrite(pin_bz1,LOW);
      state_bz1 = 5;
    break;

    case 5: //OFF
      t_bz1 = millis();
      if (t_bz1 - t_0_bz1 > off_delay_bz1) {state_bz1 = 2;}
      if (beep_count_bz1 >= beep_number_bz1) {state_bz1 = 0;}
    break;
  }
  
}

void StateMachine_led1() {
  //Almost every state needs these lines so I'll put it outside the State Machine
  state_prev_led1 = state_led1;
  //State Machine Section
  switch(state_led1) {
    case 0: //RESET
      //Set Beep Count to 0 then proceed to WAIT
      beep_count_led1 = 0;
      state_led1 = 1;
    break;
    case 1: //WAIT
      //Do nothing.  Only the top level loop can force us out of this state into state 2 "TURN ON"
    break;
    
    case 2: //TURN ON
      //Start buzzer, record time then proceed to ON, 
      digitalWrite(pin_led1,HIGH);
      t_0_led1 = millis();
      state_led1 = 3;
    break;
    case 3: //ON
      //Wait for time to elapse, then proceed to TURN OFF
      t_led1 = millis();
      if (t_led1 - t_0_led1 > on_delay_led1) {state_led1 = 4;}
    break;
    case 4: //TURN OFF
      //Increment the beep counter, turn off buzzer, proceed to OFF
      beep_count_led1++;
      t_0_led1 = millis();
      digitalWrite(pin_led1,LOW);
      state_led1 = 5;
    break;
    case 5: //OFF
      t_led1 = millis();
      if (t_led1 - t_0_led1 > off_delay_led1) {state_led1 = 2;}
      if (beep_count_led1 >= beep_number_led1) {state_led1 = 0;}
    break;
  }
  
}
