#ifndef FUNNY_MOVE_MODE__H
#define FUNNY_MOVE_MODE__H

#include "mode.h"


class FunnyMoveMode : public Mode {
public:
  FunnyMoveMode(Controller* controller);

  Mode* run();
};

#endif
