#include <dht.h>

#define ULTRASONIC_TRIG_PIN 13
#define ULTRASONIC_ECHO_PIN 22
#define IR_PIN              A0
#define POT_PIN             A1
#define IR_WINDOW_SIZE      4
#define DHT_PIN             2
#define DHT_TYPE            11

int ir_val;          // raw value from ir sensor
int ir_val_avg;      // low-passed raw ir value 
double ir_cm = 0;    // low-passed raw ir value converted to cm
double ir_cm_prev = 0;

int ir_window[IR_WINDOW_SIZE];
unsigned int ir_curr_entry = 0;

dht DHT;

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

void setup() {
  init_ir_window();
  Serial.begin (9600);
  pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);
  pinMode(IR_PIN, INPUT);
}

void loop() {
  // Potentiometer code
  int pot_degrees = map(analogRead(POT_PIN), 0, 1023, 0, 225);
  
  // Ultrasonic code
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);

  // Get received pulse width in microseconds
  int us_duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);
  int us_cm = (us_duration/2) / 29.1;
  if (us_cm >= 200 || us_cm < 0){
    us_cm = -1;
  }

  // IR code
  ir_val = analogRead(IR_PIN);
  ir_val_avg = calculate_ir_val_avg(ir_val);
  ir_cm = (1.2381098271285667e+002
     -  1.0116656095344860e+000 * pow(ir_val_avg,1)
     +  3.8880974300887472e-003 * pow(ir_val_avg,2)
     -  7.6736080602734829e-006 * pow(ir_val_avg,3)
     +  7.5096434225708319e-009 * pow(ir_val_avg,4)
     -  2.8890824514025209e-012 * pow(ir_val_avg,5));

  // Temp/humidity code
  int chk = DHT.read11(DHT_PIN);
  float hum = DHT.humidity;
  float temp_c = DHT.temperature;

  Serial.print("Potentiometer: ");
  Serial.print(pot_degrees);
  Serial.print("\t Ultrasound: ");
  Serial.print(us_cm);
  Serial.print("\t Infrared: ");
  Serial.print(ir_cm);
  Serial.print("\t Temperature (C): ");
  Serial.print(temp_c);
  Serial.print("\t Humidity: ");
  Serial.println(hum);
  
  ir_cm_prev = ir_cm;
  delay(15);
}
