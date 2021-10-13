#include "SM9333.h"

SM9333 sensor1;

void setup() {
  Serial.begin(9600);
  sensor1.begin();
}

void loop() {
  double p1 = sensor1.readPressure();

  Serial.println("Sensor 1: " + (String)p1 + " Pa");

  Serial.println("------------------------");

  delay(200);

}
