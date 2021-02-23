#define encoder0PinA 18
#define encoder0PinB 19

#include <Encoder.h>

int directionPin = 12;
int brakePin = 9;
int motorSpeedPin = 3;
Encoder myEnc(18,19);
volatile int encoderPos_f = 0;
float current_pos_f = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("set up");
  pinMode(encoder0PinA, INPUT); 
  pinMode(encoder0PinB, INPUT); 
  int encoderStart = myEnc.read();
  int lastEncoder = encoderStart;
  float encoderRatio = 465.0/360.0;
  int Kp = 0;
  int Ki = 0;
  int Kd = 0;
  float errorSum = 0.;
  float lastError = 0.;
}

void loop(){ 
  digitalWrite(brakePin, LOW);   //Disengage the Brake for Channel A

  //if user tries to input angle
  
  //  int encoderGoal = *user input thingy in the GUI*
  //  int encoder = myEnc.read();
  //  int encoderGoal = angle*encoderRatio - encoderStart;
  //  int error = encoderGoal - encoder;
  //  
  //  u = Kp*error + Ki*errorSum + Kd*(error-lastError);
  //  PWM = abs(u);
  //  if(u<0){digitalWrite(directionPin, LOW);}
  //  else{digitalWrite(directionPin, HIGH);}
  //  analogWrite(motorSpeedPin, PWM);
  //  delay(10);




  //if user tries to input velocity

  //  float speedGoal = *user input thingy in the GUI*
  //  if(speedGoal < 0){digitalWrite(directionPin, LOW);}
  //  else{digitalWrite(directionPin, HIGH);}
  
  //  int encoder = myEnc.read();
  //  int speed = (encoder-lastEncoder)/10.0
  //  float error = speedGoal - speed;
  //  u = Kp*error + Ki*errorSum + Kd*(error-lastError);
  //  PWM = abs(u);
  //  analogWrite(motorSpeedPin, PWM);
  
  //  lastEncoder = encoder;
  
  
   
  
  }
