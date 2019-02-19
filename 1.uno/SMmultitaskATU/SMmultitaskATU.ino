
/*-----( Import needed libraries )-----*/
#include <SM.h> //state machine library
#include <LiquidCrystal.h>  // Required by LCDKeypad

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); //pin 10 pour le retroeclairage

// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  20
#define btnUP     21
#define btnDOWN   22
#define btnLEFT   23
#define btnSELECT 24
#define btnNONE   25

// read the buttons
int read_LCD_buttons() // return button pushed name
{
  adc_key_in = analogRead(0);      // read the value from the buttons on A0
  // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
  // we add approx 50 to those values and check to see if we are close
  if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
  if (adc_key_in < 50)   return btnRIGHT; // restarts the Master machine after being stopped
  if (adc_key_in < 195)  return btnUP;   // switches ON the output LED of the PUMP machine (no emergency stop in this machine)
  if (adc_key_in < 380)  return btnDOWN; // starts the Master machine (emergency stop)
  if (adc_key_in < 555)  return btnLEFT; // restarts the SB machine (emergency restart)
  if (adc_key_in < 790)  return btnSELECT; //stops the SB machine (emergency stop)
  return btnNONE;  // when all others fail, return this...
}

/*-----( Declare Constants and Pin Numbers )-----*/
#define PIN13_LED 13 // output for SB machine
#define PIN12_LED 12  // output for FB machine
#define PIN11_LED 11  // output for PUMP machine


int SENSOR0= 0;//not fonctionning on pin 0 and 1, only RX & TX on these pins
int SENSOR1= 1;  
int ATU1= 2 ;// punshed: stops the FB machine, pulled: restarts the FB machine
int ATU2= 3 ; //switch off the LED11 of the PUMP machine
int SORTIE0=13 ; // sortie en pin 13
int etat=0;// used for RE (RISING EDGE) and FE (FALLING EDGE)


/*-----( Declare objects )-----*/
SM Master(Master1);             //the machines and their first state to run, a coin is put on each one
SM FirstBlink(STATE1);
SM SecondBlink(STATE11);
SM PUMP(STATE101);

void setup()   /****** SETUP: RUNS ONCE ******/
{
  //Serial.begin(115200);
  pinMode(PIN13_LED, OUTPUT);// output for SB machine
  pinMode(PIN12_LED, OUTPUT);// output for FB machine
  pinMode(PIN11_LED, OUTPUT);// output for PUMP machine
  pinMode(SENSOR0, INPUT);//not use
  pinMode(SENSOR1, INPUT);//not use
  pinMode(ATU1, INPUT);
  pinMode(ATU2, INPUT);
  lcd.begin(16, 2); // start the library
  lcd.clear();
}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{

  EXEC(Master); //launch the master machine
    
  if(RE(lcd_key==btnDOWN,etat)==1) { //Stops the Master machine, (emergency stop) 
    digitalWrite(PIN13_LED, LOW); 
    digitalWrite(PIN11_LED, LOW);
    digitalWrite(PIN12_LED, LOW);
    lcd.setCursor(0,0);
    lcd.print("FSM   :-- -- ---");
    lcd.setCursor(0,1);
    lcd.print("Action:OffOffOFF");
    Master.Finish();
  }
  if ((RE(lcd_key==btnRIGHT,etat)==1) && Master.Finished){ //restart the Master machine
    FirstBlink.Set(STATE1);  //Restart the slave machine, first state activation
    SecondBlink.Set(STATE11);
    PUMP.Set(STATE101);
    EXEC(Master);            //launch the Master machine
    Master.Set(Master2);     //put a coin in Master2, activation

  }
  if (digitalRead(ATU1)==1) { //emergency stop the FB machine
    digitalWrite(PIN12_LED, LOW);
    lcd.setCursor(7,0);
    lcd.print("--");
    lcd.setCursor(7,1);
    lcd.print("Off");
    FirstBlink.Finish() ;
  }
  if (digitalRead(ATU1)==0 && FirstBlink.Finished){ //restart the FB machine if it is finished first
    digitalWrite(PIN12_LED, LOW);
    lcd.setCursor(7,0);
    lcd.print("FB");
    EXEC(FirstBlink);
    FirstBlink.Set(STATE1);
  }

  if (RE(lcd_key==btnSELECT,etat)==1) { //emergency stop the SB machine, don't use the same btn for both finish and start machine or use 
    digitalWrite(PIN13_LED, LOW);       //a special finish/start state.
    lcd.setCursor(10,0);
    lcd.print("--");
    lcd.setCursor(10,1);
    lcd.print("Off");
    SecondBlink.Finish() ;
  }

  if ((RE(lcd_key==btnLEFT,etat)==1) && SecondBlink.Finished){ //restart the FB machine
    digitalWrite(PIN13_LED, LOW);
    lcd.setCursor(10,0);
    lcd.print("SB");
    EXEC(SecondBlink);
    SecondBlink.Set(STATE11);
  }

  lcd_key = read_LCD_buttons();  // read the buttons of the lcdkeypad


  //FirstBlink.Restart()
}//--(end main loop )---

