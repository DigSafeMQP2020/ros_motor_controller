#ifndef __MOTOR_DRIVER_H
#define __MOTOR_DRIVER_H

#include "comm.h"

enum COMM_METHOD {COMM_NONE, COMM_RC, COMM_PACKET_SERIAL, COMM_PWM};

#define MAX_POWER 255 // Power to contrain around to prevent drawing too many amps

class MotorDriver
{
protected:
public:
  virtual void SendPowers(int16_t powerA, int16_t powerB) = 0;

public:
  MotorDriver(void) {}

  void Init(void)
  {
    DEBUG_SERIAL.println("MotorDriver::Init");
    FullStop();
    DEBUG_SERIAL.println("/MotorDriver::Init");
  }

  virtual void EmergencyStop(void) 
  {
    FullStop();
  }

  void SetPowers(int16_t powerA, int16_t powerB)
  {
    // DEBUG_SERIAL.print(powerA);
    // DEBUG_SERIAL.print('\t');
    // DEBUG_SERIAL.print(powerB);
    // DEBUG_SERIAL.print('\t');
    powerA = constrain(powerA, -MAX_POWER, MAX_POWER); // Was -255 255
    powerB = constrain(powerB, -MAX_POWER, MAX_POWER); // Was -255 255


    // DEBUG_SERIAL.print(powerA);
    // DEBUG_SERIAL.print('\t');
    // DEBUG_SERIAL.print(powerB);
    // DEBUG_SERIAL.print('\t');

    SendPowers(powerA, powerB);
  }
  
  void FullStop(void)
  {
    SetPowers(0, 0);
  }
};

#endif