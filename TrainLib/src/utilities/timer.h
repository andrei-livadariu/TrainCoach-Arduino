#ifndef TRAINLIB_TIMER_H
#define TRAINLIB_TIMER_H

#include <Arduino.h>

class Timer
{
    public:
        Timer();
        Timer(unsigned long duration);

        unsigned long getDuration() const;
        void setDuration(unsigned long duration);
        unsigned long getRemainingTime() const;

        void start();
        void start(unsigned long duration);
        void tick(unsigned long ticks);
        void reset();

        bool isDone() const;
        bool isRunning() const;

    private:
        unsigned long _duration = 0;
        unsigned long _timeout = 0;
};

#endif