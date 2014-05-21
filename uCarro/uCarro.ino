#include <arduino.h>
#include <ModbusMaster.h>
/*
FSAE-CODE
=========

Arquivo principal do firmware do arduino.

IDE do code blocks disponível em:
http://sourceforge.net/projects/arduinodev/files/CodeBlocks-Arduino-20131127.7z/download
*/

#include "skeleton.h"
#include "cfw11.h"

Skeleton skeleton;
//BMS bms;
CFW11 cfw11;
//Radio radio;
//Security security;

/*
 A função setup é utilizada para chamar o setup dos submodulos que compõe o firmware.
*/

void setup() {
  skeleton.setup();
  cfw11.setup();
  /*
  bms.setup();
  radio.setup(&Serial, &bms, &cfw11, &securit);
  security.setup();
  */
}

// the loop routine runs over and over again forever:
int counter=0;
void loop() {
  if(! counter % skeleton.priority)
    skeleton.loop();
  if(! counter % cfw11.priority)
    cfw11.loop();
  /*
  if(! counter % bms.priority)
    bms.loop();
  if(! counter % radio.priority)
    radio.loop();
  if(! counter % security.priority)
    security.loop();
  */
  counter++;
}
