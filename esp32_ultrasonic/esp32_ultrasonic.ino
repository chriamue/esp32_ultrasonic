#include <HCSR04.h> // https://github.com/d03n3rfr1tz3/HC-SR04
#include "heltec.h"

byte triggerPin = 17;
byte echoPin = 5;

long duration;
int distance;

void drawDistance(int distance) {
  Heltec.display -> clear();
  Heltec.display -> drawString(0, 0, (String)distance);
  Heltec.display -> drawString(2, 10, " mm");
  Heltec.display -> drawString(0, 20, (String)(distance/10));
  Heltec.display -> drawString(2, 30, " cm");
  Heltec.display -> display();
}

void setup()
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);

  HCSR04.begin(triggerPin, echoPin);
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Enable*/, true /*Serial Enable*/);

  Heltec.display->clear();
}

void loop()
{
  //int centimeters = distMeasure();
  
  double* centimeters = HCSR04.measureDistanceMm();
  drawDistance((int)centimeters[0]);

  delay(1000);
}
