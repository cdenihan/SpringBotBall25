# December 22nd (Day 2)

## General Notes

## Tracking Time
If we use the following code, it is accurate in seconds to $\pm0.001$ seconds, or 1 millisecond. 
```c
int main() {
    double current = seconds();
    msleep(5000);
    double change = seconds() - current;
    printf("fun() took %f seconds to execute \n", change); 
    return 0;
}
```

## Setting up General Coding Headers
This is just a C syntax issue, just makes it possible to use multiple files. Took a bit of handling with the new ssh software, but makes most sense. 

## Accelerometer
So the idea is to get the average accelerometer, but there is a current issue. We are having some struggles making sure the readings are stable at rest, or so it should print 0 for all values. The issue here is that over time, it will have accumulated drift, which most computer systems use an EKF to account for (Extended Kalman Filter). Something that might be useful to study is https://github.com/rlabbe/Kalman-and-Bayesian-Filters-in-Python. 

## Main Parts
 - The time makes it possible to get the general integral of the accelerometer, which should make distances much more accurate. Will be using in conjunction with the built-in motor positions to accurately get the relative position of the robot. Need to scale it up to the second axis, as it is only in a straight line right now. 
