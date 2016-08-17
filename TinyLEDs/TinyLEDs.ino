const int ledPin1 = 2;
const int ledPin2 = 3;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  delay(500);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  delay(500);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
}
