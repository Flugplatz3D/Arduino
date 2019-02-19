void setup()
{
  Serial.begin(9600);
  backlightOff();
}

void loop()
{
  clearLCD();
  Serial.print(millis());
  delay(50);
}

void selectLineOne() { //puts the cursor at line 0 char 0.
  Serial.write(0xFE);   //command flag
  Serial.write(128);    //position
  delay(10);
}
void selectLineTwo() { //puts the cursor at line 0 char 0.
  Serial.write(0xFE);   //command flag
  Serial.write(192);    //position
  delay(10);
}
void clearLCD() {
  Serial.write(0xFE);   //command flag
  Serial.write(0x01);   //clear command.
  delay(10);
}
void backlightOn() { //turns on the backlight
  Serial.write(0x7C);   //command flag for backlight stuff
  Serial.write(157);    //light level.
  delay(10);
}
void backlightOff() { //turns off the backlight
  Serial.write(0x7C);   //command flag for backlight stuff
  Serial.write(128);     //light level for off.
  delay(10);
}
void serCommand() {  //a general function to call the command flag for issuing all other commands
  Serial.write(0xFE);
}

