#include "motorcontroller.h"

MotorController::MotorController(byte in1, byte in2, byte ena)
    : MotorController(in1, in2, ena, MotorController::DefaultSpeed)
{}

MotorController::MotorController(byte in1, byte in2, byte ena, byte speed)
    : _in1(in1), _in2(in2), _ena(ena), _speed(speed)
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
    if (isRunning()) {
        start();
    }
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

void MotorController::stop()
{
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, LOW);
    _isRunning = false;
}
