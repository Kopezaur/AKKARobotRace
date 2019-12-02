#ifndef US_DRIVER__H
#define US_DRIVER__H


class USDriver {
public:
  USDriver(int trig_pin, int echo_pin) : m_trig_pin(trig_pin), m_echo_pin(echo_pin) {
    pinMode(m_trig_pin, OUTPUT); 
    pinMode(m_echo_pin,INPUT); 
  }

  /*detection of ultrasonic distance*/
  float watch(){
    long echo_distance;
    digitalWrite(m_trig_pin,LOW);
    delayMicroseconds(5);                                                                              
    digitalWrite(m_trig_pin,HIGH);
    delayMicroseconds(15);
    digitalWrite(m_trig_pin,LOW);
    echo_distance=pulseIn(m_echo_pin,HIGH);
    echo_distance=(float)echo_distance*0.01657; //how far away is the object in cm
    //Serial.println((int)echo_distance);
    return round(echo_distance);
  }

  float get_distance() {
    return 0.0f;
  }

private:
  int m_trig_pin;
  int m_echo_pin;
};

#endif
