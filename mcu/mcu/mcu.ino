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

#define servoPin          11
#define ROT_CLK           8
#define ROT_DT            7
#define SW_PIN            10

#define IR_PIN              A3
#define POT_PIN             A2
#define IR_WINDOW_SIZE      4

#define USER_CTR 1
#define SENSOR_CTR 0

#define SERIAL_BUF_LEN 100

int rot_curr;
int rot_prev;
int counter = 0;
int ir_val;          // raw value from ir sensor
int ir_val_avg;      // low-passed raw ir value 
double ir_cm = 0;    // low-passed raw ir value converted to cm
double ir_cm_prev = 0;
int rot_dt;

int ir_window[IR_WINDOW_SIZE];
unsigned int ir_curr_entry = 0;

// variables to store system state
// is switch pressed once, toggle state
int counter_sw = 0;
int sw_val;
bool system_state = SENSOR_CTR;
bool pressed = 0;

Servo sg90;
int servoPos = 0;

A4988 stepper(MOTOR_STEPS, DIR, STEP, MS1, MS2, MS3);
int stepper_run = 1;

char serialBuf[SERIAL_BUF_LEN];
int serialProducerIdx = 0;
int serialConsumerIdx = 0;

void init_ir_window(){
  for (int i = 0; i < IR_WINDOW_SIZE; i++){
    ir_window[i] = 0;
  }
}

void increment_ir_entry(){
  ir_curr_entry += 1;
  if (ir_curr_entry >= 4)
    ir_curr_entry -= 4;
}

int calculate_ir_val_avg(int val){
  ir_window[ir_curr_entry] = ir_val;
  increment_ir_entry();
  int sum = 0;
  for (int i = 0; i < IR_WINDOW_SIZE; i++)
    sum += ir_window[i];
  return sum/4;
}

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
  init_ir_window();
  Serial.begin (9600);
  pinMode(ROT_CLK, INPUT);
  pinMode(ROT_DT, INPUT);
  pinMode(SW_PIN, INPUT);
  pinMode(IR_PIN, INPUT);
  rot_prev = digitalRead(ROT_CLK);
  sg90.attach(servoPin);
  stepper.begin(command_rpm(5), FULL_STEP);
}

void loop() {
  // Potentiometer code
  int pot_degrees = map(analogRead(POT_PIN), 0, 1023, 0, 225);
  
  // IR code
  ir_val = analogRead(IR_PIN);
  ir_val_avg = calculate_ir_val_avg(ir_val);
  ir_cm = (1.2381098271285667e+002
     -  1.0116656095344860e+000 * pow(ir_val_avg,1)
     +  3.8880974300887472e-003 * pow(ir_val_avg,2)
     -  7.6736080602734829e-006 * pow(ir_val_avg,3)
     +  7.5096434225708319e-009 * pow(ir_val_avg,4)
     -  2.8890824514025209e-012 * pow(ir_val_avg,5));

  ir_cm_prev = ir_cm;

  /*
  Serial.print("pot ");
  Serial.print(pot_degrees);
  Serial.print("\n");
  Serial.print("ir ");
  Serial.print(ir_cm);
  Serial.print("\n");
  */
  
  rot_curr = digitalRead(ROT_CLK);
  rot_dt = digitalRead(ROT_DT);
  sw_val = digitalRead(SW_PIN);
  
  // software debouncer
  if (pressed == 0){
    if (sw_val == 1){
      counter_sw += 1;
    } else {
      if (counter_sw > 0)
        counter_sw -= 1;
    }
    if (counter_sw > 3){
      pressed = 1;
      counter_sw = 0;
    }
  } else { // pressed = 1
    if (sw_val == 0){
      counter_sw += 1;
    } else {
      if (counter_sw > 0)
        counter_sw -= 1;
    }
    if (counter_sw > 3){
      pressed = 0;
      counter_sw = 0;
      system_state = !system_state;
    }
  }

  if (system_state == SENSOR_CTR) {
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

    // If we're in sensor control mode, throw out any bytes
    // coming from the user
    serialProducerIdx = 0;
    serialConsumerIdx = 0;
    while (Serial.available()) {
      Serial.read();
    }
  } else {
    // Put any commands from the computer into the serial buffer
    while (Serial.available()) {
      serialBuf[serialProducerIdx] = Serial.read();
      ++serialProducerIdx;
      if (serialProducerIdx >= SERIAL_BUF_LEN) {
        serialProducerIdx = 0;
      }
    }

    // Look for newline between consumer and producer. If there isn't one, we
    // haven't gotten a full message
    bool fullMessage = false;
    int newlineIdx = 0;
    for (int i = serialConsumerIdx; i < serialProducerIdx; ++i) {
      if (serialBuf[i] == '\n') {
        fullMessage = true;
        newlineIdx = i;
        break;
      }
    }

    if (fullMessage) {
      if (serialBuf[serialConsumerIdx] + 128 == 's' &&
          serialBuf[serialConsumerIdx + 1] + 128 == 'v') {
        char pos[4];
        pos[0] = serialBuf[serialConsumerIdx + 3];
        if (newlineIdx >= serialConsumerIdx + 4) {
          pos[1] = 0;
        }
        if (newlineIdx >= serialConsumerIdx + 5) {
          pos[1] = serialBuf[serialConsumerIdx + 4];
          pos[2] = 0;
        }
        if (newlineIdx >= serialConsumerIdx + 6) {
          pos[2] = serialBuf[serialConsumerIdx + 4];
          pos[3] = 0;
        }

        String pos_str(pos);
        servoPos = pos_str.toInt();
      } else if (serialBuf[serialConsumerIdx] + 128 == 's' &&
                 serialBuf[serialConsumerIdx + 1] + 128 == 't') {
        // Stepper message
      } else if (serialBuf[serialConsumerIdx] + 128 == 'd' &&
                 serialBuf[serialConsumerIdx + 1] + 128 == 'a') {
        // DC angle message
      } else if (serialBuf[serialConsumerIdx] + 128 == 'd' &&
                 serialBuf[serialConsumerIdx + 1] + 128 == 'v') {
        // DC velocity message
      }
      serialConsumerIdx = newlineIdx;
    }
  }

  
  rot_prev = rot_curr;
  sg90.write(servoPos);

  if (ir_cm > 7 && ir_cm < 30){
    //stepper_tot = (int)ir_cm - 7;
    if (ir_cm - ir_cm_prev > 0.5){
      stepper.rotate(command_deg(7));
    }
    else if (ir_cm - ir_cm_prev < -0.5){
      stepper.rotate(command_deg(-7));
    }
  }
  delay(15);
}
