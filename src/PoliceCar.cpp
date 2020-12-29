#include "PoliceCar.h"

void PoliceCar::draw() {
	this->matrix->drawRGBBitmap(0, 0, police_car_bitmap, this->matrix->width(), this->matrix->height());
	this->matrix->swapBuffers(false);
}

void PoliceCar::drawWithFlasher() {
	matrix->drawRGBBitmap(33, 4, police_car_flasher_high, 6, 5);
	this->matrix->swapBuffers(false);
}
