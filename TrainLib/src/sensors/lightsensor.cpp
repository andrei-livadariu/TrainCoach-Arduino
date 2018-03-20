#include "lightsensor.h"

LightSensor::LightSensor(byte pin, int threshold)
    : _pin(pin), _threshold(threshold)
{
    pinMode(_pin, INPUT);
}

void LightSensor::loop()
{
    _wasCovered = _isCovered;

    if (isSleeping()) {
        return;
    }
    wake();

    int lightValue = analogRead(_pin);
    if (lightValue > _threshold) {
        clear();
    } else {
        cover();
    }
}

Train* LightSensor::getTrain()
{
    return nullptr;
}

bool LightSensor::isSleeping()
{
    return _sleepTimeout && millis() <= _sleepTimeout;
}

void LightSensor::sleep()
{
    sleep(0xFFFFFFFF);
}

void LightSensor::sleep(unsigned long time)
{
    _sleepTimeout = millis() + time;
    _isCovered = false;
}

void LightSensor::wake()
{
    _sleepTimeout = 0;
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