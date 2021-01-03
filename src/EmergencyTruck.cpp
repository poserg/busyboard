#include "EmergencyTruck.h"

void EmergencyTruck::draw() {
	this->matrix->drawRGBBitmap(0, 0, emergency_truck_bitmap, this->matrix->width(), this->matrix->height());
	this->matrix->swapBuffers(false);
}

void EmergencyTruck::drawWithFlasher() {
	matrix->drawRGBBitmap(31, 1, emergency_truck_flasher_high, 11, 7);
	this->matrix->swapBuffers(false);
}
