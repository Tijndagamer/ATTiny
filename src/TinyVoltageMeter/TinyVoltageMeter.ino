#include <SoftwareSerial.h>
#include <EEPROM.h>

#define rxPin 0
#define txPin 1
#define analogIn 3 // Pin 4 is also an analog input pin.

// Settings
int inputVoltage = 3.3;
boolean saveInEEPROM = true; // Saves raw analogVals divided by 4 in EEPROM.

double voltage, prevVoltage;
int address = 0;

SoftwareSerial SoftSerial(rxPin, txPin);

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(analogIn, INPUT);

  SoftSerial.begin(9600);
  SoftSerial.println("Starting TinyVoltageMeter");

  if (saveInEEPROM)
  {
    SoftSerial.println("Printing EEPROM");
    for (int address = 0; address < EEPROM.length() + 1; address++)
    {
      byte value;
      value = EEPROM.read(address);
      SoftSerial.print(address);
      SoftSerial.print("\t");
      SoftSerial.print(value, DEC);
      SoftSerial.println();
      delay(50);
    }
    SoftSerial.println("Done printing EEPROM memory.");
  }
}

void loop() {
  int analogVal = analogRead(analogIn);
  voltage = (inputVoltage * analogVal) / 1024.0;
  if (voltage != prevVoltage){
    SoftSerial.print(voltage);
    SoftSerial.println(" V");
    prevVoltage = voltage;
    if (saveInEEPROM)
    {
      int writeVal = analogVal / 4;
      EEPROM.write(address, writeVal);
      address++;
    }
  }
  delay(250);
}
