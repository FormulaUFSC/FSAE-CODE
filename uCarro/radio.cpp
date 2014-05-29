#include "radio.h"

int Radio::priority = 3;
const int Rate = 115200;
Radio::Radio(void){

}

void Radio::setup(HardwareSerial*Serial,Skeleton*skeleton){
    this->Serial=Serial;
    this->skeleton=skeleton;
    Serial->begin(Rate);
}
void Radio::loop(){
    Serial->println("Transmitindo Serialmente...");
}
