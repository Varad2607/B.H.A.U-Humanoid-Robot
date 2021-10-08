#include "Pin_Define.h"
#include "180deg_arm_move.h"
#include "candle.h"
#include "lifting.h"
#include<SoftwareSerial.h>
SoftwareSerial BT(A0,A1);//RX TX      //M1 10 //  M2 8 //M3 9
char c,C;
int pos;
void setup()
{
BT.begin(9600);
Serial.begin(9600);

pinMode(PWM1, OUTPUT); //PW1
pinMode(PWM2,OUTPUT); //PW2
pinMode(PWM3, OUTPUT); //PW3
pinMode(M1,OUTPUT); //DIR 1
pinMode(M2,OUTPUT);  //DIR 2
pinMode(M3,OUTPUT); //DIR 3
}
void loop() 
{
 if(Serial.available())
 {
  c=Serial.read();
 }
 if(BT.available())
 {
  c = BT.read();
 }
 switch(c){
 case 'l':
 Serial.println("clockwise");     //All 3 LOW if Clockwise
 digitalWrite(M1 , LOW);
 digitalWrite(M2, LOW);
 digitalWrite(M3 ,LOW);
 analogWrite(PWM1 ,30);
 analogWrite(PWM2 ,30);
 analogWrite(PWM3 ,30);
 break;
 case 'r':
 Serial.println("anticlockwise");       //All 3 HIGH if anticlockwise
 digitalWrite(M1, HIGH);
 digitalWrite(M2, HIGH);
 digitalWrite(M3, HIGH);
 analogWrite(PWM1 , 30);
 analogWrite(PWM2 , 30);
 analogWrite(PWM3 , 30);
 break;
 case 's':
 Serial.println("stop");
 digitalWrite(M1 , HIGH);
 digitalWrite(M2, HIGH);
 digitalWrite(M3 ,HIGH);
 analogWrite(PWM1, 0);
 analogWrite(PWM2, 0);
 analogWrite(PWM3, 0);
 break;
 case 'B':
 Serial.println("straight");
 digitalWrite(M1 ,HIGH);
 digitalWrite(M2 ,LOW);
 digitalWrite(M3 ,HIGH);
 analogWrite(PWM1, 30);
 analogWrite(PWM2, 0);
 analogWrite(PWM3,30);
 break;
 case 'S':
 Serial.println("straight");
 digitalWrite(M1 , LOW);
 digitalWrite(M2, HIGH);
 digitalWrite(M3 ,HIGH);
 analogWrite(PWM1 , 30);
 analogWrite(PWM2, 0);
 analogWrite(PWM3,30);
 break;
 case 'R':
 Serial.println("RIGHT");
 digitalWrite(M1 ,LOW);
 digitalWrite(M2,LOW);
 digitalWrite(M3 ,HIGH);
 analogWrite(PWM1 ,30);
 analogWrite(PWM2 ,60);
 analogWrite(PWM3 ,30);
 break;
 case 'L':
 Serial.println("LEFT");
 digitalWrite(M1 , HIGH);
 digitalWrite(M2 ,HIGH);
 digitalWrite(M3 ,LOW);
 analogWrite(PWM1 , 30);
 analogWrite(PWM2, 60);
 analogWrite(PWM3,30);
 break;
 case 'stepper':

  
  while(1){
  Serial.println("Stepper")
  if (Distance < 1600)   //Rotation by 180 degree
    {
      digitalWrite(STP_STEP, HIGH); //stepper rotates
      delayMicroseconds(1000);
      digitalWrite(STP_STEP, LOW);
      delayMicroseconds(1000);
      Distance = Distance + 1; // record this step
    }
    else if (Distance == 1600) {  //180 degree
      digitalWrite(STP_STEP, LOW);
      Distance = 0;
      break;
    }
  }
  break;
 
  default:
 Serial.println("stop");
 digitalWrite(M1 , HIGH);
 digitalWrite(M2, HIGH);
 digitalWrite(M3 ,HIGH);
 analogWrite(PWM1 , 0);
 analogWrite(PWM2 , 0);
 analogWrite(PWM3 ,0);
 break;
 }

analogWrite(PWM1 , 0);
analogWrite(PWM2 , 0);
analogWrite(PWM3 ,0);

 
}
