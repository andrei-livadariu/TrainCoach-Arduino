#ifndef TRAINLIB_MERGER_H
#define TRAINLIB_MERGER_H

#include "track\checkpoint.h"
#include "trains\train.h"
#include "sensors\lightsensor.h"
#include "utilities\timer.h"

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
        Timer _lockTimer;
        Checkpoint **_tracks;
        Train *_lastTrain = nullptr;
        byte _nrTracks;
        bool _isAllowing = false;
        bool _wasAllowing = false;

        void _allow(Train *train);
        void _lock();
        void _unlock();
};

#endif