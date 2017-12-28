#ifndef TRAINLIB_TRAIN_H
#define TRAINLIB_TRAIN_H

#include <legopowerfunctions.h>

enum class TrainColor {
    Red = RED,
    Blue = BLUE,
};

enum class TrainChannel {
    One = CH1,
    Two = CH2,
    Three = CH3,
    Four = CH4,
};

enum class TrainSpeed {
    One = PWM_FWD1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven
};

enum class TrainDirection {
    Forward = 1,
    Backward = -1,
};

class Train
{
    public:
        Train(int pin, TrainColor color, TrainChannel channel);
        
        void start(TrainSpeed speed, TrainDirection direction);
        void start(TrainSpeed speed);
        void start();

        void forward(TrainSpeed speed);
        void backward(TrainSpeed speed);
        
        void stop();
        void reverse();

    private:
        LEGOPowerFunctions _motor;
        TrainColor _color;
        TrainChannel _channel;
        TrainSpeed _speed;
        TrainDirection _direction;
};

#endif