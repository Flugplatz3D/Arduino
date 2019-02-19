//////////////////////////////////////////////////////////////////////////////////////////////////////
// UNO_20_Servos_Controller.ino - High definition (15 bit), low jitter, 20 servo software for Atmega328P and Arduino UNO. Version 1.
// Jitter is typical 200-400 ns. 32000 steps resolution for 0-180 degrees. In 18 servos mode it can receive serial servo-move commands.
//
// Copyright (c) 2013 Arvid Mortensen.  All right reserved. 
// http://www.lamja.com
// 
// This software is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                              !!!!!!!!!!!!!!!!!!!
// This software will only work with ATMEGA328P (Arduino UNO and compatible. Or that is what I have tested it with anyways....  !!!!
//                              !!!!!!!!!!!!!!!!!!!
// How it works:
// 18 or 20 pins are used for the servos. These pins are all pre configured.
// All 18/20 servos are always active and updated. To change the servo position, change the
// values in the ServoPW[] array, use the serial commands (int 18 servos mode only) or use 
// ServoMove() function. The range of the ServoPW is 8320 to 39680. 8320=520us. 39680=2480us.
//
// Some formulas:
// micro second = ServoPW value / 16
// angle = (ServoPW value - 8000) / 177.77  (or there about)
// ServoPW value = angle * 177.77 + 8000
// ServoPW value = micro second * 16
//
// Channels are locked to these pins:
// Ch0=Pin2, Ch1=Pin3, Ch2=Pin4, Ch3=Pin5, Ch4=Pin6, Ch5=Pin7, Ch6=Pin8, Ch7=Pin9, Ch8=Pin10, Ch9=Pin11
// Ch10=Pin12, Ch11=Pin13, Ch12=PinA0, Ch13=PinA1, Ch14=PinA2, Ch15=PinA3, Ch16=PinA4, Ch17=PinA5, Ch18=Pin0, Ch19=Pin1
//
// Serial commands:
// # = Servo channel
// P = Pulse width in us
// p = Pulse width in 1/16 us
// S = Speed in us per second
// s = Speed in 1/16 us per second
// T = Time in ms
// PO = Pulse offset in us. -2500 to 2500 in us. Used to trim servo position.
// Po = Pulse offset in 1/16us -40000 to 40000 in 1/16 us
// I = Invert servo movements.
// N = Non-invert servo movements.
// Q = Query movement. Return "." if no servo moves and "+" if there are any servos moving.
// QP = Query servo pulse width. Return 20 bytes where each is from 50 to 250 in 10us resolution. 
//      So you need to multiply byte by 10 to get pulse width in us. First byte is servo 0 and last byte is servo 20.
// <cr> = Carrage return. ASCII value 13. Used to end command.
//
// Examples:
// #0 P1500 T1000<cr>                        - Move Servo 0 to 1500us in 1 second.
// #0 p24000 T1000<cr>                       - Move Servo 0 to 1500us in 1 second.
// #0 p40000 s1600<cr>                       - Move Servo 0 to 2500us in 100us/s speed
// #0 p40000 S100<cr>                        - Move Servo 0 to 2500us in 100us/s speed
// #0 P1000 #1 P2000 T2000<cr>               - Move Servo 0 and servo at the samt time from current pos to 1000us and 2000us in 2 second.
// #0 P2400 S100<cr>                         - Move servo 0 to 2400us at speed 100us/s
// #0 P1000 #1 P1200 S500 #2 P1400 T1000<cr> - Move servo 0, 1 and 2 at the same time, but the one that takes longes S500 or T1000 will be used.
// #0 PO100 #1 PO-100<cr>                    - Will set 100 us offset to servo 0 and -100 us ofset to servo 1
// #0 Po1600 #1 Po-1600<cr>                  - Will set 100 us offset to servo 0 and -100 us ofset to servo 1
// #0 I<cr>                                  - Will set servo 0 to move inverted from standard
// #0 N<cr>                                  - Will set servo 0 back to move non-inverted
// Q<cr>                                     - Will return "." if no servo moves and "+" if there are any servos moving
// QP<cr>                                    - Will retur 18 bytes (each 20ms apart) for position of servos 0 to 17
//
// 18 or 20 channels mode:
// #define HDServoMode 18           - This will set 18 channels mode so you can use serial in and out. Serial command interpreter is activated.
// #define HDServoMode 20           - This will set 20 channels mode, and you can not use serial. 
//                                    A demo will run in the loop() routine . Serial command interpreter is not active.
//                                    use ServoMove(int Channel, long PulseHD, long SpeedHD, long Time) to control servos.
//                                    one of SpeedHD or Time can be set to 0 to just use the other one for speed. If both are used,
//                                    the one that takes the longest time will be used. You can also change the values in the 
//                                    ServoPW[] array directly, but take care not to go under/over 8320/39680.
//
// #deefine SerialInterfaceSpeed 115200      - Serial interface Speed
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <avr/interrupt.h>
#define HDServoMode 20
#define SerialInterfaceSpeed 115200    // Serial interface Speed

