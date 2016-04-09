#include <SoftwareSerial.h>
#include <EEPROM.h>

#define rxPin 0
#define txPin 1

SoftwareSerial SoftSerial(rxPin, txPin);

int address = 0;
//byte value;

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

  SoftSerial.begin(9600);
  SoftSerial.println("Starting EEPROM_write_serial_stream");

  SoftSerial.println("Printing EEPROM");
  for (int address = 0; address < EEPROM.length() + 1; address++)
  {
    char value = EEPROM.read(address);

    SoftSerial.print(address);
    SoftSerial.print("\t");
    //SoftSerial.print(value, DEC);
    SoftSerial.print(value);
    SoftSerial.println();
    delay(25);
  }
  SoftSerial.println("Done printing EEPROM memory.");
}

void loop() {
  byte c = 0;
  c = SoftSerial.read();
  if (c != 0)
  {
    EEPROM.write(address, c);
    address++;
    if (address == (EEPROM.length() + 1))
    {
      SoftSerial.println("Last address reached, overwriting in 2 seconds.");
      delay(2000);
      address = 0;
    }
    SoftSerial.print("Wrote ");
    SoftSerial.print(int(c));
    SoftSerial.print(" to addr ");
    SoftSerial.println(address);
  }
  delay(50);
}
