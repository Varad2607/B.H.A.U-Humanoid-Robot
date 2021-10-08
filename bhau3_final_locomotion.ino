
#include<SoftwareSerial.h>
#include "define.h"
SoftwareSerial BT(A14, A15); //RX TX
char c;

void setup()
{
  BT.begin(9600);
  Serial.begin(9600);

  pinMode(PWM1, OUTPUT); //PW1
  pinMode(PWM2, OUTPUT); //PW2
  pinMode(PWM3, OUTPUT); //PW3
  pinMode(M1, OUTPUT); //DIR 1
  pinMode(M2, OUTPUT); //DIR 2
  pinMode(M3, OUTPUT); //DIR 3
  
}
void loop()
{

  if (BT.available())
  {
    c = BT.read();

  }
 


switch (c) {
case 'l':
  Serial.println("clockwise");
  digitalWrite(M1 , LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(M3 , LOW);
  analogWrite(PWM1 , 30);
  analogWrite(PWM2, 30);
  analogWrite(PWM3, 30);
  break;
case 'r':
  Serial.println("anticlockwise");
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M3 , HIGH);
  analogWrite(PWM1 , 30);
  analogWrite(PWM2 , 30);
  analogWrite(PWM3, 30);
  break;
case 's':
  Serial.println("stop");
  digitalWrite(M1 , HIGH);
  digitalWrite(M2, HIGH);
  digitalWrite(M3, HIGH);
  analogWrite(PWM1, 0);
  analogWrite(PWM2, 0);
  analogWrite(PWM3, 0);
  break;
case 'S':
  Serial.println("FORWARD");
  digitalWrite(M1 , LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(M3 , HIGH);
  analogWrite(PWM1 , 0);
  analogWrite(PWM2, 35);
  analogWrite(PWM3 , 35);
  break;
case 'B':
  Serial.println("BACK");
  digitalWrite(M1 , LOW);
  digitalWrite(M2, LOW);
  digitalWrite(M3 , LOW);
  analogWrite(PWM1, 0);
  analogWrite(PWM2, 40);
  analogWrite(PWM3, 40);
  break;
case 'L':
  Serial.println("RIGHT");
  digitalWrite(M1 , HIGH);
  digitalWrite(M2, HIGH);
  digitalWrite(M3 , LOW);
  analogWrite(PWM1 , 60);
  analogWrite(PWM2, 35);
  analogWrite(PWM3 , 35);
  break;
case 'R':
  Serial.println("LEFT");
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(M3 , HIGH);
  analogWrite(PWM1 , 60);
  analogWrite(PWM2, 35);
  analogWrite(PWM3, 35);
  break;
default:
  Serial.println("stop");
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  digitalWrite(M3 , HIGH);
  analogWrite(PWM1, 0);
  analogWrite(PWM2, 0);
  analogWrite(PWM3, 0);
  break;

}

}
