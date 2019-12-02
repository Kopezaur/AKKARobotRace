#ifndef MOVE_DRIVER__H
#define MOVE_DRIVER__H

#include "motor_driver.h"


class MoveDriver {
public:
  MoveDriver() : m_m0_driver(0, 0, 0), m_m1_driver(0, 0, 0), m_m2_driver(0, 0, 0), m_m3_driver(0, 0, 0) {
    
  }

  void set_speed(float linear, float rotation) {
    // Inverse kinematics here.
    
    m_m0_driver.set_speed(0.0f);
    m_m1_driver.set_speed(0.0f);
    m_m2_driver.set_speed(0.0f);
    m_m3_driver.set_speed(0.0f);
  }

private:
  MotorDriver m_m0_driver;
  MotorDriver m_m1_driver;
  MotorDriver m_m2_driver;
  MotorDriver m_m3_driver;
};

#endif
