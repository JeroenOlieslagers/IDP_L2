#include "last_resort.h"

void startMotors(DCMotor motor) {
	motor.start();
	motor.setMotors(1, 4);
	motor.setMotorSpeed(249, 240);
}

void runDist(DCMotor motor, long dist) {
	motor.runMotor(true, 'b');
	delay(dist);
	motor.runMotor(false, 'b');
}

void save_us(DCMotor motor) {
	startMotors(motor);
	runDist(motor, 15000);
  motor.turn('r');
  runDist(motor, 14000);
}
