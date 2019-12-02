#include "controller.h"
#include "manual_mode.h"

ManualMode::ManualMode(Controller* controller) : Mode(controller) {
    
}

Mode* ManualMode::run() {
  while(m_controller->m_blutooth.available()) {
    char data = m_controller->m_blutooth.read();

    switch (data) {
      case '2':
        m_controller->m_move_driver.set_speed(0.5f, 0.0f);
        break;
      case '8':
        m_controller->m_move_driver.set_speed(-0.5f, 0.0f);
        break;
      case '4':
        m_controller->m_move_driver.set_speed(0.5f, 0.5f);
        break;
      case '6':
        m_controller->m_move_driver.set_speed(0.5f, -0.5f);
        break;
      case '5':
        m_controller->m_move_driver.set_speed(0.0f, 0.0f);
        break;
    }

    m_controller->m_blutooth.println("hodor");
    
  }
  return NULL;
}
