#include "trackswitch.h"

TrackSwitch::TrackSwitch(IMotor &motor)
    : TrackSwitch(motor, false, TrackSwitch::DefaultNrTracks, TrackSwitch::DefaultRunningTime)
{}

TrackSwitch::TrackSwitch(IMotor &motor, bool mirrored)
    : TrackSwitch(motor, mirrored, TrackSwitch::DefaultNrTracks, TrackSwitch::DefaultRunningTime)
{}

TrackSwitch::TrackSwitch(IMotor &motor, bool mirrored, byte nrTracks)
    : TrackSwitch(motor, mirrored, nrTracks, TrackSwitch::DefaultRunningTime)
{}

TrackSwitch::TrackSwitch(IMotor &motor, bool mirrored, byte nrTracks, unsigned long runningTime)
    : _motor(motor), _nrTracks(nrTracks), _runningTimer(runningTime),
    _motorDirection(mirrored ? MotorDirection::Backward : MotorDirection::Forward)
{
    _reset();
}

byte TrackSwitch::getNrTracks()
{
    return _nrTracks;
}

unsigned long TrackSwitch::getRunningTime()
{
    return _runningTimer.getDuration();
}

byte TrackSwitch::getCurrentTrack()
{
    return _currentTrack;
}

void TrackSwitch::setCurrentTrack(byte track)
{
    flipTo(track);
}

bool TrackSwitch::isSwitching()
{
    return _motor.isRunning();
}

bool TrackSwitch::isMirrored()
{
    return _motorDirection == MotorDirection::Backward;
}

void TrackSwitch::loop()
{   
    if (_runningTimer.isDone()) {
        _motor.stop();
        _runningTimer.reset();
    }
}

void TrackSwitch::flip()
{
    flipTo((_currentTrack + 1) % _nrTracks);
}

void TrackSwitch::flipTo(byte track)
{
    if (track == _currentTrack) {
        return;
    }

    char delta = (char) track - (char) _currentTrack;

    _currentTrack = track;
    _run(abs(delta), delta > 0 ? MotorDirection::Forward : MotorDirection::Backward);
}

void TrackSwitch::_reset()
{
    _run(_nrTracks - 1, MotorDirection::Backward);
}

void TrackSwitch::_run(byte ticks, MotorDirection direction)
{
    _runningTimer.tick(ticks);
    _motor.start(static_cast<MotorDirection>((char) _motorDirection * (char) direction));
}
