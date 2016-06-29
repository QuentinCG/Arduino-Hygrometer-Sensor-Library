/*
 * \brief Get rain information from Rain drop sensor
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 29 June 2016
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 1.0
 */

#ifndef RainDropSensor_h
#define RainDropSensor_h

#include "Arduino.h"

#define ANALOG_RAIN_DROP_MIN 0
#define ANALOG_RAIN_DROP_MAX 1024
#define ANALOG_IS_RAINING 700

class RainDropSensor
{
  public:

  enum eRainDropKind {
    ANALOG,
    DIGITAL
  };

    /*!
     * \brief RainDropSensor Initialize rain drop sensor
     *
     * \param kind (eRainDropKind) Rain drop sensor kind (analog or digital)
     * \param pin (int) Rain drop sensor output pin
     */
    RainDropSensor(eRainDropKind kind, int pin);

    /*!
     * \brief isRaining Check if sensor is wet or not
     *
     * \return (bool) True if raining
     */
    bool isRaining();

    /*!
     * \brief readRainDropValue Get ANALOG output from rain drop sensor
     *
     * \return (int) Rain drop value
     *
     * \warning If the rain drop is digital, the return value will be ANALOG_IS_RAINING-1 if raining and ANALOG_IS_RAINING+1 if not raining.
     */
    int readRainDropValue();

    /*!
     * \brief setAnalogParameters Set ANALOG output range and value considered as rain
     *
     * \param min (int) Minimum value for rain drop sensor range (default: ANALOG_RAIN_DROP_MIN)
     * \param max (int) Maximum value for rain drop sensor range (default: ANALOG_RAIN_DROP_MAX)
     * \param is_raining (int) Maximum value considered as raining (default: ANALOG_IS_RAINING)
     *
     * \return (boot) Set done properly
     */
    bool setAnalogParameters(int min, int max, int is_raining);

    /*!
     * \brief getAnalogParameters Get ANALOG output range and value considered as rain
     *
     * \param min[out] (int&) Minimum value for rain drop sensor range
     * \param max[out] (int&) Maximum value for rain drop sensor range
     * \param is_raining[out] (int) Maximum value considered as raining
     */
    void getAnalogParameters(int &min, int &max, int &is_raining);

  private:
    eRainDropKind _kind;
    int _pin;
    int _min;
    int _max;
    int _is_raining;
};

#endif //RainDropSensor_h

