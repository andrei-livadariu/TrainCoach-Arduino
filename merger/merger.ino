#include <Reactduino.h>

#include <train.h>
#include <lightsensor.h>
#include <semaphore.h>
#include <merger.h>

Train trainLeft(3, TrainColor::Blue, TrainChannel::One);
Train trainRight(5, TrainColor::Red, TrainChannel::One);

LightSensor sensorLeft(A0, 200);
LightSensor sensorRight(A1, 200);

Semaphore semaphoreLeft(2);
Semaphore semaphoreRight(4);

MergerTrack tracks[2] = {
  {trainLeft, sensorLeft, semaphoreLeft},
  {trainRight, sensorRight, semaphoreRight},
};

Merger merger(tracks, 2);

Reactduino app([] {
  Serial.begin(9600);
  app.onTick([] {
    sensorLeft.loop();
    sensorRight.loop();
    merger.loop();
  });
});
