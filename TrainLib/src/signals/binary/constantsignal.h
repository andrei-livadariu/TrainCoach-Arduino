#ifndef TRAINLIB_CONSTANTSIGNAL_H
#define TRAINLIB_CONSTANTSIGNAL_H

#include <Arduino.h>
#include "ibinarysignal.h"

class ConstantSignal : public IBinarySignal
{
    public:
        ConstantSignal(byte pin);
        ConstantSignal(byte pin, bool locked);
        ConstantSignal(byte pin, bool locked, bool reverse);

        bool getLock();
        void setLock(bool lock);

    private:
        const bool _reverse;
        bool _locked;
        const byte _pin;

        void refresh();
};

typedef ConstantSignal RedGreenSignal;

#endif