#include "irSensor.h"
#include "motor_control.h"

IrReadingColour irReadingColour;
Mmotor motor;
long count;
int irSensorReading = 0;
Colour defaultColour = black;
bool startMotors = true;
int readingDelay = 100;
int readingDelayCounter = 0;

void setup() {
  Serial.begin(9600);
  motor.setMotors(1,4);
  motor.setMotorSpeed(255, 240);
}

void loop()
{
  /*if (readingDelayCounter == readingDelay)
  {
    irSensorReading = analogRead(A0);
    irReadingColour.updateValue(irSensorReading);
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
  */
  count++;
  if (count == 1){
    motor.turn('r');
  }
}
