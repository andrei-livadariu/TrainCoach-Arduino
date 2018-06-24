#include "timer.h"

Timer::Timer()
{}

Timer::Timer(unsigned long duration)
    : _duration(duration)
{}

unsigned long Timer::getDuration() const
{
    return _duration;
}

void Timer::setDuration(unsigned long duration)
{
    _duration = duration;
}

unsigned long Timer::getRemainingTime() const
{
    if (!_timeout) {
        return _duration;
    }

    if (isDone()) {
        return 0;
    }

    return _timeout - millis();
}

void Timer::start()
{
    _timeout = millis() + _duration;
}

void Timer::start(unsigned long duration)
{
    setDuration(duration);
    start();
}

void Timer::tick(unsigned long ticks)
{
    start(ticks * _duration);
}

void Timer::reset()
{
    _timeout = 0;
}

bool Timer::isDone() const
{
    return _timeout && _timeout <= millis();
}

bool Timer::isRunning() const
{
    return _timeout && _timeout > millis();
}