/*
 * \brief Get rain information from Rain drop sensor (implementation)
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 29 June 2016
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 1.1
 */

#include "RainDropSensor.h"

RainDropSensor::RainDropSensor(eRainDropKind kind, int pin)
{
  _kind = kind;
  _pin = pin;

  if (_kind == DIGITAL) {
    pinMode(pin, INPUT);
  }
  _min = ANALOG_RAIN_DROP_MIN;
  _max = ANALOG_RAIN_DROP_MAX;
  _is_raining = ANALOG_IS_RAINING;
}

bool RainDropSensor::isRaining()
{
  return (readRainDropValue() < _is_raining);
}

int RainDropSensor::readRainDropValue()
{
  int sensor_value = 0;

  switch (_kind)
  {
      case ANALOG:
        sensor_value = analogRead(_pin);
      break;
      case DIGITAL:
        if (digitalRead(_pin)) {
          sensor_value = _is_raining + 1;
        } else {
          sensor_value = _is_raining - 1;
        }
      break;
      default:
      break;
  }

  if (sensor_value > _max) {
    sensor_value = _max;
  } else if (sensor_value < _min) {
    sensor_value = _min;
  }

  return sensor_value;
}

bool RainDropSensor::setAnalogParameters(int min, int max, int is_raining)
{
  if (min >= max || is_raining >= max || is_raining <= min) {
    return false;
  }

  _min = min;
  _max = max;
  _is_raining = is_raining;

  return true;
}

void RainDropSensor::getAnalogParameters(int &min, int &max, int &is_raining)
{
  min = _min;
  max = _max;
  is_raining = _is_raining;
}
