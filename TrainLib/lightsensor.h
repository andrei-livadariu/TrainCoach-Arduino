#ifndef TRAINLIB_LIGHTSENSOR_H
#define TRAINLIB_LIGHTSENSOR_H

#include <Arduino.h>

class LightSensor
{
    public:
        LightSensor(int pin, int threshold);

        void loop();
        
        bool isClear();
        bool isCovered();

        bool isJustCleared();
        bool isJustCovered();
        bool isJustChanged();

    private:
        const int _pin;
        const int _threshold;
        bool _isCovered = false;
        bool _wasCovered = false;

        void cover();
        void clear();
};

#endif