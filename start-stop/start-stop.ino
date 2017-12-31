#include <train.h>

Train train(8, TrainColor::Red, TrainChannel::One);

void setup() {}

void loop() {
  train.forward(TrainSpeed::One);
  delay(10000);
  
  train.stop();
  delay(1000);
  
  train.reverse();
  train.start();
  delay(10000);

  train.stop();
  delay(1000);
}
