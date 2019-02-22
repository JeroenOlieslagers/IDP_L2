#pragma once

class IrReading
{
  int irReadingValue = 0;
  char irPort;
public:
  void updateValue(int);
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
