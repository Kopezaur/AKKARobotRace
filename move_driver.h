#ifndef MOVE_DRIVER__H
#define MOVE_DRIVER__H

class MoveDriver {
public:
  MoveDriver() {
    pinMode(dir1PinL, OUTPUT); 
    pinMode(dir2PinL, OUTPUT); 
    pinMode(speedPinL, OUTPUT);  
    pinMode(dir1PinR, OUTPUT);
    pinMode(dir2PinR, OUTPUT); 
    pinMode(speedPinR, OUTPUT); 
  }

  void set_speed(float linear, float rotation) {
    // Inverse kinematics here.
    
    float L_speed = linear - rotation;
    float R_speed = linear + rotation;

    set_L_speed(L_speed);
    set_R_speed(R_speed);
  }

private:
  void set_L_speed(float speed) {
    if (speed >= 0.0f) {
      digitalWrite(dir1PinL, HIGH);
      digitalWrite(dir2PinL, LOW);
    }
    else {
      digitalWrite(dir1PinL, LOW);
      digitalWrite(dir2PinL, HIGH);
    }

    analogWrite(speedPinL, speed*255.0f); 
  }

  void set_R_speed(float speed) {
    if (speed >= 0.0f) {
      digitalWrite(dir1PinR, HIGH);
      digitalWrite(dir2PinR, LOW);
    }
    else {
      digitalWrite(dir1PinR, LOW);
      digitalWrite(dir2PinR, HIGH);
    }

    analogWrite(speedPinR, speed*255.0f); 
  }
};

#endif
