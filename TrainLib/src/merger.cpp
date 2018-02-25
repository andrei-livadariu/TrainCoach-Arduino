#include "merger.h"

Merger::Merger(MergerTrack tracks[], byte nrTracks)
    : Merger(tracks, nrTracks, Merger::DefaultLockTime)
{}

Merger::Merger(MergerTrack tracks[], byte nrTracks, unsigned long lockTime)
    : _tracks(tracks), _nrTracks(nrTracks), _lockTime(lockTime)
{}

void Merger::loop()
{
    if (_unlockTimeout && millis() > _unlockTimeout) {
        unlockSemaphores();
        _unlockTimeout = 0;
    }

    for (byte i = 0; i < _nrTracks; ++i) {
        if (_tracks[i].sensor.isCovered()) {
            if (!_unlockTimeout) {
                _unlockTimeout = millis() + _lockTime;
                _tracks[i].train.start();
                lockSemaphores(i);
            } else if (_tracks[i].sensor.isJustCovered()) {
                _tracks[i].train.stop();
            }
        }
    }
}

void Merger::unlockSemaphores()
{
    for (byte i = 0; i < _nrTracks; ++i) {
        _tracks[i].semaphore.unlock();
    }
}

void Merger::lockSemaphores(byte except)
{
    for (byte i = 0; i < _nrTracks; ++i) {
        if (i != except) {
            _tracks[i].semaphore.lock();
        }
    }
}