#include "motor_control.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotorL = AFMS.getMotor(1);
Adafruit_DCMotor *myMotorR = AFMS.getMotor(4);

void RobotMotor::start() {
	//Requirement for motor sheild to start
	AFMS.begin();
}

void RobotMotor::setMotors(int mL, int mR) {
	//Associated myMotor pointers with pins on motor shield
	Adafruit_DCMotor *myMotorL = AFMS.getMotor(mL);
	Adafruit_DCMotor *myMotorR = AFMS.getMotor(mR);
}

void RobotMotor::setMotorSpeed(int mL, int mR) {
  currentL = mL;
  currentR = mR;
	//Sets speed of motors
	myMotorL->setSpeed(mL);
	myMotorR->setSpeed(mR);
}

void RobotMotor::adjustSpeed(int diff){
  //Edge case that left motor reaches max speed
  if(currentL >= 255 - diff && currentR >= 2*diff){
    currentR -= diff;
  }
  else if(currentL >= 255 - diff){
    Serial.println('ERROR, CANNOT DECREASE R FURTHER');
  }
  //Edge case that right motor reaches min speed
  else if(currentL <= 255 - (2 * diff) && currentR <= diff){
    currentL += diff;
  }
  else if (currentL <= 255 - diff){
    currentL += diff;
    currentR -= diff;
  }
  else{
    Serial.println('wtf');
  }
  if (currentL > 255){
    currentL = 255;
  }
  if (currentL < 0){
    currentL = 0;
  }
  if (currentR > 255){
    currentR = 255;
  }
  if (currentR < 0){
    currentR = 0;
  }
  setMotorSpeed(currentL, currentR);
}

void RobotMotor::runMotor(bool boo, char motor) {
	//Runs or stops individual motors
	if (boo && (motor == 'l')) {
		myMotorL->run(FORWARD);
	}
	if (boo && motor == 'r') {
		myMotorR->run(FORWARD);
	}
	if (!boo && motor == 'l') {
		myMotorL->run(RELEASE);
	}
	if (!boo && motor == 'r') {
		myMotorR->run(RELEASE);
	}
	if (boo && motor == 'b') {
		myMotorL->run(FORWARD);
		myMotorR->run(FORWARD);
	}
	if (!boo && motor == 'b') {
		myMotorL->run(RELEASE);
		myMotorR->run(RELEASE);
	}
}

void RobotMotor::nudg(char dir){
  if (dir == 'r'){
    currentL -= 50;
    setMotorSpeed(currentL, currentR);
    delay(1000);
    currentL += 50;
    setMotorSpeed(currentL, currentR);
  }
}

void RobotMotor::turn(char dir) {
  //setMotorSpeed(240, 240);
  myMotorL->run(RELEASE);
  myMotorR->run(RELEASE);
	//Turns robot 'o' for 180 degrees turn
	if (dir == 'r') {
		myMotorL->run(FORWARD);
		delay(2900);
		myMotorL->run(RELEASE);
	}
	if (dir == 'l') {
		myMotorR->run(FORWARD);
		delay(2900);
		myMotorR->run(RELEASE);
	}
	if (dir == 'o') {
		myMotorL->run(FORWARD);
		delay(5800);
		myMotorL->run(RELEASE);
	}
 setMotorSpeed(currentL, currentR);
}
