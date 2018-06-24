#ifndef TRAINLIB_TRACKSWITCH_H
#define TRAINLIB_TRACKSWITCH_H

#include "motors\imotor.h"
#include "utilities\timer.h"

class TrackSwitch
{
    public:
        TrackSwitch(IMotor &motor);
        TrackSwitch(IMotor &motor, bool mirrored);
        TrackSwitch(IMotor &motor, bool mirrored, byte nrTracks);
        TrackSwitch(IMotor &motor, bool mirrored, byte nrTracks, unsigned long runningTime);

        byte getNrTracks();
        unsigned long getRunningTime();
        byte getCurrentTrack();
        void setCurrentTrack(byte track);
        bool isSwitching();
        bool isMirrored();

        void loop();

        void flip();
        void flipTo(byte track);

    private:
        static const byte DefaultNrTracks = 2;
        static const unsigned long DefaultRunningTime = 250;

        Timer _runningTimer;

        IMotor &_motor;
        const MotorDirection _motorDirection;

        const byte _nrTracks;
        byte _currentTrack = 0;

        void _reset();
        void _run(byte ticks, MotorDirection direction);
};

#endif