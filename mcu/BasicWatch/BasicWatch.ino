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
A4988 stepper(MOTOR_STEPS, DIR, STEP, MS1, MS2, MS3);
int flag = 1;

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
    // Set target motor RPM to 1RPM and microstepping to 1 (full step mode)
    stepper.begin(command_rpm(1), FULL_STEP);
}

void loop() {
    // Tell motor to rotate 360 degrees. That's it.
    if(flag == 1){
      stepper.rotate(command_deg(90));
      flag=0;
    }
}
