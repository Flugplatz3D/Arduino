/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 16 servos, one after the other

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815

  These displays use I2C to communicate, 2 pins are required to  
  interface. For Arduino UNOs, thats SCL -> Analog 5, SDA -> Analog 4

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  119 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  445 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;

int lastpos[16];

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

  pwm.begin();
  
  pwm.setPWMFreq(50);  // Analog servos run at ~60 Hz updates

  for (int i=0;i<16;i++)
  {
    lastpos[i]=0;
  }
}

// you can use this function if you'd like to set the pulse length in seconds
// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. its not precise!
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 50;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000;
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void loop() {
  // Drive each servo one at a time
  /*
  Serial.println(servonum);
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    pwm.setPWM(servonum, 0, pulselen);
  }
  delay(500);
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(servonum, 0, pulselen);
  }
  delay(500);
  */
  char data[5];
  int numero;
  
  if (Serial.available() > 0)
  {
    numero = Serial.readBytesUntil (13,data,5);
    data[numero] = 0;

    int angulo = atoi(data);

    for (servonum=0; servonum<=2; servonum++)
    {
      int pulselength = moveServo(servonum, angulo);
      Serial.print(angulo);
      Serial.print(": ");
      Serial.println(pulselength);
      delay(500);
    }

    /*
    int pulselength = map(angulo, 0, 180, SERVOMIN, SERVOMAX);

    for (servonum=0; servonum<=2; servonum++)
    {
      pwm.setPWM(servonum, 0, pulselength);
      Serial.print(angulo);
      Serial.print(": ");
      Serial.println(pulselength);
      delay(500);
    }
    */
  }
  
  /*
  pulselength = map(180, 0, 180, SERVOMIN, SERVOMAX);

  pwm.setPWM(servonum, 0, pulselength);
  Serial.print("180: ");
  Serial.println(pulselength);
  delay(1000);

  pulselength = map(0, 0, 180, SERVOMIN, SERVOMAX);

  pwm.setPWM(servonum, 0, pulselength);
  Serial.print("0: ");
  Serial.println(pulselength);
  delay(1000);

  pulselength = map(60, 0, 180, SERVOMIN, SERVOMAX);

  pwm.setPWM(servonum, 0, pulselength);
  Serial.print("60: ");
  Serial.println(pulselength);
  delay(1000);

  servonum ++;
  if (servonum > 0) servonum = 0;
  */
}

int moveServo(int servonum, int pos)
{
    int pulselength = map(pos, 0, 180, SERVOMIN, SERVOMAX);

    pwm.setPWM(servonum, 0, pulselength);

    lastpos[servonum] = pos;

    return pulselength;
}


