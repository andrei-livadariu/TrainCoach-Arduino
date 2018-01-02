#include <train.h>
#include <lightsensor.h>

Train train(8, TrainColor::Red, TrainChannel::One);
LightSensor sensor(A0, 100);

void setup() {
  train.forward(TrainSpeed::Two);
}

void loop() {
  sensor.loop();

  if (sensor.isJustCovered()) {
    train.stop();

    delay(2000);
    train.reverse();
    train.start();
  }

  delay(10);
}