/*-----( Declare User-written Functions )-----*/

//---( STATE MACHINE: Master )------------------master launch

State Master1()
{
  lcd.setCursor(0,0);
  lcd.print("FSM   :-- -- ---");
  lcd.setCursor(0,1);
  lcd.print("Action:OffOffOFF"); 
  if(RE(lcd_key==btnDOWN,etat)==1) { //Start the Master2 which lauches the other machines 
    Master.Set(Master2);
  }

}

State Master2() //launch the 3 slave machines
{
  EXEC(FirstBlink);
  EXEC(SecondBlink);
  EXEC(PUMP);

}
//-----------------------------------------



//---( STATE MACHINE: FirstBlink )------------------

State STATE1()    
{
  lcd.setCursor(7,0);
  lcd.print("FB");

  if (FirstBlink.Timeout(1)) FirstBlink.Set(STATE2) ; 
}

State STATE2()
{
  lcd.setCursor(7,1);
  lcd.print("ON ");
  digitalWrite(PIN12_LED, LOW);
  if (FirstBlink.Timeout(1000)) FirstBlink.Set(STATE3) ; 
}

State STATE3()
{
  digitalWrite(PIN12_LED, HIGH);  
  if (FirstBlink.Timeout(1000)) FirstBlink.Set(STATE1) ; 
}

//---( STATE MACHINE: SecondBlink )------------------

State STATE11()    
{
  lcd.setCursor(10,0);
  lcd.print("SB");

  if (SecondBlink.Timeout(50)) SecondBlink.Set(STATE12) ; 
}

State STATE12()
{
  lcd.setCursor(10,1);
  lcd.print("ON ");
  digitalWrite(PIN13_LED, HIGH);  
  if (SecondBlink.Timeout(48)) SecondBlink.Set(STATE13) ; 
}

State STATE13()
{
  digitalWrite(PIN13_LED, LOW);  
  if (SecondBlink.Timeout(59)) SecondBlink.Set(STATE11) ; 
}


//---( STATE MACHINE: ThirdBlink )------------------

State STATE101()    
{
  lcd.setCursor(13,0);
  lcd.print("PMP");

  digitalWrite(PIN11_LED, LOW);
  lcd.setCursor(13,1);
  lcd.print("OFF");
  if (RE(lcd_key==btnUP,etat)==1) PUMP.Set(STATE102) ; 
}

State STATE102()
{
  lcd.setCursor(13,1);
  lcd.print("-ON");
  digitalWrite(PIN11_LED, HIGH);  
  if (RE(digitalRead(ATU2),etat)==1) PUMP.Set(STATE101); 
}


//*********( THE END )***********










