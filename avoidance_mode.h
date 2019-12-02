#ifndef AVOIDANCE_MODE__H
#define AVOIDANCE_MODE__H

#include "mode.h"


class AvoidanceMode : public Mode {
public:
  AvoidanceMode(Controller* controller);

  Mode* run();
};

#endif
