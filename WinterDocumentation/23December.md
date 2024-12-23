# December 23nd (Day 3)

## General Notes

## PID Controller
I have no idea how the in-built KIPR one works, so I'm making my own. Below are the variables that are typically used in a PID controller, but now it is remade so I can understand it. 
```c
typedef struct {
    double kP;    // Proportional gain coefficient
    double kI;    // Integral gain coefficient 
    double kD;    // Derivative gain coefficient
    double previous_error;  // Stores last error for derivative calc
    double integral;   // Running sum of errors for integral calc
} PIDController;
```
The PID values (kP = 0.5, kI = 0.01, kD = 0.1) are starting points based on common PID tuning practices:
 - kP = 0.5: A moderate proportional gain that provides immediate response to errors without being too aggressive
 - kI = 0.01: A small integral gain to slowly eliminate steady-state error without causing oscillation
 - kD = 0.1: A derivative gain that helps dampen oscillations while still allowing quick corrections
```c
void init_pid(PIDController *pid) {
    pid->kP = 0.5;    // Set initial P gain
    pid->kI = 0.01;   // Set initial I gain
    pid->kD = 0.1;    // Set initial D gain
    pid->previous_error = 0;
    pid->integral = 0;
}
```
When using this, the plan is to use a new function I deemed calculatePID (yes, very revolutionary [I'M LOOKING AT YOU JAKEEM, STOP JUDGING MY NAMING SENSE]). 
```c
double calculate_pid(PIDController *pid, double error, double dt) {
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
```

## Main Parts
 - I'M IN SO MUCH PAIN MAN; SEND HELP
