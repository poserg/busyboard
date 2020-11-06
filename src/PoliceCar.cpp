#include "PoliceCar.h"

PoliceCar::PoliceCar(RGBmatrixPanel* matrix) {
	this->matrix = matrix;
}

void PoliceCar::draw() {
	this->matrix->drawRGBBitmap(0, 0, bitmap, this->matrix->width(), this->matrix->height());
	this->matrix->swapBuffers(false);
}

void PoliceCar::processNextIteration() {
//	auto currentMillis = millis();
//	if (currentMillis - previousMillis < delay) {
//		return;
//	}
	if (isFlasherOn) {
		matrix->drawRGBBitmap(0, 0, bitmap, matrix->width(), matrix->height());
		matrix->drawRGBBitmap(33, 4, flasher_high, 6, 5);
		this->matrix->swapBuffers(false);
	} else {
		draw();
	}
}

void PoliceCar::setIsFlasherOn(bool isOn) {
	this->isFlasherOn = isOn;
}
