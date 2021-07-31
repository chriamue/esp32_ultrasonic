
#include <Arduino.h>
#include <Wire.h>        // Instantiate the Wire library
#include <TFLI2C.h>      // https://github.com/budryerson/TFLuna-I2C

#include "heltec.h"

TFLI2C tflI2C;

int16_t  tfDist;    // distance in centimeters
int16_t  tfAddr = TFL_DEF_ADR;  // Use this default I2C address or

void drawDistance(int distance) {
  Heltec.display -> clear();
  Heltec.display -> drawString(0, 0, (String)distance);
  Heltec.display -> drawString(2, 10, " mm");
  Heltec.display -> drawString(0, 20, (String)(distance / 10));
  Heltec.display -> drawString(2, 30, " cm");
  Heltec.display -> display();
}

void setup()
{
  Serial.begin( 115200);

  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Enable*/, false /*Serial Enable*/);

  Heltec.display->clear();
  delay(10);
  Wire.begin();
  Serial.println( "Start distance measuring");
}

void loop()
{

  if ( tflI2C.getData( tfDist, tfAddr)) // If read okay...
  {
    drawDistance((int) tfDist * 10);
    Serial.print("Dist: ");
    Serial.println(tfDist);          // print the data...
  } else {
    tflI2C.printDataArray();
  }

  delay( 100);
}
