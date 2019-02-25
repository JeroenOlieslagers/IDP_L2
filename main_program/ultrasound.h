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