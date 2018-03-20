#ifndef TRAINLIB_IMOTOR_H
#define TRAINLIB_IMOTOR_H

#include <Arduino.h>

enum class MotorDirection {
    Forward = 1,
    Backward = -1,
};

class IMotor
{
    public:
        virtual ~IMotor() {}

        virtual byte getSpeed() = 0;
        virtual void setSpeed(byte speed) = 0;

        virtual MotorDirection getDirection() = 0;
        virtual void setDirection(MotorDirection direction) = 0;

        virtual bool isRunning() = 0;

        virtual void start() = 0;
        virtual void start(byte speed);
        virtual void start(MotorDirection direction);
        virtual void start(byte speed, MotorDirection direction);

        virtual void stop() = 0;

        virtual void forward();
        virtual void forward(byte speed);

        virtual void backward();
        virtual void backward(byte speed);

        virtual void reverse();
};

#endif