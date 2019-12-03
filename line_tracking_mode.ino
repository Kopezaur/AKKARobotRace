#include "controller.h"
#include "line_tracking_mode.h"

#include <math.h>

LineTrackingMode::LineTrackingMode(Controller* controller) : Mode(controller) {
    counter = 0;
    limitDist = 100;
    maxCounter = 7;
}

Mode* LineTrackingMode::run() {
  while (m_controller->m_blutooth.available()) {
    char data = m_controller->m_blutooth.read();
    if (data == '3') {
      m_controller->m_move_driver.set_speed(0.0f, 0.0f);
      return &m_controller->m_manual_mode;
    }
  }

  
  float L_value = m_controller->m_L_ir_driver.get_value();
  float R_value = m_controller->m_R_ir_driver.get_value();

  float rot_speed = (R_value - L_value)*0.7f;


  //delay(100);

  m_controller->m_move_driver.set_speed(0.6f, rot_speed);

  float dist = m_controller->m_us_driver.watch();

  Serial.println(dist);

  if (counter >= 0) {
    if (dist < 50.0) {
      counter++;
      if (counter >= 5) {
        
        counter = -1;
        m_controller->m_move_driver.set_speed(0.0f, 0.0f);
        return &m_controller->m_avoidance_mode;
      }
    }
    else {
      counter = 0;
    }
  }

  /*
  if (dist<limitDist) {
    ++counter; // keep counting
  }
  if (dist>limitDist) {
      counter=0;
  } //Count is restarted
  if (counter > maxCounter) {
    counter=-100;
    return &m_controller->m_avoidance_mode;
  }
  */
  
  return NULL;
}
