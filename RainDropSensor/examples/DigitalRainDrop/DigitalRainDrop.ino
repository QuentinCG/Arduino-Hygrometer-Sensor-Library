/*
 * \brief Get rain information from Digital Rain drop sensor every second
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 29 June 2016
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 1.0
 */

#include <RainDropSensor.h>

// Create digital rain drop sensor instance on D2 pin
RainDropSensor analog_rain_drop(RainDropSensor::DIGITAL, 2);

void setup(void)
{
  Serial.begin(9600);
}

void loop()
{
  // Check rain state every sec

  Serial.print("Rain drop state: ");
  if (analog_rain_drop.isRaining()) {
    Serial.print("Raining");
  } else {
    Serial.print("Dry");
  }
  Serial.print("\n");

  delay(1000);
}
