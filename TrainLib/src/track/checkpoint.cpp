#include "checkpoint.h"

Checkpoint::Checkpoint(LightSensor &sensor, Train *train)
    : _sensor(sensor), _train(train)
{}

Train* Checkpoint::getTrain()
{
    return _train;
}

void Checkpoint::setTrain(Train* train)
{
    _train = train;
}

void Checkpoint::loop()
{
    _sensor.loop();

    if (isSleeping()) {
        return;
    }
    wake();

    if (hasJustArrived()) {
        _updateTrain();
    }
}

bool Checkpoint::isSleeping()
{
    return _sleepTimeout && millis() <= _sleepTimeout;
}

void Checkpoint::sleep()
{
    sleep(0xFFFFFFFF);
    _sensor.sleep();
}

void Checkpoint::sleep(unsigned long time)
{
    _sleepTimeout = millis() + time;
    _sensor.sleep(time);
}

void Checkpoint::wake()
{
    _sleepTimeout = 0;
    _sensor.wake();
}

bool Checkpoint::isTrainPresent()
{
    return _sensor.isCovered();
}

bool Checkpoint::hasJustArrived()
{
    return _sensor.isJustCovered();
}

bool Checkpoint::hasJustLeft()
{
    return _sensor.isJustCleared();
}

bool Checkpoint::hasJustChanged()
{
    return _sensor.isJustChanged();
}

void Checkpoint::_updateTrain()
{
    Train* newTrain = _sensor.getTrain();
    if (newTrain) {
        setTrain(newTrain);
    }
}