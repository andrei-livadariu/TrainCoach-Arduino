#include "imotor.h"

void IMotor::start(byte speed)
{
    setSpeed(speed);
    start();
}

void IMotor::start(MotorDirection direction)
{
    setDirection(direction);
    start();
}

void IMotor::start(byte speed, MotorDirection direction)
{
    setSpeed(speed);
    setDirection(direction);
    start();
}

void IMotor::forward()
{
    start(MotorDirection::Forward);
}

void IMotor::forward(byte speed)
{
    setSpeed(speed);
    forward();
}

void IMotor::backward()
{
    start(MotorDirection::Backward);
}

void IMotor::backward(byte speed)
{
    setSpeed(speed);
    backward();
}

void IMotor::reverse()
{
    setDirection(getDirection() == MotorDirection::Forward ? MotorDirection::Backward : MotorDirection::Forward);
}