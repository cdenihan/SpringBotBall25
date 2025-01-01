#ifndef MPU9250_H
#define MPU9250_H

#include <stdint.h>

#define MPU9250_ADDR 0x68
#define MAG_ADDR 0x0C

typedef struct {
    float accel[3];  // x, y, z acceleration in g
    float gyro[3];   // x, y, z angular velocity in degrees/s
    float mag[3];    // x, y, z magnetic field in µT
} mpu9250_data_t;

void mpu9250_init(void);
void mpu9250_calibrate(void);
void mpu9250_read_raw(mpu9250_data_t *data);
void mpu9250_read_data(mpu9250_data_t *data);

#endif
