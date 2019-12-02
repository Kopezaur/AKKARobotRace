#include "controller.h"
#include "line_tracking_mode.h"

#include <math.h>

LineTrackingMode::LineTrackingMode(Controller* controller) : Mode(controller) {
    
}

Mode* LineTrackingMode::run() {
  // 0.0
  //m_controller->m_move_driver.set_speed(0.5f, 0.2f);


  float L_value = m_controller->m_L_ir_driver.get_value();
  float R_value = m_controller->m_R_ir_driver.get_value();

  float rot_speed = (R_value - L_value)*0.7f;

  

  Serial.print(L_value);
  Serial.print("\n");

  Serial.print(R_value);
  Serial.print("\n\n");

  //delay(100);

  m_controller->m_move_driver.set_speed(0.6f, rot_speed);


  
  
  
  return NULL;
}
