#ifndef CONTROLLER__H
#define CONTROLLER__H

// Modes
#include "avoidance_mode.h"
#include "funny_move_mode.h"
#include "line_tracking_mode.h"
#include "manual_mode.h"

// Drivers
#include "move_driver.h"
#include "ir_driver.h"
#include "us_driver.h"


class Controller {
public:
  AvoidanceMode m_avoidance_mode;
  FunnyMoveMode m_funny_move_mode;
  LineTrackingMode m_line_tracking_mode;
  ManualMode m_manual_mode;

  MoveDriver m_move_driver;
  IRDriver m_L_ir_driver;
  IRDriver m_R_ir_driver;
  USDriver m_us_driver;

  Controller() : m_avoidance_mode(this), m_funny_move_mode(this), m_line_tracking_mode(this), m_manual_mode(this), m_move_driver(), m_L_ir_driver(4), m_R_ir_driver(5), m_us_driver(0, 0) {
    m_current_mode = &m_line_tracking_mode;
  }

  void run() {
    Mode* next_mode = m_current_mode->run();
    if (next_mode != NULL) {
      m_current_mode = next_mode;
    }
  }

private:
  Mode* m_current_mode;
};

#endif
