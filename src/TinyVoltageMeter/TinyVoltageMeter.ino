#include <SoftwareSerial.h>

#define rxPin 0
#define txPin 1
#define analogIn 3 // Pin 4 is also an analog input pin.

int inputVoltage = 5.0;

SoftwareSerial SoftSerial(rxPin, txPin);

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(analogIn, INPUT);

  SoftSerial.begin(9600);
  SoftSerial.println("Starting TinyVoltageMeter");
}

void loop() {
  double voltage;
  int analogVal = analogRead(analogIn);
  voltage = (inputVoltage * analogVal) / 1024.0;
  SoftSerial.println(analogVal);
  SoftSerial.print(voltage);
  SoftSerial.println(" V");
  delay(250);
}
