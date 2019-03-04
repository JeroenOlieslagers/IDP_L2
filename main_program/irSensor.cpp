#include "irSensor.h"

void IrReading::setPinNumber(int pin){
  pinNumber = pin;
}

void IrReading::updateValue()
{
  irReadingValue = analogRead(pinNumber);
}

int IrReading::getValue()
{
  return irReadingValue;
}


// update the colour of the line beneath the robot
void IrReadingColour::updateColour()
{
  // get the value of the attribute through the method
  irReadingValue = getValue();
  // determine the colour based on threshold
  if (irReadingValue<whiteThresh)
  {
    colour = white;
  }
  else if (irReadingValue<redThresh)
  {
    colour = red;
  }
  else if (irReadingValue<greenThresh)
  {
    colour = green;
  }
  else
  {
    colour = black;
  }
}

Colour IrReadingColour::getColour()
{
  return colour;
}

// Class method for printing the colour, returns a string
const char* IrReadingColour::getColourString()
{
  switch (colour)
  {
    case green: return "Green";
    case black: return "Black";
    case red: return "Red";
    case white: return "White";
    default: return "Undetermined - error";
  }
}

void irReadingStrip::updateRounds()
{
sensorIrValue = irR
if (!sensorLoHi && sensorIrValue > whiteThresh)
{
sensorLoHi = true;
noOfRounds++;
}
if (sensorLoHi && sensorIrValue < loIrThresh)
{
sensorLoHi = false;
}
}

int irReadingStrip::getRounds()
{
updateRounds();
return noOfRounds;
}

void irReadingStrip::resetRounds()
{
noOfRounds = 0;
}

void setTargetRounds(int target)
{
targetRounds = target;
}
