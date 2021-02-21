#include <Servo.h>
#include <Arduino.h>
#include "A4988.h"

// using a 200-step motor (most common)
#define MOTOR_STEPS 200
// configure the pins connected
#define DIR 4
#define STEP 5
#define MS1 3
#define MS2 2
#define MS3 1
#define FULL_STEP 1

#define ultrasonicTrigPin 13
#define ultrasonicEchoPin 12
#define servoPin          9
#define ROT_CLK           8
#define ROT_DT            7
#define IR_pin            A0

int rot_curr;
int rot_prev;
int counter = 0;
int ir_val;
double ir_cm = 0;
double ir_cm_prev = 0;
int rot_dt;

Servo sg90;
int servoPos = 0;

A4988 stepper(MOTOR_STEPS, DIR, STEP, MS1, MS2, MS3);
int stepper_run = 1;

float command_rpm(float rpm){
  if (rpm < 0)
    return 0;
  else if (rpm > 5)
    return 50;
  else
    return rpm * 10;
  
}

long command_deg(float deg){
  return (long)(deg * 10.32);
}


void setup() {
  Serial.begin (9600);
  pinMode(ultrasonicTrigPin, OUTPUT);
  pinMode(ultrasonicEchoPin, INPUT);
  pinMode(ROT_CLK, INPUT);
  pinMode(ROT_DT, INPUT);
  pinMode(IR_pin, INPUT);
  rot_prev = digitalRead(ROT_CLK);
  sg90.attach(servoPin);
  stepper.begin(command_rpm(5), FULL_STEP);
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
  rot_dt = digitalRead(ROT_DT);

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
  ir_val = analogRead(IR_pin);
  ir_cm = (1.2381098271285667e+002
     -  1.0116656095344860e+000 * pow(ir_val,1)
     +  3.8880974300887472e-003 * pow(ir_val,2)
     -  7.6736080602734829e-006 * pow(ir_val,3)
     +  7.5096434225708319e-009 * pow(ir_val,4)
     -  2.8890824514025209e-012 * pow(ir_val,5));
  
  Serial.print(rot_curr);
  Serial.print('\t');
  Serial.print(rot_dt);
  Serial.print('\t');
  Serial.print(counter);
  Serial.print('\t');
  Serial.print(servoPos);
  Serial.print('\t');
  Serial.println(ir_cm);
  sg90.write(servoPos);

  if (ir_cm > 7 && ir_cm < 30){
    //stepper_tot = (int)ir_cm - 7;
    if (ir_cm - ir_cm_prev > 0.5){
      stepper.rotate(command_deg(3));
    }
    else if (ir_cm - ir_cm_prev < -0.5){
      stepper.rotate(command_deg(-3));
    }
  }
  ir_cm_prev = ir_cm;
  delay(15);
}