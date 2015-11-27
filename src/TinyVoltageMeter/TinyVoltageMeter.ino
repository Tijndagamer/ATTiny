#include <SoftwareSerial.h>

#define rxPin 0
#define txPin 1
#define analogIn 3 // Pin 4 is also an analog input pin.

int inputVoltage = 5.0;
double voltage, prevVoltage;

SoftwareSerial SoftSerial(rxPin, txPin);

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(analogIn, INPUT);

  SoftSerial.begin(9600);
  SoftSerial.println("Starting TinyVoltageMeter");
}

void loop() {
  int analogVal = analogRead(analogIn);
  voltage = (inputVoltage * analogVal) / 1024.0;
  if (voltage != prevVoltage){
    SoftSerial.print(voltage);
    SoftSerial.println(" V");
    prevVoltage = voltage;
  }
  delay(250);
}
