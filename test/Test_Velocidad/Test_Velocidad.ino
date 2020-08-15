#define LED 13

#define Interno 500000
#define Base 12

//12x500000
//Nucleo-64 STM32F103RB - 10670ms
//Nano 328p - 78719ms
//Maple Mini STM32F103RCBT6 - 10077ms 72Mhz(Smallest) 25196
//Maple Mini STM32F103RCBT6 - 9421ms 72Mhz(-O2) 26532
//Maple Mini STM32F103RCBT6 - 9776s 72Mhz(-O1) 27068
//Ard Micro ATmega32U4 - 79126ms
//Clon LGT8F328P - 68432ms
//Nucleo-32 STM32F303K8 - 986ms M4 72Mhz(Smallest) 16820
//Nucleo-32 STM32F303K8 - 1158ms M4 72Mhz(-O1) 18531
//Nucleo-32 STM32F303K8 - 1158ms M4 72Mhz(-O2) 18180
//BluePill STM32F103C8T6 - 9256s 72Mhz(Smallest) 25252
//BluePill STM32F103C8T6 - 9505s 72Mhz(-O1) 27140
//BluePill STM32F103C8T6 - 10089s 72Mhz(-O2) 26596

unsigned long parcial = 0;
float Factorial;
String inString = "";

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.println("\n\nInicio");
  delay(1000);
}

void loop() {
  digitalWrite(LED, LOW);
  parcial = millis();
  Serial.print("\nCalculando ");
  Serial.print(Interno);
  Serial.print(" veces el factorial de ");
  Serial.println(Base);
  inString = "";
  for (unsigned long j = 1; j <= Interno; j++)
  {
    Factorial = 1;
    for (int i = Base; i > 0; i--)
    {
      Factorial = Factorial * (float)i;
    }
  }
  //Factorial = Factorial / 10000; //por el ovf de println
  //inString += Factorial;
  //Serial.println(inString);
  Serial.println(Factorial);
  digitalWrite(LED, HIGH);
  Serial.print("Milisegundos -> ");
  Serial.println(millis() - parcial);
  delay(2000);
}
