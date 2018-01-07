#include "semaphore.h"

Semaphore::Semaphore(byte pin)
    : Semaphore(pin, SemaphoreColor::Green)
{}

Semaphore::Semaphore(byte pin, SemaphoreColor initialColor)
    : Semaphore(pin, initialColor, SemaphoreColor::Red)
{}

Semaphore::Semaphore(byte pin, SemaphoreColor initialColor, SemaphoreColor highColor)
    : _pin(pin), _color(initialColor), _highColor(highColor)
{
    pinMode(_pin, OUTPUT);
    refresh();
}

SemaphoreColor Semaphore::getColor()
{
    return _color;
}

void Semaphore::setColor(SemaphoreColor color)
{
    _color = color;
    refresh();
}

void Semaphore::lock()
{
    setColor(SemaphoreColor::Red);
}

void Semaphore::unlock()
{
    setColor(SemaphoreColor::Green);
}

bool Semaphore::isRed()
{
    return _color == SemaphoreColor::Red;
}

bool Semaphore::isGreen()
{
    return _color == SemaphoreColor::Green;
}

void Semaphore::refresh()
{
    digitalWrite(_pin, _color == _highColor ? HIGH : LOW);
}