#include "train.h"

Train::Train(byte pin, TrainColor color, TrainChannel channel)
    : _motor(pin), _color(color), _channel(channel)
{}

void Train::start(TrainSpeed speed, TrainDirection direction)
{
    int step = (16 + (int) speed * (int) direction) % 16;

    _motor.SingleOutput(0, step, (int) _color, (int) _channel);
    _speed = speed;
    _direction = direction;
}

void Train::start(TrainSpeed speed)
{
    this->start(speed, _direction);
}

void Train::start()
{
    this->start(_speed, _direction);
}

void Train::forward(TrainSpeed speed)
{
    this->start(speed, TrainDirection::Forward);
}

void Train::backward(TrainSpeed speed)
{
    this->start(speed, TrainDirection::Backward);
}

void Train::stop()
{
    _motor.SingleOutput(0, PWM_FLT, (int) _color, (int) _channel);
}

void Train::reverse()
{
    _direction = _direction == TrainDirection::Forward ? TrainDirection::Backward : TrainDirection::Forward;
}