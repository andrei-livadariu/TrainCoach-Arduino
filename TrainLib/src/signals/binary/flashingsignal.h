#ifndef TRAINLIB_FLASHINGSIGNAL_H
#define TRAINLIB_FLASHINGSIGNAL_H

#include <Arduino.h>
#include "ibinarysignal.h"

class FlashingSignal : public IBinarySignal
{
    public:
        FlashingSignal(byte pin);
        FlashingSignal(byte pin, unsigned long flashSpeed);
        FlashingSignal(byte pin, unsigned long flashSpeed, bool locked);

        void loop();

        bool getLock();
        void setLock(bool lock);

    private:
        static const unsigned long DefaultFlashSpeed = 500;

        const unsigned long _flashSpeed;
        unsigned long _flipTimeout = 0;
        bool _locked;
        bool _visiblyLocked;
        const byte _pin;

        void refresh();
};

#endif