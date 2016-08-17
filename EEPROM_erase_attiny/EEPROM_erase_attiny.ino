#include <SoftwareSerial.h>
#include <EEPROM.h>

#define rxPin 0
#define txPin 1

int address = 0;
byte value;

SoftwareSerial SoftSerial(rxPin, txPin);

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  SoftSerial.begin(9600);
  SoftSerial.println("Starting EEPROM_read_attiny");

  SoftSerial.println("Erasing EEPROM...");
  for (int i = 0; i < EEPROM.length(); i++)
  {
    EEPROM.write(i, 0);
  }
  SoftSerial.println("Done erasing...");

  SoftSerial.println("Printing EEPROM");
  for (int address = 0; address < EEPROM.length() + 1; address++)
  {
    value = EEPROM.read(address);
    SoftSerial.print(address);
    SoftSerial.print("\t");
    SoftSerial.print(value, BIN);
    SoftSerial.println();
    delay(50);
  }
  SoftSerial.println("Done printing EEPROM memory.");
}

void loop() {
  /*
  value = EEPROM.read(address);
  SoftSerial.print(address);
  SoftSerial.print("\t");
  SoftSerial.print(value, BIN);
  SoftSerial.println();

  address++;
  if(address == EEPROM.length())
  {
    address = 0;
  }
  delay(50);
  
  */
}
