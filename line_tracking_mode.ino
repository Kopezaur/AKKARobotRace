#include "controller.h"
#include "line_tracking_mode.h"

LineTrackingMode::LineTrackingMode(Controller* controller) : Mode(controller) {
    
}

Mode* LineTrackingMode::run() {
  return NULL;
}
