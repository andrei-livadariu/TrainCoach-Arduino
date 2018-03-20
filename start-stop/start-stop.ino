#include <Reactduino.h>

#include <TrainLib.h>
#include <trains\train.h>
#include <motors\legoinfraredmotor.h>

LegoInfraRedMotor trainMotor(8, InfraRedColor::Red, InfraRedChannel::One, LegoInfraRedMotor::SpeedOne);
Train train(trainMotor);

Reactduino app([] {
  train.start();
  app.repeat(22000, [] { 
    train.start();
    app.delay(10000, [] {
      train.stop();
    });
    app.delay(11000, [] {
      train.reverse();
      train.start();
    });
    app.delay(21000, [] {
      train.stop();
    });
  });
});