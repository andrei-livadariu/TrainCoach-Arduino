#ifndef TRAINLIB_SEMAPHORE_H
#define TRAINLIB_SEMAPHORE_H

#include <Arduino.h>

enum class SemaphoreColor {
    Red,
    Green,
};

class Semaphore
{
    public:
        Semaphore(byte pin);
        Semaphore(byte pin, SemaphoreColor initialColor);
        Semaphore(byte pin, SemaphoreColor initialColor, SemaphoreColor highColor);

        SemaphoreColor getColor();
        void setColor(SemaphoreColor color);

        void lock();
        void unlock();

        bool isRed();
        bool isGreen();

    private:
        const SemaphoreColor _highColor;
        SemaphoreColor _color;
        const byte _pin;

        void refresh();
};

#endif