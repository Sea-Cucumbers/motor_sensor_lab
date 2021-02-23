#define encoder0PinA 18
#define encoder0PinB 19

#include <Encoder.h>

int directionPin = 12;
int brakePin = 9;
int motorSpeedPin = 3;
Encoder myEnc(18,19);
float encoderRatio = 465.0/360.0;
float KpAngle = 1.;
float KiAngle = 0.005;
float KdAngle = 0;
float KpSpeed = 0.01;
float KiSpeed = 1;
float KdSpeed = 0;
float errorSum = 0.;
float lastError = 0.;
int index = 0;
const int MaxChars = 3;
char strValue[MaxChars];
float angle = 0.;
float vel = 0.;
bool isAngle = false;
float lastEncoder = 0;
float PWM = 0;

void setup() {
  Serial.begin(9600);
  pinMode(encoder0PinA, INPUT); 
  pinMode(encoder0PinB, INPUT); 
  float encoderStart = myEnc.read();
  
}

void loop(){ 
digitalWrite(brakePin, LOW);   //Disengage the Brake for Channel A
// Input angle  
if(isAngle){
  
  float encoder = myEnc.read();
  float encoderGoal = angle*encoderRatio;
  float error = encoderGoal - encoder;
    
  float u = -KpAngle*error - KiAngle*errorSum - KdAngle*(error-lastError);
  int PWM = abs(u);
  Serial.println(error);
  if(u<0){digitalWrite(directionPin, LOW);}
  else{digitalWrite(directionPin, HIGH);}
  analogWrite(motorSpeedPin, PWM);
  delay(10);

  errorSum += error;
  lastError = error;

}

// Input Velocity
else{
  float speedGoal = vel*465.;
  if(speedGoal < 0){digitalWrite(directionPin, LOW);}
  else{digitalWrite(directionPin, HIGH);}
  
  float encoder = myEnc.read();
  float realSpeed = (encoder-lastEncoder)/0.1;
  float error = speedGoal - abs(realSpeed);
  float u = KpSpeed*error + KiSpeed*errorSum + KdSpeed*(error-lastError);
  PWM += u;
  Serial.print(speedGoal);
  Serial.print("    ");
  Serial.print(abs(realSpeed));
  Serial.print("    ");
  Serial.print(error);
  Serial.print("    ");
  Serial.println(PWM);
  analogWrite(motorSpeedPin, PWM);
  
  lastEncoder = encoder;
  delay(100); 
  
  }
}


  void serialEvent()
{
   while(Serial.available()) 
   {
      char ch = Serial.read();//read each character
      if(index < MaxChars && isDigit(ch)) {      
        strValue[index] = ch; //stack up all the characters in one array
        index++;
        
        }else{   
          float string = atoi(strValue); 
          if(isAngle){angle = string;}
          else{vel = string;}
          index = 0;//reset the index
          //Serial.println(string);
          myEnc.write(0);
      }  
   }
}
