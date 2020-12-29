#include "PoliceCar2.h"

void PoliceCar2::draw() {
	this->matrix->drawRGBBitmap(0, 0, police_car2_bitmap, this->matrix->width(), this->matrix->height());
	this->matrix->swapBuffers(false);
}

void PoliceCar2::drawWithFlasher() {
	matrix->drawRGBBitmap(27, 1, police_car2_flasher_high, 11, 10);
	this->matrix->swapBuffers(false);
}
