#include <LiquidCrystal.h>
#include <FiniteStateMachine.h>

State noop = State(noopUpdate);  //no operation
State chocar = State(chocarEnter, chocarUpdate, NULL);
State parar = State(pararEnter, pararUpdate, NULL);

FSM stateMachine = FSM(chocar);

// select the pins used on the LCD panelEW
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

// read the buttons
int read_LCD_buttons()
{
  adc_key_in = analogRead(0);      // read the value from the sensor
  // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
  // we add approx 50 to those values and check to see if we are close
  if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
  // For V1.1 us this threshold
  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 200)  return btnUP;
  if (adc_key_in < 350)  return btnDOWN;
  if (adc_key_in < 550)  return btnLEFT;
  if (adc_key_in < 800)  return btnSELECT;
  return btnNONE;  // when all others fail, return this...
}

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);              // start the library
  lcd.setCursor(0, 0);
  lcd.print("Botones"); // print a simple message
}

void loop()
{
  lcd.setCursor(8, 0);           // move cursor to second line "1" and 9 spaces over
  //  lcd.print(millis() / 1000);    // display seconds elapsed since power-up
  lcd.print(millis() / 100);

  //  lcd.setCursor(9, 1);
  //  lcd.print("    ");

  lcd.setCursor(8, 1);
  lcd.print(adc_key_in);
  lcd.print("   ");

  lcd.setCursor(0, 1);           // move to the begining of the second line
  lcd_key = read_LCD_buttons();  // read the buttons

  switch (lcd_key)               // depending on which button was pushed, we perform an action
  {
    case btnRIGHT:
      {
        lcd.print("RIGHT ");
        break;
      }
    case btnLEFT:
      {
        lcd.print("LEFT   ");
        break;
      }
    case btnUP:
      {
        lcd.print("UP    ");
        break;
      }
    case btnDOWN:
      {
        lcd.print("DOWN  ");
        break;
      }
    case btnSELECT:
      {
        lcd.print("SELECT");
        break;
      }
    case btnNONE:
      {
        lcd.print("NONE  ");
        break;
      }
  }
  stateMachine.update();
}

//[noop state:update] the state machine is in a state that does nothing
void noopUpdate() {
  //Serial.println(__FUNCTION__);
}

void chocarEnter() {
  Serial.println(__FUNCTION__);
}

void chocarUpdate() {
  Serial.println(__FUNCTION__);
  //stateMachine.transitionTo(parar);
}
void pararEnter() {
  ////  digitalWrite(LED, HIGH );
  //  Serial.println(__FUNCTION__);
  //  tone(9, beep, 100);
  //  delay(2000);
  //  tone(9, beep, 100);
  ////  digitalWrite(LED, LOW );
}

void pararUpdate() {
  //  Serial.print(millis());
  //  Serial.print(" - ");
  //  Serial.println(__FUNCTION__);
  //  delay(10);
  //  digitalWrite(LED, !digitalRead(LED));
  //  if (millis() - parcial > 10000)
  //  {
  //    parcial = millis();
  //    stateMachine.transitionTo(chocar);
  //  }
}
