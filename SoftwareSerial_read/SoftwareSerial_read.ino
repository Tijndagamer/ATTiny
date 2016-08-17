#include <SoftwareSerial.h>

// You can use 0 and 1 or 2 and 4
#define rxPin 0
#define txPin 1

SoftwareSerial SoftSerial(rxPin, txPin);

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  SoftSerial.begin(9600); // It's only 9600 baud when the clock is set to 1MHz. If the clock is 8MHz it wil be 1200 baud.
  SoftSerial.println("Starting SoftwareSerial_example");
}

void loop() {
  char input[8];
  for(int i = 8; i > 0; i--){
    input[i] = SoftSerial.read();
  }
  SoftSerial.println(input);
  delay(1000);
}
