#define LED_MICRO 17
#define LED_TEST 2

void setup() {
  pinMode(LED_MICRO, OUTPUT);
  pinMode(LED_TEST, OUTPUT);
}
void loop() {
  digitalWrite(LED_MICRO, !bitRead(millis(), 9));
  digitalWrite(LED_TEST, bitRead(millis(), 9));
}
