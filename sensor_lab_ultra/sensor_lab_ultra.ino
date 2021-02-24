#include <dht.h>
#include <NewPing.h>

#define IR_PIN              A3
#define POT_PIN             A2
#define IR_WINDOW_SIZE      4
#define DHT_PIN             2
#define DHT_TYPE            11
#define US_TRIG 13
#define US_ECHO 22
#define US_MAX_DISTANCE 200

unsigned long pingTimer;     // Holds the next ping time.
unsigned int pingSpeed = 50; // How frequently are we going to send out a ping (in milliseconds). 50ms would be 20 times a second.

int ir_val;          // raw value from ir sensor
int ir_val_avg;      // low-passed raw ir value 
double ir_cm = 0;    // low-passed raw ir value converted to cm
double ir_cm_prev = 0;

int us_cm = 0;

int ir_window[IR_WINDOW_SIZE];
unsigned int ir_curr_entry = 0;

dht DHT;

NewPing sonar(US_TRIG, US_ECHO, US_MAX_DISTANCE);

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
  //pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
  //pinMode(ULTRASONIC_ECHO_PIN, INPUT);
  pinMode(IR_PIN, INPUT);

  pingTimer = millis(); // Start now.
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

  // Temp/humidity code
  int chk = DHT.read11(DHT_PIN);
  float hum = DHT.humidity;
  float temp_c = DHT.temperature;

  // Ultrasonic code
  if (millis() >= pingTimer) {   // pingSpeed milliseconds since last ping, do another ping.
    pingTimer += pingSpeed;      // Set the next ping time.
    sonar.ping_timer(echoCheck); // Send out the ping, calls "echoCheck" function every 24uS where you can check the ping status.
  }

  Serial.print("Potentiometer: ");
  Serial.print(pot_degrees);
 
  Serial.print("\t Infrared: ");
  Serial.print(ir_cm);
  
  Serial.print("\t Temperature (C): ");
  Serial.print(temp_c);
  Serial.print("\t Humidity: ");
  Serial.print(hum);

  Serial.print("\t Ultrasonic: ");
  Serial.println(us_cm);
  
  ir_cm_prev = ir_cm;
  delay(15);
}

void echoCheck() {
  if (sonar.check_timer()) { // This is how you check to see if the ping was received.
    us_cm = sonar.ping_result / US_ROUNDTRIP_CM; // Ping returned, uS result in ping_result, convert to cm with US_ROUNDTRIP_CM.
  }
}
