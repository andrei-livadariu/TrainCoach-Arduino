#ifndef TRAINLIB_CHECKPOINT_H
#define TRAINLIB_CHECKPOINT_H

#include <Arduino.h>

#include "sensors\lightsensor.h"
#include "trains\train.h"

class Checkpoint
{
    public:
        Checkpoint(LightSensor &sensor, Train *train);
        
        Train* getTrain();
        void setTrain(Train *train);

        void loop();
        
        bool isSleeping();
        void sleep();
        void sleep(unsigned long time);
        void wake();

        bool isTrainPresent();
        bool hasJustArrived();
        bool hasJustLeft();
        bool hasJustChanged();

    private:
        LightSensor &_sensor;
        Train *_train;

        unsigned long _sleepTimeout = 0;

        void _updateTrain();
};

#endif