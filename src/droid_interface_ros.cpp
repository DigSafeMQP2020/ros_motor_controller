/*
 * Main program for ROS-driven Droid UGV
 * Serves as the interface between ROS nodes on the main board and motor drivers, etc.
 */

#include <Arduino.h>
#include "ros_ugv.h"

ROSUGV robot;
int16_t left = 500;
int16_t right = 500;

//N.B.: No need to start ROS serial manually, as the constructors take care of that for us
void setup()
{
  DEBUG_SERIAL.begin(115200);
  // while(!DEBUG_SERIAL)
  // {
  //   delay(100);
  // }

  DEBUG_SERIAL.println("setup");

  robot.Init();

  DEBUG_SERIAL.println("/setup");
}

void loop(void)
{
  robot.MainLoop();
  // if(CheckDebugSerial())
  if (true)
  {
    // all in m/s, rad/s
    //  float left = debugString.toFloat();
    //  uint8_t comma = debugString.indexOf(',');
    //  float right = debugString.substring(comma+1).toFloat();

    //  DEBUG_SERIAL.print("Setting left = ");
    //  DEBUG_SERIAL.println(left);
    //  DEBUG_SERIAL.print("Setting right = ");
    //  DEBUG_SERIAL.println(right);
    if (millis() % 4000 > 2000)
    {
      right = 500;
      left = 500;
    }
    else
    {
      left = -500;
      right = -500;
    }

    robot.SetTargetPositions(left, right);

    //  debugString = "";
  }
}
