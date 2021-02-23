#include <Servo.h>

// Declaring the pins used for the servo motor and potentiometer

int pot_pin      = 2;      // Pin at which the potentiometer is to be connected to
int servo_pin    = 3;     // Pin at which the servo motor is to be connected to
int control_button = 10;    // Pin at which the push button is to be connectoed to


// Creating a servo object to be able to use library functionalities

Servo motor1;


// Declaring variable for computation
int v_pot          = 0;                 // Variable to output the voltage of the potentiometer 
int servo_inp      = 0;    // Variable to privode an input to the servo motor 
int pot_output     = 0;    // Variable to get the potentiometer output
float v_ref        = 3.3;    // Reference voltage for the potentiometer 
int motor_speed    = 0;    // Variable to out the motor speed

void setup() 
{

   // setting the control button pin as INPUT pin
  pinMode(control_button, INPUT);    
  
  // setting the serial communication baud rate to 9600 bps
  Serial.begin(9600);
  
  // setting the servo motor to servo_pin
  motor1.attach(servo_pin);
}
void loop() {

  // perform motor speed control only if button is pressed
  
  if(digitalRead(control_button) == HIGH) {
     
     // setting the servo motor servo pin
     motor1.attach(servo_pin);
     
     // getting the output from potentiometer
     pot_output = analogRead(pot_pin);
     
     // converting ADC output to potentiometer voltage
     v_pot = (v_ref)/(1023.0) * pot_output;
     
     // calculating the servo motor input value based on the potentiometer output
     servo_inp = 180/(v_ref) * v_pot;
     
     // writing the servo motor value to the servo motor  
     motor1.write(servo_inp);
     
     // converting the servo motor input to rpm 
     motor_speed = (5/9)*servo_inp - 50;
    
     // displaying the servo motor speed in rpm 
     Serial.println(motor_speed);
     
  } else {
     
     // Stop the motor
     motor1.detach();
     
     // print on the serial monitor that the motor operation is stopped   
     Serial.println("Stopped");   
  } 

}
