#include <Reactduino.h>
#include <motorcontroller.h>

MotorController motor(8, 7, 9);

Reactduino app([] {
  app.repeat(8000, [] {
    motor.forward();

    app.delay(2000, [] {
      motor.stop();
    });

    app.delay(4000, [] {
      motor.backward();
    });

    app.delay(6000, [] {
      motor.stop();
    });
  });
});