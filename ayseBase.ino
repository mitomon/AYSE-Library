/*
 *Autonomous Yard Scooping Entity 
 *Created by mitomon 6/14/2018
*/

#include <Servo.h>
#include <Wire.h>
#include <I2C_Anything.h>

Servo armVos;
Servo scoopVo1;
Servo scoopVo2;
int armAngle;
int angleVo1;
int angleVo2;

boolean isRemembering = false;
int theBegin;
int theEnd;
void setArmPos(int armPos){
    armVos.write(armPos);
}
void setScoopPos(int scoopPos){
   scoopVo1.write(scoopPos);
   scoopVo2.write(180-scoopPos);
}
void brake(){
  //turn on the brakes
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
}
void moveA(boolean direction, int speed){
  //Deactivate Brakes
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
  if(!direction){  
    //Establish forward direction
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }else{
    //Establish backward direction
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
  }
  if(speed == 1){
    //Set motors to 25% speed
    analogWrite(3,64);
    analogWrite(11,64);
  }
  if(speed == 2){
    //Set motors to 50% speed
    analogWrite(3,128);
    analogWrite(11,128);
  }
  if(speed == 3){
    //Set motors to 75% speed
    analogWrite(3,192);
    analogWrite(11,192);
  }
  if(speed == 4){
    //Set motors to 100% speed
    analogWrite(3,255);
    analogWrite(11,255);
  }
}
void turn(boolean direction, int speed){
  if(!direction){
    //spin left
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    //Deactivate brakes
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    if(speed == 1){
    //Set motors to 25% speed
    analogWrite(3,64);
    analogWrite(11,64);
  }
  if(speed == 2){
    //Set motors to 50% speed
    analogWrite(3,128);
    analogWrite(11,128);
  }
  if(speed == 3){
    //Set motors to 75% speed
    analogWrite(3,192);
    analogWrite(11,192);
  }
  if(speed == 4){
    //Set motors to 100% speed
    analogWrite(3,255);
    analogWrite(11,255);
  }
  }
  if(direction){
    //spin right
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    //Deactivate brakes
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    if(speed == 1){
    //Set motors to 25% speed
    analogWrite(3,64);
    analogWrite(11,64);
  }
  if(speed == 2){
    //Set motors to 50% speed
    analogWrite(3,128);
    analogWrite(11,128);
  }
  if(speed == 3){
    //Set motors to 75% speed
    analogWrite(3,192);
    analogWrite(11,192);
  }
  if(speed == 4){
    //Set motors to 100% speed
    analogWrite(3,255);
    analogWrite(11,255);
  }
  }
}
void setup() {
//Particle inputs
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
//Infineon Sensor Outputs
  pinMode(7,OUTPUT);
//Motor Setup  
  //Direction A
  pinMode(12,OUTPUT);
  //Direction B
  pinMode(13,OUTPUT);
  //Brake A
  pinMode(9,OUTPUT);
  //Brake B
  pinMode(8,OUTPUT);
  //Speed A
  pinMode(3,OUTPUT);
  //Speed B
  pinMode(11,OUTPUT);
//Servo Setup
  //Arm servos
  armVos.attach(10);
  //Scoop servos
  scoopVo1.attach(5);
  scoopVo2.attach(6);

  
  Wire.begin (21);
  Wire.onReceive (receiveEvent);
  Serial.begin(9600);  // start serial for output
}
volatile boolean haveData = false;
volatile float disTrav;

void loop() {

  //The weird logic is because the photon's D0 and D1 pins are PMW 
  //This way no jumper wires between the arduino and photon are needed
  if((analogRead(A0)>120)&&(analogRead(A0)<200)){
    //setScoopPos(100);
    setArmPos(85);
  }else if(analogRead(A0)<100){
    //setScoopPos(100);
    setArmPos(113);
  }
  //The Autonomous Mode button can be remapped here as I work on improving the actual autonomy part
  if((analogRead(A1)>120)&&(analogRead(A1)<200)){
    setScoopPos(100);
    //setArmPos(85);
  }else if(analogRead(A1)<100){
    setScoopPos(18 0);
    //setArmPos(113);
  }

  brake();
  if(digitalRead(A2)==HIGH){
    moveA(0,2);
  }
  if(digitalRead(A3)==HIGH){
    moveA(1,2);
  }
  if(digitalRead(A4)==HIGH){
    turn(false,2);
  }
  if(digitalRead(A5)==HIGH){
    turn(true,2);
  }
  
  
  //talking to infineon slave
if (haveData)
    {
  //  Serial.print ("Distance Travelled = ");
   // Serial.println (disTrav);
    haveData = false;
    }  // end if haveData

}// ends loop

// called by interrupt service routine when incoming data arrives
void receiveEvent (int howMany)
 {
 if (howMany >= (sizeof disTrav))
   {
   I2C_readAnything (disTrav);
   haveData = true;
   }  // end if have enough data
 }  // end of receiveEvent


