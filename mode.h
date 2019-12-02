#ifndef MODE__H
#define MODE__H

class Controller;

class Mode {
public:

  Mode(Controller* controller) : m_controller(controller) {
    
  }

  virtual Mode* run() {
    return NULL;
  }

protected:
  Controller* m_controller;
};

#endif
