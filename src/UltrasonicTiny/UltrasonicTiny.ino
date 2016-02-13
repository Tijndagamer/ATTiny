#include <SoftwareSerial.h>

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
  long duration, distance;

  // Send the signal to start measuring
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 34.3;
  soft.println(duration);
  soft.print(distance);
  soft.println(" cm");
  
  delay(100);
}
