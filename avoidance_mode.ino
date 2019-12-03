#include "controller.h"
#include "funny_move_mode.h"

AvoidanceMode::AvoidanceMode(Controller* controller) : Mode(controller) {
    
    obsDelay=650;
}

Mode* AvoidanceMode::run() {
//  return &m_controller->m_line_tracking_mode;

  
      // Go right
      m_controller->m_move_driver.set_speed(0.5f, -0.5f);
      delay(obsDelay);

      // Go forward
      m_controller->m_move_driver.set_speed(0.5f, 0.0f);
      delay(obsDelay*1.5);


      // Go left
      m_controller->m_move_driver.set_speed(0.5f, 0.5f);
      delay(obsDelay*0.9);

      // Go forward
      m_controller->m_move_driver.set_speed(0.5f, 0.0f);
      delay(obsDelay*1.8);

      // Go left
      m_controller->m_move_driver.set_speed(0.5f, 0.5f);
      delay(obsDelay*0.7);

      // Go forward
      m_controller->m_move_driver.set_speed(0.4f, 0.4f);
      delay(obsDelay);

      // Go right
      m_controller->m_move_driver.set_speed(0.4f, -0.4f);
      delay(obsDelay*0.5);

      m_controller->m_move_driver.set_speed(0.0f, 0.0f);

      return &m_controller->m_manual_mode;
}
