/*float error, integral = 0;
  int pos, req=168, pwm;
  float kp=1.9, ki=0.025;
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(A1,INPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
 */
int pos_180;


void arm_180() {
 

  
 pos_180=analogRead(A1);
 pos_180=pos_180/4;
  error = (req-pos_180);
  if(error<0)
  {
     digitalWrite(13 , HIGH);
     digitalWrite(12,  LOW);
  }
  else
  {
    digitalWrite(13 , LOW);
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
 
 //Serial.println(error);
  //Serial.println(pos_180_180_180_180_180_180_180_180_180);
  Serial.println(pwm);
   

}
