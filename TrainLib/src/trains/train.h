#ifndef TRAINLIB_TRAIN_H
#define TRAINLIB_TRAIN_H

#include "motors\imotor.h"

struct TrainInfo
{
    static const TrainInfo blankInfo;

    byte length;
    byte weight;
    byte nrCars;

    TrainInfo()
        : TrainInfo(0, 0, 0)
    {}

    TrainInfo(byte length, byte weight, byte nrCars)
        : length(length), weight(weight), nrCars(nrCars)
    {}
};

class Train
{
    public:
        Train(IMotor &motor);
        Train(TrainInfo &info, IMotor &motor);
        
        IMotor& getMotor();
        const TrainInfo& getInfo();

        void start();
        void stop();
        void reverse();

    private:
        const TrainInfo &_info;
        IMotor &_motor;
};

#endif