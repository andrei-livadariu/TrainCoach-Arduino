#include "merger.h"

Merger::Merger(Checkpoint *tracks[], byte nrTracks)
    : Merger(tracks, nrTracks, Merger::DefaultLockTime)
{}

Merger::Merger(Checkpoint *tracks[], byte nrTracks, unsigned long lockTime)
    : _tracks(tracks), _nrTracks(nrTracks), _lockTimer(lockTime)
{}

Train* Merger::getLastTrain()
{
    return _lastTrain;
}

void Merger::loop()
{
    _wasAllowing = _isAllowing;

    if (_lockTimer.isDone()) {
        _unlock();
    }

    for (byte i = 0; i < _nrTracks; ++i) {
        if (!_tracks[i]->isTrainPresent()) {
            continue;
        }

        Train *train = _tracks[i]->getTrain();
        if (!train) {
            continue;
        }
        
        if (isFree()) {
            _allow(train);
            _tracks[i]->sleep(_lockTimer.getDuration());
        } else if (_tracks[i]->hasJustArrived()) {
            train->stop();
        }
    }
}

bool Merger::isAllowing()
{
    return _isAllowing;
}

bool Merger::isFree()
{
    return !_isAllowing;
}

bool Merger::isJustAllowing()
{
    return _isAllowing && !_wasAllowing;
}

bool Merger::isJustFreed()
{
    return !_isAllowing && _wasAllowing;
}

bool Merger::isJustChanged()
{
    return _isAllowing != _wasAllowing;
}

void Merger::_allow(Train *train)
{
    _lock();
    train->start();
    _lastTrain = train;
}

void Merger::_lock()
{
    _lockTimer.start();
    _wasAllowing = false;
    _isAllowing = true;
}

void Merger::_unlock()
{
    _lockTimer.reset();
    _isAllowing = false;
}