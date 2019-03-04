#ifndef last_resort_h
#define last_resort_h

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include "timer.h"
#include "motor_control.h"

void startMotors(RobotMotor motor);

void runDist(RobotMotor motor, long dist);

void save_us(RobotMotor motor);


#endif
