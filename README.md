# GNU Radio OOT Module for Signal Processing
This module is developed as part of my preparation for **GSoC 2026**. It contains custom blocks focused on **Signal Theory** and **Electronic Measurements**.

### Implemented Blocks:
- **Amplifier**: A C++ synchronous block that performs linear gain on a float signal.

### Upcoming:
- **RMS Voltmeter**: A decimator block to calculate the RMS value of a signal.

## How to build:
```Bash
mkdir build && cd build
cmake ..
make
sudo make install
