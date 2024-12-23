#include <kipr/wombat.h>
#ifndef MOVEMENT_H
#define MOVEMENT_H

// For any info about the functions in particular, see movement.c

// Manual Movement Functions
void drive(int distance, int degrees, int speed);
void turn(int degrees, int speed);
void translate(int distance, int degrees, int speed);
void frontAlign();
void backAlign();

// Gyroscope Functions


// Accelerometer Functions
void kalman_init(KalmanFilter* filter);
float kalman_update(KalmanFilter* filter, float measurement);

// PID Controller Functions
double calculatePID(PIDController *pid, double error, double dt);
void positionalDrive(int target_speed, int target_distance);

#endif
