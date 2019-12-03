#include "controller.h"
#include "manual_mode.h"

ManualMode::ManualMode(Controller* controller) : Mode(controller) {
    
}

Mode* ManualMode::run() {
  while(m_controller->m_blutooth.available()) {
    char data = m_controller->m_blutooth.read();

    switch (data) {
      case '2': // Forward
        m_controller->m_move_driver.set_speed(0.44f, 0.0f);
        break;
      case '8': // Backwards
        m_controller->m_move_driver.set_speed(-0.44f, 0.0f);
        break;
      case '4': // Left
        m_controller->m_move_driver.set_speed(0.44f, 0.35f);
        break;
      case '6': // Right
        m_controller->m_move_driver.set_speed(0.44f, -0.35f);
        break;
      case '5': // Stop
        m_controller->m_move_driver.set_speed(0.0f, 0.0f);
        break;
      case '1': // Mode
        m_controller->m_move_driver.set_speed(0.0f, 0.0f);
        return &m_controller->m_line_tracking_mode;
    }

    //m_controller->m_blutooth.println("hodor");
    
  }
  return NULL;
}
