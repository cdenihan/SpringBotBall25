# Error handling preference
$ErrorActionPreference = "Stop"

try {
    # Store original location and create paths
    $originalLocation = Get-Location
    $projectRoot = (Get-Item $PSScriptRoot).Parent.Parent.Parent.FullName
    $developPath = Join-Path $projectRoot "develop"
    $garyPath = Join-Path $projectRoot "SpringBotBall25\Gary2"
    $executionPath = Join-Path $projectRoot "execution"

    # Ensure develop directory exists
    if (-not (Test-Path $developPath)) {
        New-Item -ItemType Directory -Path $developPath | Out-Null
    }

    # Copy Gary2 files to develop
    Write-Host "Copying project files..." -ForegroundColor Cyan
    Copy-Item -Path "$garyPath\*" -Destination $developPath -Recurse -Force

    # Pull and run Docker container
    Write-Host "Starting Docker compilation..." -ForegroundColor Cyan
    docker pull sillyfreak/wombat-cross
    docker run -it --rm --volume ${developPath}:/home/kipr:rw sillyfreak/wombat-cross `
        aarch64-linux-gnu-gcc -g -Wall i2c_comm.c imu_filter.c main.c motor_control.c mpu9250.c `
        -lkipr -lm -o botball_user_program -lz -lpthread

    # Copy compiled program
    Write-Host "Copying compiled program..." -ForegroundColor Cyan
    ssh-keygen -R 192.168.125.1 2>$null
    $env:SSHPASS = "botball"
    sshpass -e scp "$developPath\botball_user_program" "kipr@192.168.125.1:/home/kipr/Documents/KISS/test/hmm/bin"

    # Backup compiled program
    if (-not (Test-Path $executionPath)) {
        New-Item -ItemType Directory -Path $executionPath | Out-Null
    }
    Copy-Item -Path "$developPath\botball_user_program" -Destination $executionPath -Force

    # Cleanup
    Remove-Item -Path "$developPath\*" -Recurse -Force

    Write-Host "Compilation completed successfully!" -ForegroundColor Green
}
catch {
    Write-Host "Error: $($_.Exception.Message)" -ForegroundColor Red
    exit 1
}
finally {
    # Return to original location
    Set-Location $originalLocation
}
