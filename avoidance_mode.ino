#include "controller.h"
#include "funny_move_mode.h"

AvoidanceMode::AvoidanceMode(Controller* controller) : Mode(controller) {
    
}

Mode* AvoidanceMode::run() {
  return &m_controller->m_line_tracking_mode;
}
