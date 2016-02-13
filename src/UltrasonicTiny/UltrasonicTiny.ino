#include <SoftwareSerial.h>

/*
 * This program reads the measurements from a HC-SR04 and prints them out over serial.
 * Made by: MrTijn/Tijndagamer
 * Important notes: This program has to be compiled with clock of 1MHz internal,
 * otherwise it does not work correctly.
 *
 * Wiring:
 *                   ATTiny85
 * -                1|       |8      5V
 * ECHO on HC-SR04  2|       |7      -
 * TRIG on HC-SR04  3|       |6      RX
 * GND              4|       |5      TX
 *
 * Connect the Vcc and GND of the HC-SR04 to 5V and GND.
 */

#define rxPin 0
#define txPin 1
#define trigPin 4
#define echoPin 3

SoftwareSerial soft(rxPin, txPin);

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  soft.begin(9600);
}

void loop() {
  double duration;
  double distance;

  // Send the signal to start measuring
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 34.3;
  soft.print(distance);
  soft.println(" cm");
  
  delay(100);
}
