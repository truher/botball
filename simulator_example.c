/*

For the botballacademy.org simulator.

Demobot configuration:

sensors (see src/sensors/mappings.ts)
  a0 = arm sensor (note idealness setting)
  a1 = ir sensor (looks downward)
  d0 = front touch
  d1 = back left touch
  d2 = back right touch

motors (see src/Sim.tsx)
  0 = left
  1 = X
  2 = X
  3 = right

servos (see src/Sim.tsx, has angle math)
  0 = arm
  1 = X
  2 = X
  3 = claw
*/

/* this picks up the can.  remember to reset
  the positions of the bot and the can. */

#include <stdio.h>
#include <kipr/wombat.h>

int main() {
  enable_servos();

  printf("Hello, World!\n");

  // exercise the arm, leave it down

  set_servo_position (0, 825); // arm vertical
  msleep (1000);
  set_servo_position (0, 1855); // arm horizontal
  msleep (1000);

  // exercise the claw, leave it open.
  set_servo_position(3, 400);  // claw 135 degrees open
  msleep(1000);
  set_servo_position(3, 2047);  // claw fully closed
  msleep(1000); 
  set_servo_position(3, 1025);  // claw 90 degrees open
  msleep(1000); 

  // drive slowly
  motor(0, 25);
  motor(3, 25);

  // look at sensor outputs for awhile
  for (int i = 0; i < 30; ++i) {
    int ir = analog(1);
    int front = digital(0);
    int et = analog(0);
    printf("%d %d %d %d\n", i, ir, front, et);
    msleep(100);
  }

  // done with motors
  alloff();

  // pick up the can
  set_servo_position(3, 2047);  // claw fully closed
  msleep(1000); 
  set_servo_position (0, 825); // arm vertical
  msleep (1000);

  // throw the can, two motions together
  set_servo_position (0, 1855); // arm horizontal
  set_servo_position(3, 1025);  // claw 90 degrees open
  msleep(1000); 

  // done with servos
  disable_servos (); 
  return 0;
}
