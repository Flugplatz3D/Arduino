#include <SparkFun_TB6612.h>

#define AIN1 2
#define AIN2 4
#define PWMA 5
#define PWMB 6
#define BIN1 7
#define BIN2 8
#define STBY 9

// these constants are used to allow you to make your motor configuration
// line up with function names like forward.  Value can be 1 or -1
const int offsetA = -1;
const int offsetB = -1;

Motor motorR = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motorL = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

void setup()
{
}

void loop()
{
  motorL.drive(255, 2000);
  motorL.brake();
  delay(500);
  motorL.drive(-255, 2000);
  motorL.brake();
  delay(1000);
  motorR.drive(255, 2000);
  motorR.brake();
  delay(500);
  motorR.drive(-255, 2000);
  motorR.brake();
  delay(3000);
}
