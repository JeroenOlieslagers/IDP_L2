#include "motor_control.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotorL = AFMS.getMotor(1);
Adafruit_DCMotor *myMotorR = AFMS.getMotor(4);

void Mmotor::begin() {
	AFMS.begin();
}

void Mmotor::setMotors(int mL, int mR) {
	Adafruit_DCMotor *myMotorL = AFMS.getMotor(mL);
	Adafruit_DCMotor *myMotorR = AFMS.getMotor(mR);
}

void Mmotor::setMotorSpeed(int mL, int mR) {
	//Sets speed of motors
	myMotorL->setSpeed(mL);
	myMotorR->setSpeed(mR);
}

void Mmotor::runMotor(bool boo, char motor) {
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

void Mmotor::turn(char dir) {
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
}


