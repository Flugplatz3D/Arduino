#include <TM1638.h>
// define un modulo en data pin 8, clock pin 9 y strobe pin 7
TM1638 module(8, 9, 7);
unsigned long time1 = 0;
void setup(){
}
void loop()
{
  time1 = millis();
  if (time1<1000)
  {
    module.setDisplayToDecNumber(time1/10,0,false);
  }
  else
  {
    module.setDisplayToDecNumber(time1/10,4,false);
  }
}


