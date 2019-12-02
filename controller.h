#ifndef CONTROLLER__H
#define CONTROLLER__H

#include "avoidance_mode.h"
#include "funny_move_mode.h"
#include "line_tracking_mode.h"
#include "manual_mode.h"


class Controller {
public:
  AvoidanceMode m_avoidance_mode;
  FunnyMoveMode m_funny_move_mode;
  LineTrackingMode m_line_tracking_mode;
  ManualMode m_manual_mode;

  Controller() : m_avoidance_mode(this), m_funny_move_mode(this), m_line_tracking_mode(this), m_manual_mode(this) {
    
  }
};

#endif
