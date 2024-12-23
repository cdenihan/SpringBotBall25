#include <kipr/wombat.h>
#ifndef VARIABLES_H
#define VARIABLES_H

struct wheels {
    int FRONT_LEFT;
    int FRONT_RIGHT;
    int REAR_LEFT;  
    int REAR_RIGHT;
};

struct touch {
    int FRONT_LEFT;
    int FRONT_RIGHT;
    int REAR_LEFT;
    int REAR_RIGHT;
};

struct servos {
    int base;
    int bigClaw;
    int arm;
    int smallClaw;
};

typedef struct {
    double kP;    // Proportional gain coefficient
    double kI;    // Integral gain coefficient 
    double kD;    // Derivative gain coefficient
    double previous_error;  // Stores last error for derivative calc
    double integral;   // Running sum of errors for integral calc
} PIDController;

void startPID(PIDController *pid) {
    pid->kP = 0.5;    // Set initial P gain
    pid->kI = 0.01;   // Set initial I gain
    pid->kD = 0.1;    // Set initial D gain
    pid->previous_error = 0;
    pid->integral = 0;
}

extern struct wheels wheels;
extern struct touch touch;
extern struct servos servos;

#endif
