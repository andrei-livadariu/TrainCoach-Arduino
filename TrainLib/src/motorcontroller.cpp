#include "motorcontroller.h"

MotorController::MotorController(byte in1, byte in2, byte ena)
    : _in1(in1), _in2(in2), _ena(ena)
{
    pinMode(_in1, OUTPUT);
    pinMode(_in2, OUTPUT);
    pinMode(_ena, OUTPUT);
    setSpeed(_speed);
}

byte MotorController::getSpeed()
{
    return _speed;
}

void MotorController::setSpeed(byte speed)
{
    _speed = speed;
    analogWrite(_ena, _speed);
}

MotorDirection MotorController::getDirection()
{
    return _direction;
}

void MotorController::setDirection(MotorDirection direction)
{
    _direction = direction;
}

bool MotorController::isRunning()
{
    return _isRunning;
}

void MotorController::start()
{
    if (_direction == MotorDirection::Forward) {
        digitalWrite(_in1, LOW);
        digitalWrite(_in2, HIGH);
    } else {
        // We are sending the commands in this order because we want to avoid having HIGH / HIGH at any time
        digitalWrite(_in2, LOW);
        digitalWrite(_in1, HIGH);
    }

    _isRunning = true;
}

void MotorController::start(byte speed)
{
    setSpeed(speed);
    start();
}

void MotorController::start(MotorDirection direction)
{
    setDirection(direction);
    start();
}

void MotorController::start(byte speed, MotorDirection direction)
{
    setSpeed(speed);
    setDirection(direction);
    start();
}

void MotorController::stop()
{
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, LOW);
    _isRunning = false;
}

void MotorController::forward()
{
    start(MotorDirection::Forward);
}

void MotorController::forward(byte speed)
{
    setSpeed(speed);
    forward();
}

void MotorController::backward()
{
    start(MotorDirection::Backward);
}

void MotorController::backward(byte speed)
{
    setSpeed(speed);
    backward();
}

void MotorController::reverse()
{
    setDirection(_direction == MotorDirection::Forward ? MotorDirection::Backward : MotorDirection::Forward);
}
