#include <TM1638.h>
// define a module on data pin 8, clock pin 9 and strobe pin 7
//TM1638 module(8, 9, 7);
TM1638 module(2, 3, 4);
unsigned long a = 1;
void setup() {}
void loop()
{
  for (a = 10000; a < 11000; a++)
  {
    module.setDisplayToDecNumber(a, 4, false);
    delay(1);
  }
  for (a = 10000; a < 11000; a++)
  {
    module.setDisplayToDecNumber(a, 0, true);
    delay(1);
  }
}
