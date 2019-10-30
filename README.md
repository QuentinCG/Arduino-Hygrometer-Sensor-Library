# Hygrometer Sensor Library for Arduino (Rain Drop and Soil Moisture)
[![Build Status](https://travis-ci.org/QuentinCG/Arduino-Hygrometer-Sensor-Library.svg?branch=master)](https://travis-ci.org/QuentinCG/Arduino-Hygrometer-Sensor-Library) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/260ca5a589d0495e9cdfabeae7fa917e)](https://www.codacy.com/manual/QuentinCG/Arduino-Hygrometer-Sensor-Library?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=QuentinCG/Arduino-Hygrometer-Sensor-Library&amp;utm_campaign=Badge_Grade) [![License: MIT](https://img.shields.io/badge/License-MIT-brightgreen.svg)](https://github.com/QuentinCG/Arduino-Hygrometer-Sensor-Library/blob/master/LICENSE.md)
 
## What is it

This library (with examples) is designed to be integrated in projects using any kind of Hygrometer sensors like rain drop or soil moisture sensors (analog or/and digital).
It retrieves analog/digital value from the sensor and gives the humidity status.

<img src="device.png" width="400">

## How to install

1) Download <a target="_blank" href="https://github.com/QuentinCG/Arduino-Hygrometer-Sensor-Library/releases/download/2.0.0/HygrometerSensor_v2_0_0.zip">latest release</a>

2) On your Arduino IDE, click "Sketch" menu and then "Include Library > Add .ZIP Libraries"

3) You can now use the library for your project or launch an example ("File > Examples")

## How to connect Rain drop sensor or soil moisture sensor to your Arduino

Most hygrometer sensors have an analog and/or a digital output.

All rain drop sensors behave the same way:

|Raindrop Sensor|Arduino                      |
|--------       |--------                     |
|VCC            |5V                           |
|GND            |GND                          |
|A0             |A1 (or any other analog pin) |
|D0             |D2 (or any other digital pin)|

<img src="schematics.png" width="400">

(<a target="_blank" href="http://henrysbench.capnfatz.com/henrys-bench/arduino-sensors-and-input/arduino-rain-sensor-module-guide-and-tutorial/">Source image</a>)

## Examples

Two examples are provided with this library:

### Read digital value from sensor
<a target="_blank" href="https://github.com/QuentinCG/Arduino-Hygrometer-Sensor-Library/blob/master/examples/DigitalHygrometer/DigitalHygrometer.ino">Link to source code</a>

### Read analog value from sensor
<a target="_blank" href="https://github.com/QuentinCG/Arduino-Hygrometer-Sensor-Library/blob/master/examples/AnalogHygrometer/AnalogHygrometer.ino">Link to source code</a>

## License

This project is under MIT license. This means you can use it as you want (just don't delete the library header).

## Contribute

If you want to add more examples or improve the library, just create a pull request with proper commit message and right wrapping.
