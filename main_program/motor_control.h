#ifndef motor_control_h
#define motor_control_h

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

class Mmotor {
	//Motors are referred to as left and right ('l', 'r') not 1 and 2
public:
	void begin();

	void setMotors(int mL, int mR);

	void setMotorSpeed(int mL, int mR);

	void runMotor(bool boo, char motor);

	void turn(char dir);
};



#endif