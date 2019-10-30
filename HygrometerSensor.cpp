/*
 * \brief Get humidity information from Rain drop or soil moisture sensor (implementation)
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 19 July 2016
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 2.0
 *
 * \history
 *  - v1.0 Main design of the library
 *  - v2.0 Change library and functions name
 */

#include "HygrometerSensor.h"

HygrometerSensor::HygrometerSensor(eHygrometerKind kind, int pin)
{
  _kind = kind;
  _pin = pin;

  if (_kind == DIGITAL) {
    pinMode(pin, INPUT);
  }
  _min = ANALOG_HUMIDITY_MIN;
  _max = ANALOG_HUMIDITY_MAX;
  _is_humid = ANALOG_IS_HUMID;
}

bool HygrometerSensor::isHumid() const
{
  return (readHumidityValue() < _is_humid);
}

int HygrometerSensor::readHumidityValue() const
{
  int sensor_value = 0;

  switch (_kind)
  {
      case ANALOG:
        sensor_value = analogRead(_pin);
      break;
      case DIGITAL:
        if (digitalRead(_pin)) {
          sensor_value = _is_humid + 1;
        } else {
          sensor_value = _is_humid - 1;
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

int HygrometerSensor::readPercentageHumidity() const
{
  return (int)(100 * (float)((float) (_max - readHumidityValue()) / (float) (_max - _min)));
}

bool HygrometerSensor::setAnalogParameters(int min, int max, int is_humid)
{
  if (min >= max || is_humid >= max || is_humid <= min) {
    return false;
  }

  _min = min;
  _max = max;
  _is_humid = is_humid;

  return true;
}

void HygrometerSensor::getAnalogParameters(int &min, int &max, int &is_humid) const
{
  min = _min;
  max = _max;
  is_humid = _is_humid;
}
