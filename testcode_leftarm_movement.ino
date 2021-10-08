//sample position control code for left hand of bot 



float error, integral = 0;
  int pos, req=85, pwm;
  float kp=1.7, ki=0.025;
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(A1,INPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
 

}

void loop() {
 

  
 pos=analogRead(A1);
 pos=pos/4;
  error = (req-pos);
  if(error<0)
  {
    
     digitalWrite(12,  LOW);
  }
  else
  {
     digitalWrite(12, HIGH);
    
  }

  
 pwm = kp*abs(error);
if(abs(error)<=20)
 {
  integral = integral+ abs(error);
   pwm = kp*abs(error)+(ki*integral);
 }

 if(pwm >= 200)
 {
  pwm = 0;
 }
  
  
  analogWrite(6,pwm);
 
 Serial.println(error);
  Serial.println(pos);
  Serial.println(pwm);
   

}
