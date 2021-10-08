//Head rotation and chasis rotation. Back to same position after rotation.

#define M1 12
#define PWM1 11

//Motor 2
#define M2 28
#define PWM2 6

//Motor 3
#define M3 30
#define PWM3 7

//              46 = 13

int stpflag = 1;
int Distance = 0;
void setup() {
  pinMode(10, OUTPUT); //Step CLK+ 48
  pinMode(13, OUTPUT); //Direction CW+ 46
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(PWM3, OUTPUT);
  digitalWrite(13, LOW);

}

void loop() {
  //3200 for 360 degree rotation.
  if (Distance < 3200) {
    digitalWrite(10, HIGH); //stepper rotates
    delayMicroseconds(600); //Vary speed by decr/inc
    digitalWrite(10, LOW);
    delayMicroseconds(600);   //Vary speed by decr / inc
    Distance = Distance + 1; // record this step
    digitalWrite(M1 ,HIGH);
    digitalWrite(M2, HIGH);
    digitalWrite(M3 , LOW);
    analogWrite(PWM1 , 30);
    analogWrite(PWM2 , 30);
    analogWrite(PWM3 , 30);
  }
  else {
    digitalWrite(10, LOW);
    digitalWrite(M1 , LOW);
    digitalWrite(M2, LOW);
    digitalWrite(M3 , LOW);
    analogWrite(PWM1 , 0);
    analogWrite(PWM2 , 0);
    analogWrite(PWM3 , 0);
  }

}


//if(distance == 15){
//Start PWM
/*}
  else{
  digitalWrite(48, LOW);
  delay(2000);
  }
  }
  // put your main code here, to run repeatedly:*/
