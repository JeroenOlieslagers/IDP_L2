#include "ultrasound.h"
#include <Arduino.h>

void UsReading::setPins(int trig, int echo)
{
  this->trigPin = trig;
  this->echoPin = echo;
  pinMode(trig, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo, INPUT); // Sets the echoPin as an Input
}

void UsReading::updateValue()
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  this->usDistance = duration * 0.034 / 2;
}

int UsReading::getValue()
{
  return usDistance;
}

void UsReadingControl::setTargetDistance(int _targetDistance)
{
  this->targetDistance = _targetDistance;
}

int UsReadingControl::getSpeedDiff()
{
  this->prevDistance = getValue();
  updateValue();
  // Motor is mounted on the left side. Difference is added to the left
  // motor. If targetDistance is bigger than current distance, the robot
  // should turn right, so left motor speed should increase, so difference
  // should be positive.
  this->speedDiff = (int)round((targetDistance - getValue())*kp 
    + (getValue()-prevDistance)*kd/samplingRate);
  return speedDiff;
}