static unsigned int iCount;
static volatile uint8_t *OutPortTable[20] = {&PORTD,&PORTD,&PORTD,&PORTD,&PORTD,&PORTD,&PORTB,&PORTB,&PORTB,&PORTB,&PORTB,&PORTB,&PORTC,&PORTC,&PORTC,&PORTC,&PORTC,&PORTC,&PORTD,&PORTD};
static uint8_t OutBitTable[20] = {4,8,16,32,64,128,1,2,4,8,16,32,1,2,4,8,16,32,1,2};
static unsigned int ServoPW[20] = {24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000};
static byte ServoInvert[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
static byte Timer2Toggle;
static volatile uint8_t *OutPort1A = &PORTD;
static volatile uint8_t *OutPort1B = &PORTB;
static uint8_t OutBit1A = 4;
static uint8_t OutBit1B = 16;
static volatile uint8_t *OutPortNext1A = &PORTD;
static volatile uint8_t *OutPortNext1B = &PORTB;
static uint8_t OutBitNext1A = 4;
static uint8_t OutBitNext1B = 16;

static long ServoStepsHD[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
static long ServoLastPos[20] = {24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000,24000};
static long StepsToGo[20] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
static int ChannelCount;

static long ServoGroupStepsToGo = 0;
static long ServoGroupServoLastPos[20];
static long ServoGroupStepsHD[20];
static int ServoGroupChannel[20];
static int ServoGroupNbOfChannels = 0;

static char SerialIn;
static int SerialCommand = 0; //0= none, 1 = '#' and so on...
static long SerialNumbers[10];
static int SerialNumbersLength = 0;
static boolean FirstSerialChannelAfterCR = 1;

static int SerialChannel = 0;
static long SerialPulseHD = 24000;
static long SerialPulseOffsetHD[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
static long SerialPulseOffsetTempHD = 0;
static long SerialSpeedHD = 0;
static long SerialTime = 0;
static long SerialNegative = 1;
static boolean SerialNeedToMove = 0;
static char SerialCharToSend[50] = ".detratS slennahC 81 ovreSDH";
static int SerialNbOfCharToSend = 0;  //0= none, 1 = [0], 2 = [1] and so on...


void ServoMove(int Channel, long PulseHD, long SpeedHD, long Time)
{
// Use ServoMove(int Channel, long PulseHD, long SpeedHD, long Time) to control servos.
// One of th SpeedHD or Time can be set to 0 to only  use the other one for speed. If both are used,
// the one that takes the longest time, will be used
  ServoGroupMove(Channel, CheckRange(PulseHD), SpeedHD, Time);
  ServoGroupMoveActivate();
}

void setup()
{
  ServoSetup();                       //Initiate timers and misc.
  
  #if HDServoMode == 18
    TIMSK0 = 0;                       // Disable timer 0. This can reduse jitter some more. But it's used for delay() funtions.
  #endif                              // This will disable delay()!
}

void loop()
{
  #if HDServoMode == 18               //Serial command interpreter is acive. 18-servos mode.
    CheckSerial();
  #elif HDServoMode == 20             //Demo dance is active. 20-servos mode.
    DemoDance1();
    DemoDance2();
    DemoDance3();
    DemoDance1();
    DemoDance4();
    DemoDance5();
    DemoDance6();
  #endif
}

void DemoDance6()
{
  long MinPulse = 8320;
  long MaxPulse = 35200;  
  int i = 0;
  int i2 = 0;
  for(i2 = 0; i2 < 5 ; i2++)           // All servos go to random position. Then go back to middle in same time.
  {
    for(i = 0; i < 20 ; i++)
    {
      long a = random(MaxPulse-MinPulse)+MinPulse;        
      ServoMove(i, a, 0, 100);
    }
    delay(1500);
    for(i = 0; i < 20 ; i++)
    {
      ServoMove(i, 24000, 0, 3000);
    }
    delay(4000);
  }
}

void DemoDance5()
{
  long MinPulse = 8320;
  long MaxPulse = 35200;  
  int i = 0;
  int i2 = 0;
  i = 0;                                         // All servos moving randomly
  for(i2 = 0; i2 < 1000 ; i2++)
  {
    long a = random(MaxPulse-MinPulse)+MinPulse;        
    int DemoTime = random(1000)+300;
    ServoMove(i, a, 0, DemoTime);
    delay(DemoTime/25);
    i++;
    if(i > 19) i = 0;
  }
}

void DemoDance4()
{
  long MinPulse = 8320;
  long MaxPulse = 35200;  
  int i = 0;
  int i2 = 0;
  float i4 = 0;
  float pi = 3.14159265359;

  for(i2 = 10; i2 > 0 ; i2--)                // Faster bounce
  {
    for(i4 = 0 ; i4 < pi ; i4 += 0.03)
    {
      for(i = 0; i < 20 ; i++) ServoPW[i] = sin(i4)*((MaxPulse-MinPulse)/2) + (MinPulse);
      delay(10);
    }
  }
}

void DemoDance3()
{
  long MinPulse = 8320;
  long MaxPulse = 35200;  
  int i = 0;
  int i2 = 0;
  float i4 = 0;
  float pi = 3.14159265359;

  for(i2 = 10; i2 > 0 ; i2--)                // Slow bounce
  {
    for(i4 = 0 ; i4 < pi ; i4 += 0.005+(0.001*i2))
    {
      for(i = 0; i < 20 ; i++) ServoPW[i] = sin(i4)*(MaxPulse-MinPulse) + MinPulse;
      delay(10);
    }
  }
}

void DemoDance2()
{
  long MinPulse = 8320;
  long MaxPulse = 35200;
  int i = 0;
  int i2 = 0;
    
  for(i2 = 0; i2 < 10 ; i2++)              //Sweep servos, every other way, from fast to slow
  {
    for(i = 0; i < 20 ; i+=2) 
    {
      ServoMove(i, MinPulse, 0, 1000+i2*100);
      ServoMove(i+1, MaxPulse, 0, 1000+i2*100);
    }
    delay(1000+i2*100);  
    for(i = 0; i < 20 ; i+=2) 
    {
      ServoMove(i, MaxPulse, 0, 1000+i2*100);
      ServoMove(i+1, MinPulse, 0, 1000+i2*100);
    }
    delay(1000+i2*100);
  }
}

void DemoDance1()
{
  long MinPulse = 8320;
  long MaxPulse = 35200;
  int i = 0;
  int i2 = 0;
  int i3 = 16;
    
  for(i = 0; i < 100 ; i++)                // Wave move circular
  {
    ServoMove(i2, MinPulse, 0, 800);
    ServoMove(i3, MaxPulse, 0, 800);
    delay(200);
    i2++;
    i3++;
    if(i2>19) i2=0;
    if(i3>19) i3=0;
  }
}

long CheckRange(long PulseHDValue)
{
  if(PulseHDValue > 39680) return 39680;
  else if(PulseHDValue < 8320) return 8320;
  else return PulseHDValue;
}

long CheckChannelRange(long CheckChannel)
{
  if(CheckChannel >= HDServoMode) return (HDServoMode-1);
  else if(CheckChannel < 0) return 0;
  else return CheckChannel;
}

void CheckSerial()     //Serial command interpreter.
{
  int i = 0;

  if(Serial.available() > 0)
  {
    SerialIn = Serial.read();
    if(SerialIn == '#') 
    {
      SerialCommand = 1;
      SerialNeedToMove = 1;
      if(!FirstSerialChannelAfterCR) ServoGroupMove(SerialChannel, CheckRange(SerialPulseHD), SerialSpeedHD, SerialTime);
      FirstSerialChannelAfterCR = 0;
    }
    if(SerialIn == 'p') SerialCommand = 2;
    if(SerialIn == 's') SerialCommand = 3;
    if(SerialIn == 'T') SerialCommand = 4;
    if(SerialIn == 'P') 
    {
      if(SerialCommand == 9) SerialCommand = 10;   // 'QP'
      else SerialCommand = 5;                      // 'P'
    }
    if(SerialIn == 'S') SerialCommand = 6;
    if(SerialIn == 'o') {SerialCommand = 7; SerialNeedToMove = 1;}
    if(SerialIn == 'O') {SerialCommand = 8; SerialNeedToMove = 1;}
    if(SerialIn == 'Q') SerialCommand = 9; 
    if(SerialIn == 'I') SerialCommand = 11; 
    if(SerialIn == 'N') SerialCommand = 12; 
    if(SerialIn == ' ' || SerialIn == 13)
    {
      if(SerialCommand == 1) {SerialChannel = CheckChannelRange(ConvertSerialNumbers()); SerialCommand = 0;}
      if(SerialCommand == 2) {SerialPulseHD = ConvertSerialNumbers() + SerialPulseOffsetHD[SerialChannel]; SerialCommand = 0;}
      if(SerialCommand == 3) {SerialSpeedHD = ConvertSerialNumbers(); SerialCommand = 0;}
      if(SerialCommand == 4) {SerialTime = ConvertSerialNumbers(); SerialCommand = 0;}
      if(SerialCommand == 5) {SerialPulseHD = ConvertSerialNumbers()*16 + SerialPulseOffsetHD[SerialChannel]; SerialCommand = 0;}
      if(SerialCommand == 6) {SerialSpeedHD = ConvertSerialNumbers()*16; SerialCommand = 0;}
      if(SerialCommand == 11) {ServoInvert[SerialChannel] = 1; SerialCommand = 0;}
      if(SerialCommand == 12) {ServoInvert[SerialChannel] = 0; SerialCommand = 0;}
      if(SerialCommand == 7) 
      {
        SerialPulseOffsetTempHD = ConvertSerialNumbers();
        SerialPulseHD = ServoPW[SerialChannel] - SerialPulseOffsetHD[SerialChannel] + SerialPulseOffsetTempHD;
        SerialTime = 10;
        SerialPulseOffsetHD[SerialChannel] = SerialPulseOffsetTempHD;
        SerialCommand = 0;
      }
      if(SerialCommand == 8) 
      {
        SerialPulseOffsetTempHD = ConvertSerialNumbers()*16;
        SerialPulseHD = ServoPW[SerialChannel] - SerialPulseOffsetHD[SerialChannel] + SerialPulseOffsetTempHD;
        SerialTime = 10;
        SerialPulseOffsetHD[SerialChannel] = SerialPulseOffsetTempHD;
        SerialCommand = 0;
      }
      if(SerialIn == 13) 
      {
        if(SerialNeedToMove)
        {
          ServoGroupMove(SerialChannel, CheckRange(SerialPulseHD), SerialSpeedHD, SerialTime);
          ServoGroupMoveActivate();
          FirstSerialChannelAfterCR = 1;
          SerialCommand = 0;
          SerialSpeedHD = 0;
          SerialTime = 0;
          SerialNeedToMove = 0;
        }
        if(SerialCommand == 9)
        {
          SerialCharToSend[0] = '.';
          for(i = 0; i < 20 ; i++)
          {
            if(StepsToGo[i] > 0) SerialCharToSend[0] = '+';
          }
          SerialNbOfCharToSend = 1;
          SerialCommand = 0;
        }
        if(SerialCommand == 10)
        {
          for(i = 0; i < 18 ; i++)
          {
            SerialCharToSend[17 - i] = (ServoPW[i] - SerialPulseOffsetHD[i])/160;
          }
          SerialNbOfCharToSend = 18;
          SerialCommand = 0;
        }
      }
    }
    if((SerialIn >= '0') && (SerialIn <= '9')) {SerialNumbers[SerialNumbersLength] = SerialIn - '0'; SerialNumbersLength++;}
    if(SerialIn == '-') SerialNegative = -1;
  }
}

long ConvertSerialNumbers()         //Converts numbers gotten from serial line to long.
{
  int i = 0;
  
  long ReturnValue = 0;
  long Multiplier = 1;
  if(SerialNumbersLength > 0)
  {
    for(i = SerialNumbersLength-1 ; i >= 0 ; i--)
    {
      ReturnValue += SerialNumbers[i]*Multiplier;
      Multiplier *=10;
    }
    ReturnValue *= SerialNegative;
    SerialNumbersLength = 0;
    SerialNegative = 1;
    return ReturnValue;
  }
  else return 0;
}

void ServoGroupMove(int Channel, long PulseHD, long SpeedHD, long Time)    //ServoMove used by serial command interpreter
{
  long StepsToGoSpeed=0;
  long StepsToGoTime=0;
  
  ServoGroupChannel[ServoGroupNbOfChannels] = Channel;
  if(SpeedHD < 1) SpeedHD = 3200000;
  StepsToGoSpeed = abs((PulseHD - ServoPW[Channel]) / (SpeedHD / 50));
  StepsToGoTime = Time / 20;
  if(StepsToGoSpeed > ServoGroupStepsToGo) ServoGroupStepsToGo = StepsToGoSpeed;
  if(StepsToGoTime > ServoGroupStepsToGo) ServoGroupStepsToGo = StepsToGoTime;
  ServoGroupChannel[ServoGroupNbOfChannels] = Channel;
  ServoGroupServoLastPos[ServoGroupNbOfChannels] = PulseHD;
  ServoGroupNbOfChannels++;
}

void ServoGroupMoveActivate()                       //ServoMove used by serial command interpreter
{
  int ServoCount = 0;
  
  for(ServoCount = 0 ; ServoCount < ServoGroupNbOfChannels ; ServoCount++)
  {
    ServoStepsHD[ServoGroupChannel[ServoCount]] = (ServoGroupServoLastPos[ServoCount] - ServoPW[ServoGroupChannel[ServoCount]]) / ServoGroupStepsToGo;
    StepsToGo[ServoGroupChannel[ServoCount]] =ServoGroupStepsToGo;
    ServoLastPos[ServoGroupChannel[ServoCount]] = ServoGroupServoLastPos[ServoCount];
  }
  ServoGroupNbOfChannels = 0;
  ServoGroupStepsToGo = 0;
}

void RealTime50Hz() //Move servos every 20ms to the desired position.
{
  if(SerialNbOfCharToSend) {SerialNbOfCharToSend--; Serial.print(SerialCharToSend[SerialNbOfCharToSend]);}
  for(ChannelCount = 0; ChannelCount < 20; ChannelCount++)
  {
    if(StepsToGo[ChannelCount] > 0)
    {
      ServoPW[ChannelCount] += ServoStepsHD[ChannelCount];
      StepsToGo[ChannelCount] --;
    }
    else if(StepsToGo[ChannelCount] == 0)
    {
      ServoPW[ChannelCount] = ServoLastPos[ChannelCount];
      StepsToGo[ChannelCount] --;
    }
  }
}

ISR(TIMER1_COMPA_vect) // Interrupt routine for timer 1 compare A. Used for timing each pulse width for the servo PWM.
{ 
  *OutPort1A &= ~OutBit1A;                //Pulse A finished. Set to low
}

ISR(TIMER1_COMPB_vect) // Interrupt routine for timer 1 compare A. Used for timing each pulse width for the servo PWM.
{ 
  *OutPort1B &= ~OutBit1B;                //Pulse B finished. Set to low
}

ISR(TIMER2_COMPA_vect) // Interrupt routine for timer 2 compare A. Used for timing 50Hz for each servo.
{ 
  *OutPortNext1A |= OutBitNext1A;         // Start new pulse on next servo. Write pin HIGH
  *OutPortNext1B |= OutBitNext1B;         // Start new pulse on next servo. Write pin HIGH
}

ISR(TIMER2_COMPB_vect) // Interrupt routine for timer 2 compare A. Used for timing 50Hz for each servo.
{ 
  TIFR1 = 255;                                       // Clear  pending interrupts
  TCNT1 = 0;                                         // Restart counter for timer1
  TCNT2 = 0;                                         // Restart counter for timer2
  sei();
  *OutPort1A &= ~OutBit1A;                           // Set pulse low to if not done already
  *OutPort1B &= ~OutBit1B;                           // Set pulse low to if not done already
  OutPort1A = OutPortTable[Timer2Toggle];            // Temp port for COMP1A
  OutBit1A = OutBitTable[Timer2Toggle];              // Temp bitmask for COMP1A
  OutPort1B = OutPortTable[Timer2Toggle+10];         // Temp port for COMP1B
  OutBit1B = OutBitTable[Timer2Toggle+10];           // Temp bitmask for COMP1B
  if(ServoInvert[Timer2Toggle]) OCR1A = 48000 - ServoPW[Timer2Toggle] - 7985;                // Set timer1 count for pulse width.
  else OCR1A = ServoPW[Timer2Toggle]-7980;
  if(ServoInvert[Timer2Toggle+10]) OCR1B = 48000 - ServoPW[Timer2Toggle+10]-7970;            // Set timer1 count for pulse width.
  else OCR1B = ServoPW[Timer2Toggle+10]-7965;
  Timer2Toggle++;                                    // Next servo in line.
  if(Timer2Toggle==10)
  { 
    Timer2Toggle = 0;                                // If next servo is grater than 9, start on 0 again.
    RealTime50Hz();                                  // Do servo management
  }
  OutPortNext1A = OutPortTable[Timer2Toggle];        // Next Temp port for COMP1A
  OutBitNext1A = OutBitTable[Timer2Toggle];          // Next Temp bitmask for COMP1A
  OutPortNext1B = OutPortTable[Timer2Toggle+10];     // Next Temp port for COMP1B
  OutBitNext1B = OutBitTable[Timer2Toggle+10];       // Next Temp bitmask for COMP1B
}

void ServoSetup()
{
  // Timer 1 setup(16 bit):
  TCCR1A = 0;                     // Normal counting mode 
  TCCR1B = 1;                     // Set prescaler to 1 
  TCNT1 = 0;                      // Clear timer count 
  TIFR1 = 255;                    // Clear  pending interrupts
  TIMSK1 = 6;                     // Enable the output compare A and B interrupt 
  // Timer 2 setup(8 bit):
  TCCR2A = 0;                     // Normal counting mode 
  TCCR2B = 6;                     // Set prescaler to 256
  TCNT2 = 0;                      // Clear timer count 
  TIFR2 = 255;                    // Clear pending interrupts
  TIMSK2 = 6;                     // Enable the output compare A and B interrupt 
  OCR2A = 93;                     // Set counter A for about 500us before counter B below;
  OCR2B = 124;                    // Set counter B for about 2000us (20ms/10, where 20ms is 50Hz);
  
  #if HDServoMode == 18
    for(iCount=2;iCount<14;iCount++) pinMode(iCount, OUTPUT);    // Set all pins used to output:
    OutPortTable[18] = &PORTC;    // In 18 channel mode set channel 18 and 19 to a dummy pin that does not exist.
    OutPortTable[19] = &PORTC;
    OutBitTable[18] = 128;
    OutBitTable[19] = 128;
    Serial.begin(SerialInterfaceSpeed);  
    SerialNbOfCharToSend = 28;
  #elif HDServoMode == 20
    for(iCount=0;iCount<14;iCount++) pinMode(iCount, OUTPUT);    // Set all pins used to output:
  #endif
  DDRC = 63;                      //Set analog pins A0 - A5 as digital output also.
}
