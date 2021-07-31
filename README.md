# esp32_ultrasonic

Ultrasonic distance measuring using esp32 with display

## Hardware

* [Heltec ESP32 with ](https://heltec.org/project/wifi-kit-32/)
* HC-SR04 Ultrasonic Sensor

![](image.jpg)

* [TFLuna](https://youyeetoo.com/blog/tflunald0023-55)

![](lidar.jpg)

## Software Packages

These packages have to be installed in the Arduino IDE.

* [Heltec](https://github.com/HelTecAutomation/Heltec_ESP32)
* [HCSR04](https://github.com/d03n3rfr1tz3/HC-SR04)

## Pinout

[ESP32 Pins](https://resource.heltec.cn/download/WiFi_Kit_32/WIFI_Kit_32_pinoutDiagram_V2.1.pdf)

## Ultrasonic

- 1 - GND
- 2 - 5V (VCC)
- 12 - GPIO17 (trigger)
- 13 - GPIO15 (echo)

## Lidar

 - 1 - 5V
 - 2 - GPIO4 (SDA)
 - 3 - GPIO15 (SCL)
 - 4 - GND
 