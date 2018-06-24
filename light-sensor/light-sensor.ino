#include <Reactduino.h>

#include <TrainCoach.h>
#include <trains\train.h>
#include <motors\legoinfraredmotor.h>
#include <sensors\lightsensor.h>

LegoInfraRedMotor trainMotor(8, InfraRedColor::Red, InfraRedChannel::One, LegoInfraRedMotor::SpeedTwo);
Train train(trainMotor);
LightSensor sensor(A0, 100);

Reactduino app([] {
  train.start();

  app.onTick([] {
    sensor.loop();

    if (sensor.isJustCovered()) {
      train.stop();

      app.delay(2000, [] {
        train.reverse();
        train.start();
      });
    }
  });
});