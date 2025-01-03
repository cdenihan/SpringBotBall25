#!/bin/bash

./compile.sh
sshpass -p "botball" ssh -o StrictHostKeyChecking=no kipr@192.168.125.1 "echo gdbserver --multi 192.168.125.1:5555"
gdb-multiarch
expect "--Type <RET> for more, q to quit, c to continue without paging--"
send "y"
target extended-remote 192.168.125.1:5555
set remote exec-file /home/kipr/Documents/KISS/test/hmm/bin/botball_user_program
file /home/aubrey/execution/botball_user_program
start

exit 0