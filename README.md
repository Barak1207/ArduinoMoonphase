# ArduinoMoonphase
I got this idea from moonphase watches.
This repository contains Arduino code for flashing 7 LEDs at random intervals and spinning the moonphase disk.

The moonphase disk consists of two moons.
Earth's moon completes a "rotation" evrey 29.53 days, every 708.12 hours or 2,551,392 seconds.
My stepper motor has 2048 steps in a full rotation, so if we want a full moon to a full moon rotation we need half a rotation of the disk, 1024 steps.

2,551,392 seconds divided by 1024 steps means a step every 2491.59375 seconds, my code steps every 2491.6 seconds because of...reasons.
