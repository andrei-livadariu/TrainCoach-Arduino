#ifndef TRAINLIB_BINARYSIGNALSET_H
#define TRAINLIB_BINARYSIGNALSET_H

#include <Arduino.h>
#include "ibinarysignal.h"

class BinarySignalSet
{
    public:
        BinarySignalSet(IBinarySignal *signals[], byte nrSignals);

        void lock(byte position);
        void lockAll();
        void lockAllExcept(byte position);
        void lockOnly(byte position);

        void unlock(byte position);
        void unlockAll();
        void unlockAllExcept(byte position);
        void unlockOnly(byte position);

    private:
        IBinarySignal **_signals;
        const byte _nrSignals;
};

#endif