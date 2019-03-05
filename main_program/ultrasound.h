#pragma once

/*
Class for accessing the Ultrasound sensor reading.
Pins are set during class construction. This sets
appropriate pin to Input and Output. Distance to the nearest obstacle
is stored in usDistance and can be accessed through getValue(). The 
distance is taken when that function is called, and the class attribute
is updated.
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
ultrasound sensor reading. Pins are set when constructing the class.
getSpeedDiff updates the ultrasound sensor readings and uses them to calculate
the difference in speed that should be applied to motors. The difference 
should be added to the left motor.
getSpeedDiff is a P controller, distF comes from ultrasound sensor from front
of the robot. distB comes from ultrasound sensor from back of the robot.
*/

class UsReadingControl
{
  UsReading usReadingFront, usReadingBack;
  int speedDiff = 0;
<<<<<<< Updated upstream
  int prevDistance;
  const float kp = 1.0;
  const float kd = 1.0;
  const float samplingRate = 10.0;

=======
  const float kp = 0.2;
>>>>>>> Stashed changes
public:
  void setPins(int trigF, int echoF, int trigB, int echoB);
  int getFrontDist();
  int getBackDist();
  int getSpeedDiff();
};
