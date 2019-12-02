#ifndef CONTROLLER__H
#define CONTROLLER__H

#include <SoftwareSerial.h>

// Modes
#include "avoidance_mode.h"
#include "funny_move_mode.h"
#include "line_tracking_mode.h"
#include "manual_mode.h"

// Drivers
#include "bt_driver.h"
#include "move_driver.h"
#include "ir_driver.h"
#include "us_driver.h"


class Controller {
public:
  AvoidanceMode m_avoidance_mode;
  FunnyMoveMode m_funny_move_mode;
  LineTrackingMode m_line_tracking_mode;
  ManualMode m_manual_mode;

  //BTDriver m_bt_driver;
  MoveDriver m_move_driver;
  IRDriver m_L_ir_driver;
  IRDriver m_R_ir_driver;
  USDriver m_us_driver;
  SoftwareSerial m_blutooth;

  Controller() : m_avoidance_mode(this), m_funny_move_mode(this), m_line_tracking_mode(this), m_manual_mode(this), m_move_driver(), m_L_ir_driver(4), m_R_ir_driver(5), m_us_driver(12, 11), m_blutooth(3, 10) {
    m_current_mode = &m_manual_mode;
    m_blutooth.begin(9600);
  }

  void run() {

    float dist = m_us_driver.watch();

    Serial.println(dist);
    
    Mode* next_mode = m_current_mode->run();
    if (next_mode != NULL) {
      m_current_mode = next_mode;
    }
  }

private:
  Mode* m_current_mode;
};

#endif
