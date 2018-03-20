#include <Reactduino.h>

#include <TrainLib.h>
#include <trains\train.h>
#include <sensors\lightsensor.h>

Train train(8, TrainColor::Red, TrainChannel::One);
LightSensor sensor(A0, 100);

Reactduino app([] {
  train.forward(TrainSpeed::Two);

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