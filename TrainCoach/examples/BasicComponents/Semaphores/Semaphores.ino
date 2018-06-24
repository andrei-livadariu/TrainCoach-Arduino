#include <Reactduino.h>

#include <TrainCoach.h>
#include <signals\binary\ibinarysignal.h>
#include <signals\binary\binarysignalset.h>
#include <signals\binary\constantsignal.h>
#include <signals\binary\flashingsignal.h>

RedGreenSignal redGreenSignal1(2);
RedGreenSignal redGreenSignal2(3, false, true);
ConstantSignal constantSignal(4);
FlashingSignal flashingSignal(5);

IBinarySignal *signals[4] = {&redGreenSignal1, &redGreenSignal2, &constantSignal, &flashingSignal};
BinarySignalSet signalSet = BinarySignalSet(signals, 4);

void runLights() {
  signalSet.lockOnly(0);
  app.delay(3000, [] {
    signalSet.lockOnly(1);
  });
  app.delay(6000, [] {
    signalSet.lockOnly(2);
  });
  app.delay(9000, [] {
    signalSet.lockOnly(3);
  });

  app.delay(12000, [] {
    signalSet.lockOnly(0);
  });
  app.delay(15000, [] {
    signalSet.lockOnly(1);
  });
  app.delay(18000, [] {
    signalSet.lockOnly(2);
  });
  app.delay(21000, [] {
    signalSet.lockOnly(3);
  });

  app.delay(24000, [] {
      signalSet.lockAllExcept(0);
  });
  app.delay(27000, [] {
      signalSet.lockAllExcept(1);
  });
  app.delay(30000, [] {
      signalSet.lockAllExcept(2);
  });
  app.delay(33000, [] {
      signalSet.lockAllExcept(3);
  });

  app.delay(36000, [] {
      signalSet.lockAllExcept(0);
  });
  app.delay(39000, [] {
      signalSet.lockAllExcept(1);
  });
  app.delay(42000, [] {
      signalSet.lockAllExcept(2);
  });
  app.delay(45000, [] {
      signalSet.lockAllExcept(3);
  });
}

Reactduino app([] {
  app.onTick([] {
    flashingSignal.loop();
  });

  runLights();
  app.repeat(48000, &runLights);
});