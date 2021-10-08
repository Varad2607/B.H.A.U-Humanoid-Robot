/*float error, integral = 0;
  int pos, req=57, pwm;
  float kp=1.5, ki=0.005; */
 
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(A1,INPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
 

}

void candle {
 pos=analogRead (A1);
 pos=pos/4;
  error = (req-pos);
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
 
 Serial.println(error);
  Serial.println(pos);
  Serial.println(pwm);
  
}

void loop() {
candle();
}
