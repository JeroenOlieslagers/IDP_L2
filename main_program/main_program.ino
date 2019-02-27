#include "irSensor.h"
#include "motor_control.h"
#include "timer.h"
#include "ultrasound.h"

IrReadingColour irReadingColour;
UsReadingControl usControl;
RobotMotor motor;
Timer debugTimer;
Timer usTimer;
long count = 0;
int irSensorReading = 0;
Colour defaultColour = black;
bool startMotors = true;
int readingDelay = 100;
int readingDelayCounter = 0;

//Constant
const int US_SAMPLING_PERIOD = 10;

//Debugging
int a;

void setup() {
  Serial.begin(9600);
  motor.start();
  motor.setMotors(1,4);
  motor.setMotorSpeed(50, 50);
  irReadingColour.setPinNumber(A0);
  usControl.setPins(2, 3);
  usControl.setTargetDistance(20);
  debugTimer.reset();
  usTimer.reset();
  motor.runMotor(true, 'b');
}

void loop()
{
  /*
  if (readingDelayCounter == readingDelay)
  {
    irReadingColour.updateValue();
    irReadingColour.updateColour();
    Serial.println(irReadingColour.getColourString());
    readingDelayCounter = 0;
  }
  readingDelayCounter++;
  if (startMotors)
  {
    motor.runMotor(true, 'b');
    startMotors = false;
  }
  if (irReadingColour.getColour()!=defaultColour)
  {
    motor.runMotor(false, 'b');
  }*/
  /*
  if (debugTimer.getSeconds() == 3){
    motor.nudge(1);
  }*/

  if (usTimer.getTime() > US_SAMPLING_PERIOD){
    usControl.updateValue();
    a = usControl.getValue();
    //Serial.println(a);
    Serial.println(motor.currentL);
    Serial.println(motor.currentR);
    Serial.println(usControl.getSpeedDiff());
    usTimer.reset();
    motor.adjustSpeed(usControl.getSpeedDiff());
  }
  if (debugTimer.getSeconds() >= 15){
    motor.runMotor(false, 'b');
  }
  
}
