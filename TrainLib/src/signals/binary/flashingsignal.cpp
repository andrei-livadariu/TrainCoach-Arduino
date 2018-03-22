#include "flashingsignal.h"

FlashingSignal::FlashingSignal(byte pin)
    : FlashingSignal(pin, FlashingSignal::DefaultFlashSpeed, false)
{}

FlashingSignal::FlashingSignal(byte pin, unsigned long flashSpeed)
    : FlashingSignal(pin, flashSpeed, false)
{}

FlashingSignal::FlashingSignal(byte pin, unsigned long flashSpeed, bool locked)
    : _pin(pin), _flashSpeed(flashSpeed), _locked(locked)
{
    pinMode(_pin, OUTPUT);
    refresh();
}

void FlashingSignal::loop()
{
    if (!_locked) {
        return;
    }

    if (_flipTimeout && _flipTimeout < millis()) {
        _visiblyLocked = !_visiblyLocked;
        _flipTimeout = millis() + _flashSpeed;
        refresh();
    }
}

bool FlashingSignal::getLock()
{
    return _locked;
}

void FlashingSignal::setLock(bool lock)
{
    if (_locked == lock) {
        return;
    }
    
    _locked = lock;
    if (_locked) {
        _visiblyLocked = _locked;
        _flipTimeout = millis() + _flashSpeed;
    }

    refresh();
}

void FlashingSignal::refresh()
{
    digitalWrite(_pin, _locked && _visiblyLocked ? HIGH : LOW);
}