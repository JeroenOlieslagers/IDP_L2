#ifndef last_resort_h
#define last_resort_h

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include "timer.h"
#include "motor_control.h"

//Initialises motors and servo
void startMotors(RobotMotor motor);

//Runs motor straight for a set distance
void runDist(RobotMotor motor, long dist);

//Combines runDist and DCMotor.turn functions to go around the arena without help of sensors
void save_us(RobotMotor motor);


#endif
