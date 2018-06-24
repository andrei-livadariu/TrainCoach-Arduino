#include "lego9vmotor.h"

Lego9VMotor::Lego9VMotor(byte c1, byte c2)
    : _c1(c1), _c2(c2), _speed(Lego9VMotor::DefaultSpeed)
{}

Lego9VMotor::Lego9VMotor(byte c1, byte c2, byte speed)
    : _c1(c1), _c2(c2), _speed(speed)
{
    pinMode(_c1, OUTPUT);
    pinMode(_c2, OUTPUT);
}

byte Lego9VMotor::getSpeed()
{
    return _speed;
}

void Lego9VMotor::setSpeed(byte speed)
{
    _speed = speed;
    if (isRunning()) {
        start();
    }
}

MotorDirection Lego9VMotor::getDirection()
{
    return _direction;
}

void Lego9VMotor::setDirection(MotorDirection direction)
{
    _direction = direction;
    if (isRunning()) {
        start();
    }
}

bool Lego9VMotor::isRunning()
{
    return _isRunning;
}

void Lego9VMotor::start()
{
    if (_direction == MotorDirection::Forward) {
        // We are sending the commands in this order because we want to avoid having PWM / PWM at any time
        analogWrite(_c2, 0);
        analogWrite(_c1, _speed);
    } else {
        analogWrite(_c1, 0);
        analogWrite(_c2, _speed);
    }

    _isRunning = true;
}

void Lego9VMotor::stop()
{
    analogWrite(_c1, 0);
    analogWrite(_c2, 0);
    _isRunning = false;
}
