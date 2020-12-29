#include "Car.h"

Car::Car(RGBmatrixPanel* matrix) {
	this->matrix = matrix;
}

void Car::processNextIteration() {
	if (!isFlasherOn) {
		isFlasherTurnedOn = false;
		draw();
		return;
	}
	auto currentMillis = millis();
	if (currentMillis - previousMillis < delay) {
		return;
	}
	previousMillis = currentMillis;
	if (!isFlasherTurnedOn) {
		isFlasherTurnedOn = true;
		drawWithFlasher();
	} else {
		isFlasherTurnedOn = false;
		draw();
	}
}

void Car::setIsFlasherOn(bool isOn) {
	this->isFlasherOn = isOn;
}
