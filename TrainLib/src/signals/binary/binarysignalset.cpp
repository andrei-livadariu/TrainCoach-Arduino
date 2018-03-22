#include "binarysignalset.h"

BinarySignalSet::BinarySignalSet(IBinarySignal *signals[], byte nrSignals)
    : _signals(signals), _nrSignals(nrSignals)
{}

void BinarySignalSet::lock(byte position)
{
    _signals[position]->lock();
}

void BinarySignalSet::lockAll()
{
    for (byte i = 0; i < _nrSignals; ++i) {
        lock(i);
    }
}

void BinarySignalSet::lockAllExcept(byte position)
{
    for (byte i = 0; i < position; ++i) {
        lock(i);
    }
    unlock(position);
    for (byte i = position + 1; i < _nrSignals; ++i) {
        lock(i);
    }
}

void BinarySignalSet::lockOnly(byte position)
{
    unlockAllExcept(position);
}

void BinarySignalSet::unlock(byte position)
{
    _signals[position]->unlock();
}

void BinarySignalSet::unlockAll()
{
    for (byte i = 0; i < _nrSignals; ++i) {
        unlock(i);
    }
}

void BinarySignalSet::unlockAllExcept(byte position)
{
    for (byte i = 0; i < position; ++i) {
        unlock(i);
    }
    lock(position);
    for (byte i = position + 1; i < _nrSignals; ++i) {
        unlock(i);
    }
}

void BinarySignalSet::unlockOnly(byte position)
{
    lockAllExcept(position);
}