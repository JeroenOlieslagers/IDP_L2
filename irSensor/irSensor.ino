int sensorIrValue = 0;  // variable to store the value coming from the IR sensor
int noOfRoundsTarget = 15; // number of times a strip crosses the IR sensor
char * irPort = "A0";

class StripCrossCounter
{
    int noOfRounds=0, sensorLoHi=0, highIrThresh=750, loIrThresh=730;
  public:
    void updateRounds();
    int getRounds();
    void resetRounds();
};

void StripCrossCounter::updateRounds()
{
  sensorIrValue = analogRead(A0);
  Serial.println(sensorIrValue);
  if (!sensorLoHi && sensorIrValue > highIrThresh)
  {
    sensorLoHi = true;
    noOfRounds++;
  }
  if (sensorLoHi && sensorIrValue < loIrThresh)
  {
    sensorLoHi = false;
  }
}

int StripCrossCounter::getRounds()
{
  return noOfRounds;
}

void StripCrossCounter::resetRounds()
{
  noOfRounds = 0;
}

void setup() {
  Serial.begin(9600);
}

StripCrossCounter stripCrossCounter;
void loop()
{
  stripCrossCounter.updateRounds();
  Serial.println(stripCrossCounter.getRounds());
  if (stripCrossCounter.getRounds()>3)
  {
    stripCrossCounter.resetRounds();
  }
}
