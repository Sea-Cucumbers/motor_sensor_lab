int val=0;
int pot_pin=2;
int valout=13;

void setup() 
{
  Serial.begin(9600);
pinMode(valout,OUTPUT);
}

void loop()
{
  val=analogRead(pot_pin);
  Serial.print("Potentiometer =");
  Serial.println(val);
  digitalWrite(valout,HIGH);
  delay(val);
  digitalWrite(valout,LOW);
  delay(val);
}
