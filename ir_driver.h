#ifndef IR_DRIVER__H
#define IR_DRIVER__H

class IRDriver {
public:
  IRDriver(int pin) : m_pin(pin) {
    
  }

  float get_value() {
    return ((float)analogRead(m_pin))/1024.0f;
  }

private:
  int m_pin;
};

#endif
