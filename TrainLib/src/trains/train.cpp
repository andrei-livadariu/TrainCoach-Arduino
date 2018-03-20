#include "train.h"

const TrainInfo TrainInfo::blankInfo;

Train::Train(IMotor &motor)
    : _info(TrainInfo::blankInfo), _motor(motor)
{}

Train::Train(TrainInfo &info, IMotor &motor)
    : _info(info), _motor(motor)
{}

const TrainInfo& Train::getInfo()
{
    return _info;
}

IMotor& Train::getMotor()
{
    return _motor;
}

void Train::start()
{
    _motor.start();
}

void Train::stop()
{
    _motor.stop();
}

void Train::reverse()
{
    _motor.reverse();
}