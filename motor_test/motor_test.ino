#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(4);

int count = 0;

void setup() {
  // put your setup code here, to run once:
  AFMS.begin();
  myMotor1->setSpeed(150);
  myMotor2->setSpeed(150);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  count++;
  
  if (count < 5){
    Serial.println(count);
    Serial.println(millis());
    delay(1000);
    myMotor1->run(FORWARD);
    myMotor2->run(FORWARD);
    delay(1000);
    myMotor1->run(BACKWARD);
    myMotor2->run(BACKWARD);
  }
  else{
    myMotor1->run(RELEASE);
    myMotor2->run(RELEASE);
  }
}
