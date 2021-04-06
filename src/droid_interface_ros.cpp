/*
 * Main program for ROS-driven Droid UGV
 * Serves as the interface between ROS nodes on the main board and motor drivers, etc.
 */

#include <Arduino.h>
#include "ros_ugv.h"

ROSUGV robot;
int16_t left = 500;
int16_t right = 500;
int item = 0;
int16_t points[19][2] = {//{0, 0},
                         {1951, -1491},
                         {1929, -1613},
                         {1400, -1633},
                         {522, -1514},
                         {359, -1091},
                         {99, -704},
                         {0, -574},
                         {-272, -136},
                         {-536, 343},
                        //  {-534, 473},
                         {-457, 515},
                        //  {-457, 436},
                         {-118, 224},
                         {907, -749},
                         {1316, -1108},
                         {1595, -1372},
                         {1797, -1523}
                         //{0, 0}
                         };
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
    if (millis() % 850 == 0)
    {
      delay(2);
      item++;
      // DEBUG_SERIAL.println(item);
      // DEBUG_SERIAL.println(points[item][0]);
      if (item > 18)
      {
        item = 0;
      }
    }

    robot.SetTargetPositions(points[item][0], points[item][1]);

    //  debugString = "";
  }
}
