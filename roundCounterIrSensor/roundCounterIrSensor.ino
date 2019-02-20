int sensorIrValue = 0;  // variable to store the value coming from the IR sensor
int noOfRoundsTarget = 15; // number of times a strip crosses the IR sensor
int noOfRounds = 0; // counter for the numebr of times a strip crosses the IR sensor
int highIrThresh = 750;
int loIrThresh = 730; // high and low thresholds for IR sensor
bool sensorLoHi = false; // variable for storing the previous state of IR reading

void setup() {
  Serial.begin(9600);
}

void loop() {
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
  Serial.println(noOfRounds);
}
