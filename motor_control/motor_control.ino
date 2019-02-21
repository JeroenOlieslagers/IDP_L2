#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

class Motor{
  //Motors are referred to as left and right ('l', 'r') not 1 and 2

  
  public:
  Adafruit_DCMotor *myMotorL = AFMS.getMotor(1);
  Adafruit_DCMotor *myMotorR = AFMS.getMotor(4);
  /*
  Motor(int mL, int mR){
    Adafruit_DCMotor *myMotorL = AFMS.getMotor(mL);
    Adafruit_DCMotor *myMotorR = AFMS.getMotor(mR);
  }*/
  
  void setMotors(int mL, int mR){
    Adafruit_DCMotor *myMotorL = AFMS.getMotor(mL);
    Adafruit_DCMotor *myMotorR = AFMS.getMotor(mR);
  }
  
  void setMotorSpeed(int mL, int mR){
    //Sets speed of motors
    myMotorL->setSpeed(mL);
    myMotorR->setSpeed(mR);
  }
  
  void runMotor(bool boo, char motor){
    //Runs or stops individual motors
    if (boo && (motor == 'l')){
      myMotorL->run(FORWARD);
    }
    if (boo && motor =='r'){
      myMotorR->run(FORWARD);
    }
    if (!boo && motor =='l'){
      myMotorL->run(RELEASE);
    }
    if (!boo && motor =='r'){
      myMotorR->run(RELEASE);
    }
    if (boo && motor =='b'){
      myMotorL->run(FORWARD);
      myMotorR->run(FORWARD);
    }
    if (!boo && motor =='b'){
      myMotorL->run(RELEASE);
      myMotorR->run(RELEASE);
    }
  }

  void turn(char dir){
    //Turns robot 'o' for 180 degrees turn
    if (dir == 'r'){
      myMotorL->run(FORWARD);
      delay(2900);
      myMotorL->run(RELEASE);
    }
    if (dir == 'l'){
      myMotorR->run(FORWARD);
      delay(2900);
      myMotorR->run(RELEASE);
    }
    if (dir == 'o'){
      myMotorL->run(FORWARD);
      delay(5800);
      myMotorL->run(RELEASE);
    }
  }
};

long count;
Motor motor;
void setup() {
  // put your setup code here, to run once:
  AFMS.begin();
  Serial.begin(9600);
  motor.setMotors(1, 4);
  motor.setMotorSpeed(255, 240);
}

void loop() {
  // put your main code here, to run repeatedly:
  count++;
  //tryStop();
  if (count == 1){
    motor.turn('r');
  }
}
