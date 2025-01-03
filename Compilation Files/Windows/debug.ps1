# Run compilation script
./compile.ps1

# Start gdbserver on the remote machine
ssh -o StrictHostKeyChecking=no kipr@192.168.125.1 "gdbserver --multi 192.168.125.1:5555"

# Prepare GDB commands
$gdbCommands = @"
target extended-remote 192.168.125.1:5555
set remote exec-file /home/kipr/Documents/KISS/test/hmm/bin/botball_user_program
file $env:USERPROFILE/execution/botball_user_program
start
"@

# Launch gdb-multiarch with commands
$gdbCommands | gdb-multiarch