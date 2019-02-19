#include <Wire.h>
#include <LSM303.h>

LSM303 compass;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  compass.init();
  compass.enableDefault();
  
  // Calibration values. Use the Calibrate example program to get the values for
  // your compass.
  compass.m_min.x = -1035; compass.m_min.y = +420; compass.m_min.z = +1164;
  compass.m_max.x = -561; compass.m_max.y = +1075; compass.m_max.z = +1280;
}

void loop() {
  compass.read();
  int heading = compass.heading((LSM303::vector){0,-1,0});
  Serial.println(heading);
  delay(100);
}
