#!/bin/bash
sudo cp -r project/* develop/
docker run -it --rm --volume ./develop:/home/kipr:rw sillyfreak/wombat-cross  aarch64-linux-gnu-gcc -Wall i2c_comm.c imu_filter.c main.c motor_control.c mpu9250.c -lkipr -lm -o botball_user_program -lz -lpthread
cd develop/
sshpass -p "botball" scp main kipr@192.168.125.1:/home/kipr/Documents/KISS/test/hmm/bin
sudo rm -r *
cd ..
echo "Compiled sucessfully!"
