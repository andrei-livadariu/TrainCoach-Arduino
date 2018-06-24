#include "constantsignal.h"

ConstantSignal::ConstantSignal(byte pin)
    : ConstantSignal(pin, false, false)
{}

ConstantSignal::ConstantSignal(byte pin, bool locked)
    : ConstantSignal(pin, locked, false)
{}

ConstantSignal::ConstantSignal(byte pin, bool locked, bool reverse)
    : _pin(pin), _locked(locked), _reverse(reverse)
{
    pinMode(_pin, OUTPUT);
    refresh();
}

bool ConstantSignal::getLock()
{
    return _locked;
}

void ConstantSignal::setLock(bool lock)
{
    if (_locked == lock) {
        return;
    }

    _locked = lock;
    refresh();
}

void ConstantSignal::refresh()
{
    digitalWrite(_pin, _locked == _reverse ? LOW : HIGH);
}