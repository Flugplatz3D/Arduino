#define LED 13
#define ExtLoop 500000
#define Base 12

//12x500000
//Nucleo-64 STM32F103RB - 10670m
//Nucleo-32 STM32L432KC - 544m
//Nano 328p - 78719ms
//Maple Mini STM32F103RCBT6 - 10077ms 72Mhz(Smallest) 25196
//Maple Mini STM32F103RCBT6 - 9421ms 72Mhz(-O2) 26532
//Maple Mini STM32F103RCBT6 - 9776s 72Mhz(-O1) 27068
//Ard Micro ATmega32U4 - 79126ms
//Clon LGT8F328P - 68432ms
//Clon LGT8F328P - 32416ms
//Nucleo-32 STM32F303K8 - 986ms M4 72Mhz(Smallest) 16820
//Nucleo-32 STM32F303K8 - 1158ms M4 72Mhz(-O1) 18531
//Nucleo-32 STM32F303K8 - 1158ms M4 72Mhz(-O2) 18180
//BluePill STM32F103C8T6 - 9256s 72Mhz(Smallest) 25252
//BluePill STM32F103C8T6 - 9505s 72Mhz(-O1) 27140
//BluePill STM32F103C8T6 - 10089s 72Mhz(-O2) 26596
//Teensy 3.0 - 14220ms 16560 96Mhz

unsigned long partial = 0;
float Factorial;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  delay(2000);
  Serial.println("\n\nStart");
  delay(2000);
}

void loop() {
  digitalWrite(LED, LOW);
  partial = millis();
  Serial.print("\nCalculating ");
  Serial.print(ExtLoop);
  Serial.print(" times Factorial of ");
  Serial.println(Base);
  for (unsigned long j = 1; j <= ExtLoop; j++)
  {
    Factorial = 1;
    for (int i = Base; i > 0; i--)
    {
      Factorial = Factorial * (float)i;
    }
  }
  Serial.println(Factorial);
  digitalWrite(LED, HIGH);
  Serial.print("Milliseconds -> ");
  Serial.println(millis() - partial);
  delay(2000);
}
