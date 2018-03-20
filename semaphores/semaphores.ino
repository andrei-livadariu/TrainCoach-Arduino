#include <Reactduino.h>

#include <TrainLib.h>
#include <trains\train.h>
#include <motors\legoinfraredmotor.h>
#include <signals\semaphore.h>

LegoInfraRedMotor trainLeftMotor(3, InfraRedColor::Blue, InfraRedChannel::One);
Train trainLeft(trainLeftMotor);

LegoInfraRedMotor trainRightMotor(5, InfraRedColor::Red, InfraRedChannel::One);
Train trainRight(trainRightMotor);

Semaphore semaphoreLeft(2);
Semaphore semaphoreRight(4);

Reactduino app([] {
  semaphoreLeft.unlock();
  semaphoreRight.lock();

  app.repeat(6000, [] {
    semaphoreLeft.lock();
    trainLeft.stop();
    semaphoreRight.unlock();
    trainRight.start();
    app.delay(3000, [] {
      semaphoreRight.lock();
      trainRight.stop();
      semaphoreLeft.unlock();
      trainLeft.start();
    });
  });
});
