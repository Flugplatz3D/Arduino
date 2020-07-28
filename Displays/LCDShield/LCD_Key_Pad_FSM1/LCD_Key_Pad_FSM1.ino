#include <LiquidCrystal.h>
#include <FiniteStateMachine.h>

State noop = State(noopUpdate);
State unoC = State(unoCEnter, unoCUpdate, unoCExit);
State dosC = State(dosCEnter, dosCUpdate, dosCExit);
State unoR = State(unoREnter, unoRUpdate, unoRExit);

unsigned long unoCCount = 0;
unsigned long dosCCount = 0;
unsigned long unoRCount = 0;

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

FSM stateMachine = FSM(noop);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);              // start the library
  stateMachine.transitionTo(unoC);
}

void loop()
{
  stateMachine.update();
}

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

void noopUpdate() {
  //Serial.println(__FUNCTION__);
}

void unoCEnter() {
  lcd.setCursor(0, 0);
  lcd.print("unoC");
  lcd.setCursor(0, 1);
  lcd.print(unoCCount);
  lcd.print("   ");
  //delay(500);
}

void unoCUpdate() {
  lcd_key = read_LCD_buttons();
  unoCCount++;
  if (lcd_key == btnDOWN)
  {
    stateMachine.transitionTo(dosC);
  }
    if (lcd_key == btnRIGHT)
  {
    stateMachine.transitionTo(unoR);
  }
}

void unoCExit() {
  lcd.clear();
}

void dosCEnter() {
  lcd.setCursor(0, 0);
  lcd.print("dosC");
  lcd.setCursor(0, 1);
  lcd.print(dosCCount);
  lcd.print("   ");
  //delay(500);
}

void dosCUpdate() {
  lcd_key = read_LCD_buttons();
  dosCCount++;
  if (lcd_key == btnUP)
  {
    stateMachine.transitionTo(unoC);
  }
}

void dosCExit() {
  lcd.clear();
}

void unoREnter() {
  lcd.setCursor(0, 0);
  lcd.print("unoR");
  lcd.setCursor(0, 1);
  lcd.print(unoRCount);
  lcd.print("   ");
  //delay(500);
}

void unoRUpdate() {
  lcd_key = read_LCD_buttons();
  unoRCount++;
  if (lcd_key == btnLEFT)
  {
    stateMachine.transitionTo(unoC);
  }
}

void unoRExit() {
  lcd.clear();
}