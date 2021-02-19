#define ultrasonicTrigPin 13
#define ultrasonicEchoPin 12

void setup() {
  Serial.begin (9600);
  pinMode(ultrasonicTrigPin, OUTPUT);
  pinMode(ultrasonicEchoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(ultrasonicTrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(ultrasonicTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonicTrigPin, LOW);

  // Get received pulse width in microseconds
  duration = pulseIn(ultrasonicEchoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance >= 200 || distance <= 0){
    Serial.println("us 0");
  }
  else {
    Serial.print("us ");
    Serial.println(distance);
  }
  delay(100);
}
