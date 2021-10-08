float error1 , error2, integral1 = 0, integral2=0;
  int pos1,pos2, req=85, pwm1 ,pwm2;
  float kp1=1.7,kp2=1.8,  ki1=0.025, ki2=0.025;
void setup() {
  //left arm config
  pinMode(12, OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(A3,INPUT);
  
  //right arm config
  pinMode(10, OUTPUT);
  pinMode(11  ,OUTPUT);
  pinMode(A2,INPUT);

  pinMode(12,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
 

}

void loop() {
 

  
 pos1=analogRead(A2);
 pos2=analogRead(A3);
 pos1=pos1/4;
 pos2=pos2/4;
  error1 = (req-pos1);
  error2 = (req-pos2);
  if(error1<0 || error2<0)
  {
     digitalWrite(12 , HIGH);
     digitalWrite(13,  LOW);
      digitalWrite(10 , HIGH);
     digitalWrite(11,  LOW);
     
  }
  else
  {
     digitalWrite(12 , LOW);
     digitalWrite(13  HIGH);
      digitalWrite(10, LOW);
     digitalWrite(11,  HIGH);
   
    
  }

  
 pwm1 = kp1*abs(error1);
 pwm2 = kp2*abs(error2);
if(abs(error1)<=20 ||  abs( error2)<=20)
 {
  integral1 = integral+ abs(error1);
  integral2  = integral + abs(error2);
   pwm1 = kp*abs(error1)+(ki*integral1);
   pwm2 = kp*abs(error2)+(ki*integral2);
 }

 if(pwm1 >= 200 || pwm2> =200)
 {
  pwm1 = 0;
  pwm2 = 0;
 }
  
  
  analogWrite(7,pwm1);
  analogWrite(6,pwm2);
 
 Serial.print(error1);
 Serial.print(' ');
 Serial.println(pos1);
 delay(100);
 //Serial.print(' ');
 //Serial.println(pwm1);
   

}
