#include <OrangutanLEDs.h>

OrangutanLEDs leds;

void setup()                    // run once, when the sketch starts
{
}

void loop()                     // run over and over again
{
  leds.red(HIGH);               // red LED on
  delay(100);                  // waits for a second
  leds.red(LOW);                // red LED off
  delay(100);                  // waits for a second                 // waits for 0.5 seconds
  leds.red(HIGH);               // red LED on
  delay(100);                  // waits for a second
  leds.red(LOW);                // red LED off
  delay(100);                  // waits for a second                 // waits for 0.5 seconds
  leds.red(HIGH);               // red LED on
  delay(500);                  // waits for a second
  leds.red(LOW);                // red LED off
  delay(1000);                  // waits for a second                 // waits for 0.5 seconds
}
