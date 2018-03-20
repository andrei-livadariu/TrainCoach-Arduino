#ifndef TRAINLIB_MERGER_H
#define TRAINLIB_MERGER_H

#include "track\checkpoint.h"
#include "trains\train.h"
#include "sensors\lightsensor.h"
#include "signals\semaphore.h"

class Merger
{
    public:
        static const unsigned long DefaultLockTime = 3000;

        Merger(Checkpoint *tracks[], byte nrTracks);
        Merger(Checkpoint *tracks[], byte nrTracks, unsigned long lockTime);

        Train* getLastTrain();

        bool isAllowing();
        bool isFree();

        bool isJustAllowing();
        bool isJustFreed();
        bool isJustChanged();

        void loop();
    private:
        Checkpoint **_tracks;
        Train *_lastTrain = nullptr;
        unsigned long _lockTime;
        unsigned long _unlockTimeout = 0;
        byte _nrTracks;
        bool _isAllowing = false;
        bool _wasAllowing = false;

        void _allow(Train *train);
        void _lock();
        bool _canUnlock();
        void _unlock();
};

#endif