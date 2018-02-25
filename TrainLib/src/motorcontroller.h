#ifndef TRAINLIB_MOTORCONTROLLER_H
#define TRAINLIB_MOTORCONTROLLER_H

#include <Arduino.h>

enum class MotorDirection {
    Forward = 1,
    Backward = -1,
};

class MotorController
{
    public:
        MotorController(byte in1, byte in2, byte ena);

        byte getSpeed();
        void setSpeed(byte speed);

        MotorDirection getDirection();
        void setDirection(MotorDirection direction);

        bool isRunning();

        void start();
        void start(byte speed);
        void start(MotorDirection direction);
        void start(byte speed, MotorDirection direction);

        void stop();

        void forward();
        void forward(byte speed);

        void backward();
        void backward(byte speed);

        void reverse();

    private:
        const byte _in1;
        const byte _in2;
        const byte _ena;

        MotorDirection _direction = MotorDirection::Forward;
        byte _speed = 255;
        bool _isRunning = false;
};

#endif