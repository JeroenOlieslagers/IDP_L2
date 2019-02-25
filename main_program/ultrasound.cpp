#include "ultrasound.h"
#include <Arduino.h>

void UsReading::setPins(int trig, int echo)
{
  this->trigPin = trig;
  this->echoPin = echo;
  pinMode(2, OUTPUT); // Sets the trigPin as an Output
  pinMode(3, INPUT); // Sets the echoPin as an Input
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
