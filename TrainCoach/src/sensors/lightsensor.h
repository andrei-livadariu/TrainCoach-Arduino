#ifndef TRAINLIB_LIGHTSENSOR_H
#define TRAINLIB_LIGHTSENSOR_H

#include <Arduino.h>
#include "trains\train.h"
#include "utilities\timer.h"

class LightSensor
{
    public:
        LightSensor(byte pin, int threshold);

        void loop();

        Train* getTrain();
        
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
        Timer _sleepTimer;

        const byte _pin;
        const int _threshold;
        bool _isCovered = false;
        bool _wasCovered = false;

        void cover();
        void clear();
};

#endif