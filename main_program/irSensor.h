#pragma once

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

class IrReading
{
  int irReadingValue = 0;
  int pinNumber = A0;
  char irPort;
public:
  void updateValue();
  void setPinNumber(int);
  int getValue();
};

// enum class used to store the detected colour of the strip beneath the robot
enum Colour { black, white, red, green };

// Class for InfraRed colour detector 
class IrReadingColour : public IrReading
{
  int irReadingValue = 0;
  Colour colour = black;
  // Upper thresholds for white, red and green stripes determined experimentally
  int redThresh = 600, greenThresh = 800, whiteThresh = 80;
public:
  void updateColour();
  Colour getColour();
  const char* getColourString();
};

class irReadingStrip :: public irReading
{
int irReadingValue = 0;
int noOfRounds = 0, targetRounds = 0;
int whiteThresh = 80;
bool sensorLoHi = false;
public:
void updateRounds();
void resetRounds();
int getRounds();
void setTargetRounds(int);
};
