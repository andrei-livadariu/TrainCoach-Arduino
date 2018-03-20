#include "legoinfraredmotor.h"

LegoInfraRedMotor::LegoInfraRedMotor(byte pin, InfraRedColor color, InfraRedChannel channel)
    : _motor(pin), _color(color), _channel(channel), _speed(LegoInfraRedMotor::DefaultSpeed)
{}

LegoInfraRedMotor::LegoInfraRedMotor(byte pin, InfraRedColor color, InfraRedChannel channel, byte speed)
    : _motor(pin), _color(color), _channel(channel), _speed(speed)
{}

byte LegoInfraRedMotor::getSpeed()
{
    return _speed;
}

void LegoInfraRedMotor::setSpeed(byte speed)
{
    _speed = speed;
    if (isRunning()) {
        start();
    }
}

MotorDirection LegoInfraRedMotor::getDirection()
{
    return _direction;
}

void LegoInfraRedMotor::setDirection(MotorDirection direction)
{
    _direction = direction;
    if (isRunning()) {
        start();
    }
}

bool LegoInfraRedMotor::isRunning()
{
    return _isRunning;
}

void LegoInfraRedMotor::start()
{
    // Map the speed and the direction to the Power Functions constants
    int step = (16 + (int) (_speed / 32) * (int) _direction) % 16;
    _motor.SingleOutput(0, step, (int) _color, (int) _channel);
    _isRunning = _speed > 0;
}

void LegoInfraRedMotor::stop()
{
    _motor.SingleOutput(0, PWM_FLT, (int) _color, (int) _channel);
    _isRunning = false;
}
