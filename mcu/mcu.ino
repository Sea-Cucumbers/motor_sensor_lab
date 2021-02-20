#include <Servo.h>
#define ultrasonicTrigPin 13
#define ultrasonicEchoPin 12
#define servoPin          9
#define ROT_CLK           8
#define ROT_DT            7
#define ROT_SW            6

int rot_curr;
int rot_prev;
int counter = 0;

Servo sg90;
int servoPos = 0;

void setup() {
  Serial.begin (9600);
  pinMode(ultrasonicTrigPin, OUTPUT);
  pinMode(ultrasonicEchoPin, INPUT);
  pinMode(ROT_CLK, INPUT);
  pinMode(ROT_DT, INPUT);
  pinMode(ROT_SW, INPUT);
  rot_prev = digitalRead(ROT_CLK);
  sg90.attach(servoPin);
}

void loop() {
  /*
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
  */
  rot_curr = digitalRead(ROT_CLK);
  int rot_dt = digitalRead(ROT_DT);

  if (rot_curr != rot_prev){
    if (rot_dt != rot_curr) { 
      //moved CCW
      if (rot_curr == 0 && rot_dt == 1)
        counter ++;
        if (servoPos < 160)
          servoPos += 30;
    } 
    else {
      if (rot_curr == 1 && rot_dt == 1)
        // moved CW
        counter --;
        if (servoPos > 0 )
          servoPos -= 30;
    }
  } 
  rot_prev = rot_curr;
  //potPos = analogRead(potPos);
  Serial.print(rot_curr);
  Serial.print('\t');
  Serial.print(rot_dt);
  Serial.print('\t');
  Serial.print(digitalRead(ROT_SW));
  Serial.print('\t');
  Serial.print(counter);
  Serial.print('\t');
  Serial.println(servoPos);
  sg90.write(servoPos);
  /*
  // testing servo
  for (servoPos = 0; servoPos <= 180; servoPos++) { 
    // in steps of 1 degree
    sg90.write(servoPos);          
    delay(15);                   
  }
  for (servoPos = 180; servoPos >= 0; servoPos--) { 
    sg90.write(servoPos);             
    delay(15);                    
  }
  */
  delay(15);
}
