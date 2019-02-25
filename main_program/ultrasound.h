#pragma once
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