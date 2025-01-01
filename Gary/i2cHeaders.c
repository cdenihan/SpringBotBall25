#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>

static int i2c_fd = -1;

void i2c_init() {
    i2c_fd = open("/dev/i2c-1", O_RDWR);
}

int i2c_read8(int address, int reg) {
    unsigned char buf[1];
    ioctl(i2c_fd, I2C_SLAVE, address);
    write(i2c_fd, &reg, 1);
    read(i2c_fd, buf, 1);
    return buf[0];
}

int i2c_write8(int address, int reg, int value) {
    unsigned char buf[2] = {(unsigned char)reg, (unsigned char)value};
    ioctl(i2c_fd, I2C_SLAVE, address);
    return write(i2c_fd, buf, 2);
}
