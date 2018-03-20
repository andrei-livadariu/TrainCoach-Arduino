#ifndef TRAINLIB_LEGO9VMOTOR_H
#define TRAINLIB_LEGO9VMOTOR_H

#include <Arduino.h>
#include "motors\imotor.h"

class Lego9VMotor : public IMotor
{
    public:
        Lego9VMotor(byte c1, byte c2);

        byte getSpeed() override;
        void setSpeed(byte speed) override;

        MotorDirection getDirection() override;
        void setDirection(MotorDirection direction) override;

        bool isRunning() override;

        void start() override;
        void stop() override;

    private:
        const byte _c1;
        const byte _c2;

        MotorDirection _direction = MotorDirection::Forward;
        byte _speed = 255;
        bool _isRunning = false;
};

#endif