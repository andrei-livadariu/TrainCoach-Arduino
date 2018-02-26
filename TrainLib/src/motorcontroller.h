#ifndef TRAINLIB_MOTORCONTROLLER_H
#define TRAINLIB_MOTORCONTROLLER_H

#include <Arduino.h>
#include "imotor.h"

class MotorController : public IMotor
{
    public:
        MotorController(byte in1, byte in2, byte ena);

        byte getSpeed() override;
        void setSpeed(byte speed) override;

        MotorDirection getDirection() override;
        void setDirection(MotorDirection direction) override;

        bool isRunning() override;

        void start() override;
        void stop() override;

    private:
        const byte _in1;
        const byte _in2;
        const byte _ena;

        MotorDirection _direction = MotorDirection::Forward;
        byte _speed = 255;
        bool _isRunning = false;
};

#endif