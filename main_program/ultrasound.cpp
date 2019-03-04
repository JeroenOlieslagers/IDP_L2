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
  updateValue();
  return usDistance;
}

void UsReadingControl::setPins(int trigF, int echoF, int trigB, int echoB)
{
  Serial.println("Setting pins");
  usReadingFront.setPins(trigF, echoF);
  usReadingBack.setPins(trigB, echoB);
}

int UsReadingControl::getFrontDist()
{
  return usReadingFront.getValue();
}

int UsReadingControl::getBackDist()
{
  return usReadingBack.getValue();
}

int UsReadingControl::getSpeedDiff()
{
  // Reading distF is from sensor in the front of the robot. distB from
  // sensor in the back. Difference is added to the left
  // motor. If distB is bigger than distF, the robot
  // should turn right, so left motor speed should increase, so difference
  // should be positive.
  this->speedDiff = (int)round((usReadingBack.getValue() - usReadingFront.getValue())*kp);
  return speedDiff;
}
