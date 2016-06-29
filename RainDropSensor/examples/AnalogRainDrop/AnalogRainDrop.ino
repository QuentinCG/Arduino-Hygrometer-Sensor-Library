/*
 * \brief Get rain information from Analog Rain drop sensor every second
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 29 June 2016
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 1.0
 */

#include <RainDropSensor.h>

// Create Analog rain drop sensor instance on A1 pin
RainDropSensor analog_rain_drop(RainDropSensor::ANALOG, A1);

void setup(void)
{
  Serial.begin(9600);

  // Set analog parameters (min value, max value, value to switch from "dry" to "is raining") (optional call)
  if (!analog_rain_drop.setAnalogParameters(ANALOG_RAIN_DROP_MIN, ANALOG_RAIN_DROP_MAX, 800)) {
    Serial.print("Error while setting Analog parameters\n");
  }

  // Get analog parameters (optional call)
  int min, max, is_raining;
  analog_rain_drop.getAnalogParameters(min, max, is_raining);
  Serial.print("Minimum analog value: ");
  Serial.print(min, DEC);
  Serial.print("\nMaximum analog value: ");
  Serial.print(max, DEC);
  Serial.print("\nValue used as switch from 'dry' to 'is raining': ");
  Serial.print(is_raining, DEC);
  Serial.print("\n");
}

void loop()
{
  // Check rain state and value every sec

  Serial.print("Rain drop value: ");
  Serial.print(analog_rain_drop.readRainDropValue());
  Serial.print(" (");
  if (analog_rain_drop.isRaining()) {
    Serial.print("raining");
  } else {
    Serial.print("dry");
  }
  Serial.print(")\n");

  delay(1000);
}
