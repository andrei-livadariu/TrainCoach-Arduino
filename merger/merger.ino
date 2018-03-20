#include <Reactduino.h>

#include <TrainLib.h>
#include <trains\train.h>
#include <sensors\lightsensor.h>
#include <signals\semaphore.h>
#include <track\merger.h>
#include <motors\motorcontroller.h>
#include <track\trackswitch.h>

Train passengerTrain(3, TrainColor::Blue, TrainChannel::One);
Train cargoTrain(5, TrainColor::Red, TrainChannel::One);

LightSensor sensorCargo(A0, 200);
LightSensor sensorPassenger(A1, 200);

Checkpoint cargoTrack(sensorCargo, &cargoTrain);
Checkpoint passengerTrack(sensorPassenger, &passengerTrain);

Checkpoint *tracks[2] = {&passengerTrack, &cargoTrack};

Merger merger(tracks, 2, 6000);

MotorController motor(7, 8, 9);
TrackSwitch trackSwitch(motor);

Reactduino app([] {
  passengerTrain.forward(TrainSpeed::Three);
  cargoTrain.forward(TrainSpeed::Four);

  app.onTick([] {
    trackSwitch.loop();
    cargoTrack.loop();
    passengerTrack.loop();
    merger.loop();

    if (merger.isJustAllowing()) {
      Train *train = merger.getLastTrain();
      if (train == &passengerTrain) {
        app.delay(3500, [] {
          trackSwitch.flipTo(0);
        });
      } else if (train == &cargoTrain) {
        app.delay(5000, [] {
          trackSwitch.flipTo(1);
        });
      }
    }
  });
});
