#include <Reactduino.h>

#include <train.h>

Train train(8, TrainColor::Red, TrainChannel::One);

Reactduino app([] {
  train.forward(TrainSpeed::One);
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