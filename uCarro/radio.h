#ifndef Radio_h
#define Radio_h

#include <arduino.h>
#include "skeleton.h"

class Radio{
    HardwareSerial*Serial;
    Skeleton*skeleton;
 public:
  Radio(void);
  void setup(HardwareSerial*Serial, Skeleton*skeleton);
  void loop();
  static int priority;
};

#endif
