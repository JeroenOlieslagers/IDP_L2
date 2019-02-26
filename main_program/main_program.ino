#include "irSensor.h"
#include "motor_control.h"
#include "timer.h"

IrReadingColour irReadingColour;
RobotMotor motor;
Timer usTimer;
long count = 0;
int irSensorReading = 0;
Colour defaultColour = black;
bool startMotors = true;
int readingDelay = 100;
int readingDelayCounter = 0;

void setup() {
  Serial.begin(9600);
  motor.start();
  motor.setMotors(1,4);
  motor.setMotorSpeed(200, 200);
  irReadingColour.setPinNumber(A0);
  usTimer.reset();
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
  count++;
  if (count == 1){
    motor.runMotor(true, 'b');
  }
  if (count == 5){
    motor.adjustCourse(40);
  }
  delay(500);*/
  delay(1000);
  Serial.println(usTimer.getTime());
  usTimer.reset();
}
