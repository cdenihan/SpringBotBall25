#!/bin/bash

./compile.sh
cat run.sh | sshpass -p "botball" ssh -o StrictHostKeyChecking=no kipr@192.168.125.1
