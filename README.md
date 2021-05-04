# ros_motor_controller
 
Install `PlatformIO` from VSCode extensions if using VSCode. This allows for code upload and serial monitor if needed.

## To run:

### Prereqs:
Install rosserial
`sudo apt-get install ros-melodic-rosserial`

ensure user belongs to dialout group
`sudo adduser $(whoami) dialout`

Install prof lewin `linalg-micro` repo as library
`https://github.com/gcl8a/linalg-micro`


Change `&Serial` in `.pio/libdeps/sparkfun_samd21_mini_usb/Rosserial Arduino Library/src/ArduinoHardware.h` to `&SERIAL_PORT_MONITOR`

### Instructions and things

Plug in board, hit reset.

To run use 

`rosrun rosserial_python serial_node.py /dev/ttyACM0`
If this errors, run `ls -al /dev/ttyACM*` to try to find the port.

To goto a position
`rostopic pub /motor_targets std_msgs/UInt32 "data: 0"`

To read position
`rostopic echo /motor_positions`

## ROS Topics

- `/cmd_mode`
- `/motor_targets` To write, type uint32
- `/motor_positions` to read, type uint32
