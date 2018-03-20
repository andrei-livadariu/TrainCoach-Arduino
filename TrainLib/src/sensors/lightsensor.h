#ifndef TRAINLIB_LIGHTSENSOR_H
#define TRAINLIB_LIGHTSENSOR_H

#include <Arduino.h>

class LightSensor
{
    public:
        LightSensor(byte pin, int threshold);

        void loop();
        
        bool isSleeping();
        void sleep();
        void sleep(unsigned long time);
        void wake();
        
        bool isClear();
        bool isCovered();

        bool isJustCleared();
        bool isJustCovered();
        bool isJustChanged();

    private:
        const byte _pin;
        const int _threshold;
        unsigned long _sleepTimeout = 0;
        bool _isCovered = false;
        bool _wasCovered = false;

        void cover();
        void clear();
};

#endif