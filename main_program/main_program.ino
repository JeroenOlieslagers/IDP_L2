#include "irSensor.h"

IrReadingColour irReadingColour;
void setup() {
  Serial.begin(9600);
}

int irSensorReading = 0;
void loop()
{
  irSensorReading = analogRead(A0);
  irReadingColour.updateValue(irSensorReading);
  irReadingColour.updateColour();
  Serial.println(irReadingColour.getColourString());
  delay(100);
}
