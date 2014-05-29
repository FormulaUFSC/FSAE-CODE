#include <arduino.h>

/*
FSAE-CODE
=========

Arquivo principal do firmware do arduino.

*/

#include "skeleton.h"
#include "radio.h"

Skeleton skeleton;
Radio radio;
//BMS bms;
//CFW11 cfw11;
//Security security;

/*
 A função setup é utilizada para chamar o setup dos submodulos que compõe o firmware.
*/

void setup() {
  skeleton.setup();
  radio.setup(&Serial3, &skeleton);
  /*
  bms.setup(&Serial3);
  cfw11.setup(&Serial3);
  security.setup();
  */
}

// the loop routine runs over and over again forever:
int counter=0;
void loop() {
  if(! counter % skeleton.priority)
    skeleton.loop();

  if(! counter % radio.priority)
    radio.loop();
  /*
  if(! counter % bms.priority)
    bms.loop();
  if(! counter % cfw11.priority)
    cfw11.loop();
  if(! counter % security.priority)
    security.loop();
  */
  counter++;
}
