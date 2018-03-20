#include <Reactduino.h>

#include <TrainLib.h>
#include <motors\motorcontroller.h>
#include <sensors\lightsensor.h>
#include <track\trackswitch.h>
#include <track\checkpoint.h>

LightSensor lightSensor(A0, 200);
MotorController motor(7, 8, 9);
TrackSwitch trackSwitch(motor);
byte ledPin = 2;

Reactduino app([] {
  app.onTick([] {
    lightSensor.loop();
    trackSwitch.loop();

    if (lightSensor.isJustCovered() && !trackSwitch.isSwitching()) {
      trackSwitch.flip();
      lightSensor.sleep(4000);
    }

    if (lightSensor.isCovered()) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  });
});
