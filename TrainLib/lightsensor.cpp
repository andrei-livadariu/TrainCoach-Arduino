#include "lightsensor.h"

LightSensor::LightSensor(int pin, int threshold)
    : _pin(pin), _threshold(threshold)
{}

void LightSensor::loop()
{
    _wasCovered = _isCovered;

    int lightValue = analogRead(_pin);
    if (lightValue > _threshold) {
        clear();
    } else {
        cover();
    }
}

bool LightSensor::isClear()
{
    return !_isCovered;
}

bool LightSensor::isCovered()
{
    return _isCovered;
}

bool LightSensor::isJustCleared()
{
    return !_isCovered && _wasCovered;
}

bool LightSensor::isJustCovered()
{
    return _isCovered && !_wasCovered;
}

bool LightSensor::isJustChanged()
{
    return _isCovered != _wasCovered;
}

void LightSensor::cover()
{
    _isCovered = true;
}

void LightSensor::clear()
{
    _isCovered = false;
}