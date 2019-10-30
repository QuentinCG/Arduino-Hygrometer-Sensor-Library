/*
 * \brief Get humidity information from Digital Rain drop sensor (or moisture sensor) every second
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 19 July 2016
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 2.0
 *
 * \history
 *  - v1.0 Base
 *  - v2.0 Adapt to new library
 */

#include <HygrometerSensor.h>

// Create digital rain drop sensor (or moisture sensor) instance on D2 pin
HygrometerSensor analog_rain_drop(HygrometerSensor::DIGITAL, 2);

void setup(void)
{
  Serial.begin(9600);
}

void loop()
{
  // Check rain state every sec

  Serial.print("Rain drop state: ");
  if (analog_rain_drop.isHumid()) {
    Serial.print("Raining");
  } else {
    Serial.print("Dry");
  }
  Serial.print("\n");

  delay(1000);
}
