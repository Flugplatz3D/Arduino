const int xPin = PA0;		// X output of the accelerometer
const int yPin = PA1;		// Y output of the accelerometer
int MapValueX = 0;
int MapValueY = 0;
int pulseX, pulseY;
int accelerationX, accelerationY;

void setup() {
  // initialize serial communications:
  Serial.begin(9600);
  // initialize the pins connected to the accelerometer as inputs:
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
}

void loop() {
  // read pulse from x- and y-axes:
  pulseX = pulseIn(xPin, HIGH);
  pulseY = pulseIn(yPin, HIGH);

  // convert the pulse width into acceleration
  // accelerationX and accelerationY are in milli-g's:
  // Earth's gravity is 1000 milli-g's, or 1 g.
  //  accelerationX = ((pulseX / 10) - 500) * 8;
  //  accelerationY = ((pulseY / 10) - 500) * 8;

  accelerationX = map(pulseX, 3700, 6300, -400, 400);
  accelerationY = map(pulseY, 3700, 6300, -400, 400);

  // print the acceleration
  Serial.print(accelerationX);
  // print a tab character:
  Serial.print(",");
  Serial.print(accelerationY);
  Serial.println();

  delay(100);
}
