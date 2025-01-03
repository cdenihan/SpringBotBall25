#!/bin/bash

./compile.sh
cd SpringBotBall25/"Compilation Files"
cat run.sh | sshpass -p "botball" ssh -o StrictHostKeyChecking=no kipr@192.168.125.1

exit 0