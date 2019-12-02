#ifndef MANUAL_MODE__H
#define MANUAL_MODE__H

#include "mode.h"


class ManualMode : public Mode {
public:
  ManualMode(Controller* controller);

  Mode* run();
};

#endif
