# Wombat Cross Compilation Instructions

## Prerequisites

- Docker Desktop must be running

## Steps

1. Pull the Wombat cross-compilation Docker image:

```bash
docker pull sillyfreak/wombat-cross
```

2. Clear and prepare the development directory:

```bash
rm -r *
sudo cp -r gyro/* develop/
```

3. Run the cross-compilation:

```bash
docker run -it --rm --volume ./develop:/home/kipr:rw sillyfreak/wombat-cross \
  aarch64-linux-gnu-gcc -Wall main.c i2cHeaders.c movement.c mpu9250.c -lkipr -lm -o main -lz -lpthread
```

## Deployment

1. SSH into the Wombat:

```bash
ssh kipr@192.168.125.1
# Password: botball
```

2. Copy the compiled program to the Wombat:

```bash
scp main kipr@192.168.125.1:/home/kipr/Documents/KISS/test/hmm/bin
```

Note: Run the program from the Wombat using the Spring interface.
