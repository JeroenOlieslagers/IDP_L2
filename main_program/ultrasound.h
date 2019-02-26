#pragma once

/*
Class for accessing the Ultrasound sensor reading.
In setup, set the trigger and echo pins using setPins(). This sets
appropriate pin to Input and Output. Distance to the nearest obstacle
is stored in usDistance and can be accessed through getValue(). Before
accessing the value, make sure the reading is up to date using 
updateValue().
*/

class UsReading
{
  int usDistance = 0;
  int trigPin = 0;
  int echoPin = 0;
public:
  void setPins(int trig, int echo);
  void updateValue();
  int getValue();
};

/*
Class for motor control system for driving in a straight line using
ultrasound sensor reading. Set the trigger and echo pins using setPins().
getSpeedDiff updates the ultrasound sensor reading and uses it to calculate
the difference in speed that should be applied to motors. The difference 
should be added to the left motor assuming the ultrasound sensor is mounted
on the LHS of the chassis.
*/

class UsReadingControl: public UsReading
{
  int targetDistance = 0;
  int usDistance = 0;
  int speedDiff = 0;
  const int kp = 3;
public:
  void setTargetDistance(int);
  int getSpeedDiff();
};