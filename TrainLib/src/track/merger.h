#ifndef TRAINLIB_MERGER_H
#define TRAINLIB_MERGER_H

#include "trains\train.h"
#include "sensors\lightsensor.h"
#include "signals\semaphore.h"

struct MergerTrack
{
    Train &train;
    LightSensor &sensor;
    Semaphore &semaphore;
    
    MergerTrack(Train &train, LightSensor &sensor, Semaphore &semaphore)
        : train(train), sensor(sensor), semaphore(semaphore)
    {}
};

class Merger
{
    public:
        static const unsigned long DefaultLockTime = 3000;

        Merger(MergerTrack tracks[], byte nrTracks);
        Merger(MergerTrack tracks[], byte nrTracks, unsigned long lockTime);
        void loop();

    private:
        MergerTrack *_tracks;
        unsigned long _lockTime;
        unsigned long _unlockTimeout = 0;
        byte _nrTracks;

        void unlockSemaphores();
        void lockSemaphores(byte except);
};

#endif