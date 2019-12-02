#include "controller.h"
#include "manual_mode.h"

ManualMode::ManualMode(Controller* controller) : Mode(controller) {
    
}

Mode* ManualMode::run() {
  return NULL;
}
