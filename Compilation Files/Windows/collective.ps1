# Run compilation script first
./compile.ps1

# Change to the parent directory
Set-Location -Path ".."

Set-Location SpringBotBall25/"Compilation Files"

# Change to the script directory
Set-Location $PSScriptRoot

# Execute the run commands directly on the remote system
ssh -o StrictHostKeyChecking=no kipr@192.168.125.1 "cd Documents/KISS/test/hmm/bin && ./botball_user_program"
