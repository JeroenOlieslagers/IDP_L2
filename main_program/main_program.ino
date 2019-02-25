#include "irSensor.h"
#include "motor_control.h"

IrReadingColour irReadingColour;
RobotMotor motor;
long count;
int irSensorReading = 0;
Colour defaultColour = black;
bool startMotors = true;
int readingDelay = 100;
int readingDelayCounter = 0;

void setup() {
  Serial.begin(9600);
  motor.start();
  motor.setMotors(1,4);
  motor.setMotorSpeed(255, 240);
  irReadingColour.setPinNumber(A0);
}

void loop()
{
  
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
  }
  /*
  count++;
  if (count == 1){
    motor.runMotor(true, 'b');
  }
  */
}
