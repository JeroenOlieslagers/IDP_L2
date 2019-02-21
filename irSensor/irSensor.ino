int sensorIrValue = 0;  // variable to store the value coming from the IR sensor
int noOfRoundsTarget = 15; // number of times a strip crosses the IR sensor
//char * irPort = "A0"; // port to which IR sensor is connected

/* 
 *  Main class for InfraRed readings, contains threshold for white
 *  used by both the color sensor and strip counter
*/
class IrReading
{
    int irReadingValue = 0;
    char irPort;
  public:
    void setPort(char);
    void updateValue();
    int getValue();
};

void IrReading::setPort(char portNumber)
{
  irPort = portNumber;
}

void IrReading::updateValue()
{
  sensorIrValue = analogRead(A0);
  irReadingValue = sensorIrValue;
}

int IrReading::getValue()
{
  return irReadingValue;
}

// enum class used to store the detected colour of the strip beneath the robot
enum Colour {black, white, red, green};
// Class for InfraRed colour detector 
class IrReadingColour: public IrReading
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

// update the colour of the line beneath the robot
void IrReadingColour::updateColour()
{
  // get the value of the attribute through the method
  irReadingValue = getValue();
  // determine the colour based on threshold
  if(irReadingValue<whiteThresh)
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
  switch(colour)
  {
    case green: return "Green";
    case black: return "Black";
    case red: return "Red";
    case white: return "White";
  }
}
/*
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
*/

IrReadingColour irReadingColour;
void setup() {
  Serial.begin(9600);
}

void loop()
{
  irReadingColour.updateValue();
  irReadingColour.updateColour();
  Serial.println(irReadingColour.getColourString());
  delay(100);
}
