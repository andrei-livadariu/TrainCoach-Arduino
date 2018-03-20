#include <Reactduino.h>

#include <TrainLib.h>
#include <trains\train.h>
#include <signals\semaphore.h>

Train trainLeft(3, TrainColor::Blue, TrainChannel::One);
Train trainRight(5, TrainColor::Red, TrainChannel::One);

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
