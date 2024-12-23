#include "../include/library.h"

/**Info on the drive function
 * Drives the robot based on the provided distance, angle, and speed.
 * 
 * This function calculates the forward and strafe components based on the
 * provided angle, then uses those to determine the individual wheel speeds.
 * The wheel speeds are then applied to the motors to drive the robot.
 *
 * @param distance The distance to drive, in some unit.
 * @param degrees The angle to drive at, in degrees.
 * @param speed The speed to drive at, in some unit per second.
 */
void drive(int distance, int degrees, int speed) {

    // Converts needed angle to radians
    double angle_rad = degrees / 180.0 * 3.14159;

    // Calculate forward and strafe components
    int forward = (int)(speed * cos(angle_rad));
    int strafe = (int)(speed * sin(angle_rad));
    
    // Calculate wheel speeds
    int fl_speed = forward + strafe;
    int fr_speed = forward - strafe;
    int bl_speed = forward - strafe;
    int br_speed = forward + strafe;

    // Apply speeds to motors
    motor(wheels.FRONT_LEFT, fl_speed);
    motor(wheels.FRONT_RIGHT, fr_speed);
    motor(wheels.REAR_LEFT, bl_speed);
    motor(wheels.REAR_RIGHT, br_speed);

}

/** Info on the turn function
 * 
 */
void turn(int degrees, int speed) {
    double current_angle = 0.0;
    int bias = gyro_calibrate();
    
    while (abs(current_angle) < abs(degrees)) {
        current_angle += (gyro_z() - bias) * 0.01;
        int turn_speed = (degrees > 0) ? speed : -speed;
        
        motor(wheels.FRONT_LEFT, turn_speed);
        motor(wheels.FRONT_RIGHT, -turn_speed);
        motor(wheels.REAR_LEFT, turn_speed);
        motor(wheels.REAR_RIGHT, -turn_speed);
        
        msleep(10);
    }
    ao();
}

/** Info on the translate function
 * 
 */
void translate(int distance, int degrees, int speed) {
    double angle_rad = degrees / 180.0 * 3.14159;
    int rotation_speed = 200;
    
    // Get initial positions
    for (int port = 0; port < 4; port++) {
        clear_motor_position_counter(port);
    }
    int start_time = seconds();
    int last_time = start_time;
    
    while (1) {
        int current_time = seconds();
        
        // Calculate current movement components
        int forward = (int)(speed * cos(angle_rad));
        int strafe = (int)(speed * sin(angle_rad));
        
        // Calculate wheel speeds for this frame
        int fl_speed = forward + strafe + rotation_speed;
        int fr_speed = forward - strafe - rotation_speed;
        int bl_speed = forward - strafe + rotation_speed;
        int br_speed = forward + strafe - rotation_speed;
        
        // Apply updated speeds 
        motor(wheels.FRONT_LEFT, fl_speed);
        motor(wheels.FRONT_RIGHT, fr_speed);
        motor(wheels.REAR_LEFT, bl_speed);
        motor(wheels.REAR_RIGHT, br_speed);
        
        // Update timing
        last_time = current_time;
        msleep(10);
        
        // Check if we've reached target di stance
        // NEED TO FIX ERROR PLEASE HELP MEEEEEEEEEEE
        if (1) {
            break;
        }
    }
    
    ao();
}

void frontAlign() {
    for (int port = 0; port < 4; port++) {
        fd(port);
    }
    while ((digital(touch.FRONT_LEFT) == 0) || (digital(touch.FRONT_RIGHT) == 0)) {
        
        if (digital(touch.FRONT_LEFT) == 1) {
            motor(wheels.FRONT_LEFT, -500);
            motor(wheels.REAR_LEFT, -500);
        }
        else if (digital(touch.FRONT_RIGHT) == 1) {
            motor(wheels.FRONT_RIGHT, -500);
            motor(wheels.REAR_RIGHT, -500);
        }
        else {
            for (int port = 0; port < 4; port++) {
                fd(port);
            }
        }
        
        
        motor(wheels.FRONT_LEFT, 500);
        motor(wheels.FRONT_RIGHT, 500);
    }
}

void frontAlign() {
    for (int port = 0; port < 4; port++) {
        bk(port);
    }
    while ((digital(touch.FRONT_LEFT) == 0) || (digital(touch.FRONT_RIGHT) == 0)) {
        
        if (digital(touch.FRONT_LEFT) == 1) {
            motor(wheels.FRONT_LEFT, 500);
            motor(wheels.REAR_LEFT, 500);
        }
        else if (digital(touch.FRONT_RIGHT) == 1) {
            motor(wheels.FRONT_RIGHT, 500);
            motor(wheels.REAR_RIGHT, 500);
        }
        else {
            for (int port = 0; port < 4; port++) {
                bk(port);
            }
        }
        
        
        motor(wheels.FRONT_LEFT, 500);
        motor(wheels.FRONT_RIGHT, 500);
    }
}

double calculatePID(PIDController *pid, double error, double dt) {
    // P term: immediate response proportional to error
    double p_term = pid->kP * error;  // 0.5 * error gives moderate correction
    
    // I term: accumulates error over time
    pid->integral += error * dt;
    double i_term = pid->kI * pid->integral;  // 0.01 * accumulated error fixes small persistent errors
    
    // D term: responds to rate of change
    double derivative = (error - pid->previous_error) / dt;
    double d_term = pid->kD * derivative;  // 0.1 * rate of change smooths corrections
    
    pid->previous_error = error;
    
    // Combined correction applied to motors
    return p_term + i_term + d_term;
}

// Function for calibration and testing
void positionalDrive(int targetSpeed, int targetDistance) {
    PIDController pid;
    startPID(&pid);
    
    // Clear initial positions
    for (int port = 0; port <= 3; port++) {
        clear_motor_position_counter(port);
    }
    
    while (1) {
        // Get current positions
        int leftVal = (get_motor_position_counter(0)+ get_motor_position_counter(1))/2;
        int rightVal = (get_motor_position_counter(2) + get_motor_position_counter(3))/2;
        
        // Calculate position error between wheels
        double error = leftVal - rightVal;
        
        // Get PID correction
        double correction = calculatePID(&pid, error, 0.01);
        
        // Apply speeds with correction
        motor(wheels.FRONT_LEFT, targetSpeed + correction);
        motor(wheels.FRONT_RIGHT, targetSpeed - correction);
        motor(wheels.REAR_LEFT, targetSpeed + correction);
        motor(wheels.REAR_RIGHT, targetSpeed - correction);
        
        // Check if we've reached target distance
        if ((leftVal + rightVal)/2 >= targetDistance) {
            break;
        }
        
        msleep(10);
    }
    
    ao();
};

void kalman_init(KalmanFilter* filter) {
    filter->q = 0.5;     // Process noise
    filter->r = 0.5;       // Measurement noise
    filter->x = 0;         // Initial estimate
    filter->p = 1.0;       // Initial error estimate
    filter->k = 0.0;       // Initial Kalman gain
}

float kalman_update(KalmanFilter* filter, float measurement) {
    // Prediction update
    filter->p = filter->p + filter->q;

    // Measurement update
    filter->k = filter->p / (filter->p + filter->r);
    filter->x = filter->x + filter->k * (measurement - filter->x);
    filter->p = (1 - filter->k) * filter->p;

    return filter->x;
}
