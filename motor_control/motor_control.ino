#include "motor_control.h"

long count;
Mmotor motor;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor.setMotors(1, 4);
  motor.setMotorSpeed(255, 240);
}

void loop() {
  // put your main code here, to run repeatedly:
  count++;
  //tryStop();
  if (count == 1){
    motor.turn('r');
  }
}
