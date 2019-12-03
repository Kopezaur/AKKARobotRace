#ifndef AVOIDANCE_MODE__H
#define AVOIDANCE_MODE__H

#include "mode.h"


class AvoidanceMode : public Mode {

  int counter;
  int limitDist;
  int maxCounter;
  int obsDelay;
  
public:
  AvoidanceMode(Controller* controller);

  Mode* run();
};

#endif
