#define button1Pin PA8
#define button2Pin PB14
#define button3Pin PB12
#define ledPin PC13

int boton1 = 0;
int boton2 = 0;
int boton3 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button1Pin, INPUT_PULLDOWN);
  pinMode(button2Pin, INPUT_PULLDOWN);
  pinMode(button3Pin, INPUT_PULLDOWN);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  boton1 = digitalRead(button1Pin);
  boton2 = digitalRead(button2Pin);
  boton3 = digitalRead(button3Pin);
  Serial.print(boton1);
  Serial.print(" : ");
  Serial.print(boton2);
  Serial.print(" : ");
  Serial.println(boton3);
//  if (boton3 != 0)
//  {
//    //    digitalWrite(ledPin,!digitalRead(ledPin));
//    digitalWrite(ledPin, LOW);
//  }
//  else
//  {
//    digitalWrite(ledPin, HIGH);
//  }
  delay(50);
}
