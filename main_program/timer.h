#ifndef timer_h
#define timer_h

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

class Timer {
	long initTime;
	long passedTime;
public:
	//Resets timer (also needed for initialisation
	void reset();

	//Returns time (in milliseconds) since last reset
	int getTime();

	//Retusn time (to nearest second) since last reset
	int getSeconds();
};




#endif