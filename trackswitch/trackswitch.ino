#include <Reactduino.h>
#include <motorcontroller.h>
#include <trackswitch.h>

MotorController motor(7, 8, 9);
TrackSwitch trackSwitch(motor);

Reactduino app([] {
  app.onTick([] {
    trackSwitch.loop();
  });

  app.repeat(3000, [] { 
    trackSwitch.flip();
  });
});