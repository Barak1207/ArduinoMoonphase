# ArduinoMoonphase
I got this idea from moonphase watches.

This repository contains Arduino code for flashing 7 LEDs at random intervals and spinning the moonphase disk at a rate so it mimics the earth's moon actual rotation as seen from the nothren hemisphere.

The moonphase disk consists of two moons.
Earth's moon completes a "rotation" every 29.53 days, every 708.72 hours or 2,551,392 seconds.
The stepper motor I used has 2048 steps in a full rotation, so if we want a full moon to a full moon rotation we need half a rotation of the disk, 1024 steps.

2,551,392 seconds divided by 1024 steps means a step every 2491.59375 seconds, I rounder up so this code steps every 2491.6 seconds.
