#include "timer.h"

void Timer::reset() {
	initTime = millis();
}

long Timer::getTime() {
	passedTime = millis();
	return passedTime - initTime;
}

int Timer::getSeconds() {
	passedTime = millis();
	int dummy = (passedTime - initTime) / 1000;
	return dummy;
}
