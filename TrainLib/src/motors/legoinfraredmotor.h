#ifndef TRAINLIB_LEGOINFRAREDMOTOR_H
#define TRAINLIB_LEGOINFRAREDMOTOR_H

#include <Arduino.h>
#include <legopowerfunctions.h>
#include "motors\imotor.h"

enum class InfraRedColor
{
    Red = RED,
    Blue = BLUE,
};

enum class InfraRedChannel
{
    One = CH1,
    Two = CH2,
    Three = CH3,
    Four = CH4,
};

class LegoInfraRedMotor : public IMotor
{
    public:
        static const byte SpeedStop = 0;
        static const byte SpeedOne = 32;
        static const byte SpeedTwo = 64;
        static const byte SpeedThree = 96;
        static const byte SpeedFour = 128;
        static const byte SpeedFive = 160;
        static const byte SpeedSix = 192;
        static const byte SpeedSeven = 224;

        LegoInfraRedMotor(byte pin, InfraRedColor color, InfraRedChannel channel);
        LegoInfraRedMotor(byte pin, InfraRedColor color, InfraRedChannel channel, byte speed);

        byte getSpeed() override;
        void setSpeed(byte speed) override;

        MotorDirection getDirection() override;
        void setDirection(MotorDirection direction) override;

        bool isRunning() override;

        void start() override;
        void stop() override;

    private:
        static const byte DefaultSpeed = LegoInfraRedMotor::SpeedFour;

        LEGOPowerFunctions _motor;
        const InfraRedColor _color;
        const InfraRedChannel _channel;
        
        MotorDirection _direction = MotorDirection::Forward;
        byte _speed;
        bool _isRunning = false;
};

#endif