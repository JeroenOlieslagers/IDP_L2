#include "irSensor.h"
#include "motor_control.h"
#include "timer.h"
#include "ultrasound.h"
#include "last_resort.h"
#include <Servo.h>

Servo servo;

IrReadingColour irReadingColour;
UsReadingControl usControl;
DCMotor motor;
//RobotServo servo;
Timer debugTimer;
Timer usTimer;
long count = 0;
int irSensorReading = 0;
Colour defaultColour = black;
//bool startMotors = true;
int readingDelay = 100;
int readingDelayCounter = 0;

//Constant
const int US_SAMPLING_PERIOD = 10;
const long DISTANCE_1 = 10000;
const long DISTANCE_2 = 1000;
const long AMOUNT = 500;

//Debugging
int nice = 0;
int pos = 0;


void setup() {
  servo.attach(10);
  
  Serial.begin(9600);
  motor.start();
  //servo.setServoSpeed(60);
  motor.setMotors(1,4);
  motor.setMotorSpeed(253, 240);
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
  { m 
    motor.runMotor(false, 'b');
  }*/
  /*
  if (usTimer.getTime() > US_SAMPLING_PERIOD){
    usControl.updateValue();
    a = usControl.getValue();
    //Serial.println(a);
    //Serial.println(motor.currentL);
    //Serial.println(motor.currentR);
    Serial.println("US READING: ");
    Serial.println(a);
    Serial.println(usControl.getSpeedDiff());
    usTimer.reset();
    motor.adjustSpeed(usControl.getSpeedDiff());
  }*/
  /*
  if (debugTimer.getTime() > (DISTANCE_1 - AMOUNT) && debugTimer.getTime() > DISTANCE_1){
    motor.runMotor(false, 'b');
    delay(500);
    motor.turn('r');
    delay(500);
    //motor.runMotor(true, 'b');
  }*/
  /*
  if (debugTimer.getSeconds() == 0){
      save_us(motor);
  }*/
  
  if (debugTimer.getSeconds() == 3){
    motor.giveNudge('r');
    //motor.runMotor(false, 'b');
  }
  /*
  else{
    nice++;
    servo.write(nice);
    delay(50);
  }
  *//*
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }*/
}
