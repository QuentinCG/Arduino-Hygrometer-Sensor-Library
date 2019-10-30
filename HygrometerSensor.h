/*
 * \brief Get humidity information from Hygrometer sensor (Rain drop or soil moisture sensor)
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 19 July 2016
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 2.0
 *
 * \history
 *  - v1.0 Main design of the library
 *  - v1.1 Add Arduino < 1.0 compatibility
 *  - v2.0 Change library and functions name
 */

#ifndef HygrometerSensor_h
#define HygrometerSensor_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define ANALOG_HUMIDITY_MIN 0
#define ANALOG_HUMIDITY_MAX 1024
#define ANALOG_IS_HUMID 700

class HygrometerSensor
{
  public:

  enum eHygrometerKind {
    ANALOG,
    DIGITAL
  };

    /*!
     * \brief HygrometerSensor Initialize Hygrometer sensor
     *
     * \param kind (eHygrometerKind) Hygrometer sensor kind (analog or digital)
     * \param pin (int) Hygrometer sensor output pin
     */
    HygrometerSensor(eHygrometerKind kind, int pin);

    /*!
     * \brief isHumid Check if sensor is wet or not
     *
     * \return (bool) True if it's humid (raining or soil moist)
     */
    bool isHumid() const;

    /*!
     * \brief readHumidityValue Get ANALOG output from hygrometer sensor
     *
     * \return (int) Humidity value
     *
     * \warning If the sensor is digital, the return value will be ANALOG_IS_HUMID-1 if humid and ANALOG_IS_HUMID+1 if not humid.
     */
    int readHumidityValue() const;

    /*!
     * \brief readPercentageHumidity Get humidity percentage from hygrometer sensor
     *
     * \return (int) Humidity percentage
     *
     * \warning If the sensor is digital, the return value will be inconsistent values
     */
     int readPercentageHumidity() const;

    /*!
     * \brief setAnalogParameters Set ANALOG output range and value considered as humid
     *
     * \param min (int) Minimum value for sensor range (default: ANALOG_HUMIDITY_MIN)
     * \param max (int) Maximum value for sensor range (default: ANALOG_HUMIDITY_MAX)
     * \param is_humid (int) Maximum value considered as humid (default: ANALOG_IS_HUMID)
     *
     * \return (boot) Set done properly
     */
    bool setAnalogParameters(int min, int max, int is_humid);

    /*!
     * \brief getAnalogParameters Get ANALOG output range and value considered as humid
     *
     * \param min[out] (int&) Minimum value for sensor range
     * \param max[out] (int&) Maximum value for sensor range
     * \param is_humid[out] (int) Maximum value considered as humid
     */
    void getAnalogParameters(int &min, int &max, int &is_humid) const;

  private:
    eHygrometerKind _kind;
    int _pin;
    int _min;
    int _max;
    int _is_humid;
};

#endif //HygrometerSensor_h

