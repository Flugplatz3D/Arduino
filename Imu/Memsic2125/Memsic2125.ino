#include <MedianFilter.h>

const int xPin = 2;     // X output of the accelerometer
const int yPin = 3;     // Y output of the accelerometer

MedianFilter testX(150, 0);
MedianFilter testY(150, 0);

void setup() {
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
}

void loop() {
  // variables to read the pulse widths:
  int pulseX, pulseY;
  // variables to contain the resulting accelerations
  //  int accelerationX, accelerationY;
  // read pulse from x- and y-axes:
  pulseX = pulseIn(xPin, HIGH);
  pulseY = pulseIn(yPin, HIGH);

  testX.in(pulseX);
  testY.in(pulseY);

  //  // convert the pulse width into acceleration
  //  // accelerationX and accelerationY are in milli-g's:
  //  // Earth's gravity is 1000 milli-g's, or 1 g.
  //  accelerationX = ((pulseX / 10) - 500) * 8;
  //  accelerationY = ((pulseY / 10) - 500) * 8;

  Serial.print(pulseX);
  Serial.print(",");
  Serial.print(testX.out());
  Serial.print(",");
  Serial.print(pulseY);
  Serial.print(",");
  Serial.print(testY.out());
  Serial.println();
}
