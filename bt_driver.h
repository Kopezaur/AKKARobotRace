#ifndef BT_DRIVER__H
#define BT_DRIVER__H

#define MAX_PACKETSIZE 32

#include <SoftwareSerial.h>

class BTDriver {
public:
  BTDriver() : m_serial(10, 3){
    m_serial.begin(9600);
  }

  

  int read(char* data) {
    m_serial.println("lalala");
    if (m_serial.available()) {
      data[0] = m_serial.read();
      Serial.println(data[0]);
      return 1;
    }
    return 0;
  }

private:
  SoftwareSerial m_serial;
};

#endif
