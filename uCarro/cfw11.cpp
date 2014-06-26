#include <ModbusMaster.h>
#include "cfw11.h"

//Porta na qual o RS232 está ligado:
#define porta 2
//Endereço do inversor:
#define address 1
//Endereço do inversor:
#define baudrate 9600

int CFW11::priority = 3;

ModbusMaster node(porta, address);

CFW11::CFW11(void){

}

void CFW11::setup(){
  node.begin(baudrate);
}

void CFW11::loop(){
  uint8_t j, result;
  uint16_t data[6];

  // slave: read (1) 16-bit registers starting at register 4 to RX buffer
  result = node.readHoldingRegisters(4, 1);

  // do something with data if read is successful
  if (result == node.ku8MBSuccess)
  {
      data[j] = node.getResponseBuffer(j);
      Serial.print("Tensão Barram.CC (Ud):");
      Serial.println(data[0]);
  }else{
      Serial.println("fail");
  }

  result = node.readHoldingRegisters(6, 1);

  if (result == node.ku8MBSuccess)
  {
      data[j] = node.getResponseBuffer(j);
      Serial.print("Estado do Inversor:");
      switch(data[0]){
        case 0:
           Serial.println("Ready (Pronto)");
           break;
        case 1:
           Serial.println("Run (Execução)");
           break;
        case 2:
           Serial.println("Subtensão");
           break;
        case 3:
           Serial.println("Falha");
           break;
        case 4:
           Serial.println("Auto-Ajuste");
           break;
        case 5:
           Serial.println("Configuração");
           break;
        case 6:
           Serial.println("Frenagem CC");
           break;
        case 7:
           Serial.println("STO");
           break;
      }
  }else{
      Serial.println("fail");
  }

result = node.readHoldingRegisters(1, 1);

  // do something with data if read is successful
  if (result == node.ku8MBSuccess)
  {
      data[j] = node.getResponseBuffer(j);
      Serial.print("Velocidade do Motor:");
      Serial.println(data[0]);
  }else{
      Serial.println("fail");
  }
}
