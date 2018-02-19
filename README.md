# Adducci
A Loadable High Resolution Timer Kernel Module

## Getting Started
Adducci is a simple, loadable, high resolution timer kernel module. It requires a task to be added inside the timerCallback function, and the TIMER_PERIOD_MS to be configured in order to do anything functional.

### Prerequisites
In order to compile the kernel module, you must have the appropriate kernel headers installed prior to running make. This can be done by running
```
sudo apt-get install linux-headers<uname-r>
```

### Compiling
Compile Adducci by running
```
make
```

Clean Adducci by running
```
make clean
```

### Loading/Unloading
Load Adducci:
```
sudo make load
```
Unload Adducci:
```
sudo make unload
```
