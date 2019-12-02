 #include "configuration.h"
#include "controller.h"


Controller controller;
 

void setup()
{
  //my_serial.begin(9600);
 Serial.begin(9600);
}



void loop(){
  //my_serial.println("lalala");
  delay(100);
  
  
  controller.run();
//auto_tracking();
}
