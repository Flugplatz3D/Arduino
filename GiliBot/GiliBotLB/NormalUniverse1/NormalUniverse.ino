//Title: Button Debouncing using a State Machine, Complex Version
//Author: Chris Guichet
//Date: Jan 15, 2018
//
//Description:
//  -A State Machine is a useful tool to organize complex code
//  -Think of it like the next step beyone "If Else" statements
//  -This example code uses a State Machine to handle tac switch debouncing
//  -It also has a "Hold" function to enable interaction with long button presses
//
//Wiring Instructions:
//  -Wire a SPST momentary switch between a Digital I/O pin and Ground.  (I use pin 12)
//    (we will use an internal pullup resistor, so no need to worry about wiring a resistor)
//
//Code Reading Tip:
//  -Before mentally digesting this code, collapse all folds to get a bird's eye view.
//  -Ctrl-a (to select all) -> Right Click -> Folding -> Collapse All Folds

//Top Level Variables:
int DEBUG = 1;  //Set to 1 to enable serial monitor debugging info

//Switch Variables:
int state_s1 = 0;
int state_prev_s1 = 0;
int pin_s1 = 12;
int val_s1 = 0;
unsigned long t_s1 = 0;
unsigned long t_0_s1 = 0;
unsigned long bounce_delay_s1 = 10;
unsigned long hold_delay_s1 = 1000;

void setup() {
  // initialize digital pins
  pinMode(12,INPUT_PULLUP); //INPUT_PULLUP will use the Arduino's internal pullup resistor

  //if DEBUG is turned on, intiialize serial connection
  if(DEBUG) {Serial.begin(115200);Serial.println("Debugging is ON");}
}

void loop() {
  // put your main code here, to run repeatedly:
  SM_s1();

  //If debug is enabled, do some printing of messages

  //Let the world know when the state changes
  if(DEBUG) {
    if(state_prev_s1 != state_s1) {Serial.print("Switch State: "); Serial.println(state_s1);}
    };

  //Let the world know when the button is held or pressed  
  if (DEBUG) {Serial.println("HOLDED!!");}
  if (DEBUG) {Serial.println("TRIGGERED!!");}
}

void SM_s1() {
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
      state_s1 = 0;
    break;

    case 6: //HOLD!
      //proceed to LOW WAIT
      state_s1 = 7;
    break;

    case 7: //LOW WAIT
      //wait for switch to go back HIGH, then reset
      if (val_s1 == HIGH) {state_s1 = 0;}
    break;
  }
}