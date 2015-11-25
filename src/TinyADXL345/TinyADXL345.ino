#include <TinyWireM.h>
#include <SoftwareSerial.h>

#define ADXL345_ADDR 0x53
#define rxPin 4
#define txPin 1

SoftwareSerial debug(rxPin, txPin);

//const uint8_t adxlAddr = 0x53;

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  debug.begin(9600);
  debug.println("Starting TinyADXL345");
  TinyWireM.begin();
  InitAccel();
  GetSomething();
}

void loop() {
  //GetSomething();
}

void SendData(uint8_t inputRegister, uint8_t data){
  debug.print("Running SendData. inputRegister: ");
  debug.print(inputRegister);
  debug.print(" data: ");
  debug.println(data);
  TinyWireM.beginTransmission(ADXL345_ADDR);
  TinyWireM.send(inputRegister);
  TinyWireM.send(data);
  TinyWireM.endTransmission();
}

void InitAccel(){
  /*
  TinyWireM.beginTransmission(ADXL345_ADDR);
  TinyWireM.send(0x2D);
  TinyWireM.send(0x08);
  TinyWireM.endTransmission();
  */
  debug.println("Running InitAccel()");
  SendData(0x2D, 0x08);
  debug.println("Done with Initaccel()");
}

void GetSomething()
{
  byte data_format = TinyWireM.requestFrom(ADXL345_ADDR, 0x31);
  byte bd_rate = TinyWireM.requestFrom(ADXL345_ADDR, 0x2C);
  byte check_if_something_works = TinyWireM.requestFrom(ADXL345_ADDR, 0x2D);
  debug.println(data_format);
  debug.println(bd_rate);
  debug.println(check_if_something_works);
}

