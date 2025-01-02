#!/bin/bash
cd
sudo cp -r SpringBotBall25/Gary2/* develop/
docker run -it --rm --volume ./develop:/home/kipr:rw sillyfreak/wombat-cross  aarch64-linux-gnu-gcc -g -Wall i2c_comm.c imu_filter.c main.c motor_control.c mpu9250.c -lkipr -lm -o botball_user_program -lz -lpthread
cd develop/
sshpass -p "botball" scp botball_user_program kipr@192.168.125.1:/home/kipr/Documents/KISS/test/hmm/bin
sudo cp botball_user_program ../execution
sudo rm -r *
cd ..
echo "Compiled sucessfully!"
