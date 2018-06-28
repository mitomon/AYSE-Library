# AYSE-Library
Library for the Autonomous Yard Scooping Entity 

Inspiration: 
Going outside to do chores like cleaning up after and feeding my dogs, raking leaves, and getting rid of fireant mounds that attack my smaller dogs is not only inconvenient and annoying in the hot Texas summer, but dangerous as well. Working outside for extended periods of time can cause sunburns and even heat strokes. I don't expect my 100 degree weather to get any better soon, so I came up with AYSE. Short for Autonomous Yard Scooping Entity, the robot features:
Four Wheels
Arduino Uno with Motor Shield and Particle Photon
Double-Jointed Arms
Strong Reused Aluminum Scoop
Magnetic Odometer Sensor Setup (built with Infineon 3D 2Go Magnetic Sensor)
Single Command setting in the works
Custom Library
Scalability for different robot sizes
With robotics and autonomy increasingly being introduced to the consumer, this is an ideal solution to a problem many people experience.

Demo Video: https://www.youtube.com/watch?v=nHE4Vpv-4BY

Find instructions for this setup here: https://www.hackster.io/RealMitomon/autonomous-yard-scooping-entity-39b9c4
I'll make a header file in a few days, got a bunch on my plate right now but...

Dependencies:
Arduino Servo library
Arduino Wire library for I2C
Magnetic Odometer Sensor Setup (https://www.hackster.io/RealMitomon/magnetic-odometer-sensor-setup-708962)

<h2>Functions:</h2>

void setArmPos(int armPos) - takes an angle input (0-180) as an integer and moves both of the arm servos to that position

void setScoopPos(int scoopPos) - takes a PWM input(0-180) as an integer and moves one of the scoop servos to that position
and moves the other scoop servo to an angle supplementary from that one(180- the angle you input originally).

void brake() - activates brakes for both motors

void moveA(boolean direction, int speed) - moves AYSE forward if input direction is false and backwards if true at the
set speed(1 for 25%,2 for 50%,3 for 75%, or 4for 100%) percentage. Check your battery voltage before setting to max as
their is no built-in safety and your motors may become damaged.

void turn(boolean direction, int speed) - turns AYSE left if input direction is false and right if true at the
set speed(1 for 25%,2 for 50%,3 for 75%, or 4for 100%) percentage. Check your battery voltage before setting to max as
their is no built-in safety and your motors may become damaged.

<h2>In Progress:</h2>

Stable autonomous build. Currently, I can set autonomous mode by pressing the Left and right buttons at the same time. 
This records the MOSS's current position and when the L and R buttons are pressed again saves the end position. AYSE will
move this set distance and execute any commands made when the Autonomous Mode button is pressed. I've decided to remove it 
from the public version as it remains a bit glitchy.
