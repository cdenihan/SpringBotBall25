#include "../include/variables.h"

/**
 * Defines the default configuration for the wheels and touch sensors.
 * The `wheels` struct contains the default motor ports for each wheel.
 * The `touch` struct contains the default touch sensor IDs.
 * The `servos` struct contains the default servo ports.
 * These ports are correlated with the ports on the Wombat.
 */
struct wheels wheels = {2, 1, 3, 0};
struct touch touch = {0, 1, 2, 3};
struct servos servos = {0, 1, 2, 3};

