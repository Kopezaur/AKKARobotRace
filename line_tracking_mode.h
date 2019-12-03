#ifndef LINE_TRACKING_MODE__H
#define LINE_TRACKING_MODE__H

#include "mode.h"


class LineTrackingMode : public Mode {
public:
  LineTrackingMode(Controller* controller);

  Mode* run();

  int counter;
  int limitDist;
  int maxCounter;
};

#endif
