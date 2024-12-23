#include <kipr/wombat.h>
#include "../include/variables.h"
#include "../include/movement.h"

void transRight() {
    mav(wheels.FRONT_LEFT, 1000);
    mav(wheels.FRONT_RIGHT, 1000);
    mav(wheels.REAR_LEFT, -1000);
    mav(wheels.REAR_RIGHT, -1000);
    msleep(500);
    ao();
}

void transLeft() {
    mav(wheels.FRONT_LEFT, -1000);
    mav(wheels.FRONT_RIGHT, -1000);
    mav(wheels.REAR_LEFT, 1000);
    mav(wheels.REAR_RIGHT, 1000);
    msleep(500);
    ao();
}

void transForward() {

}
