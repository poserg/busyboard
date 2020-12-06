#include "CarouselStrategy.h"

CarouselStrategy::CarouselStrategy(Led** leds, int ledsSize):LedSwitchingStrategy() {
	this->leds = leds;
	this->ledsSize = ledsSize;
}

bool CarouselStrategy::processNextIteration() {
	if (currentLed >= ledsSize) {
		currentLed = 0;
		if (isSwitchOnCycle) {
			isSwitchOnCycle = false;
			return false;
		} else {
			isSwitchOnCycle = true;
			return true;
		}
	}
	if (isSwitchOnCycle) {
		leds[currentLed]->on();
	} else {
		leds[currentLed]->off();
	}
	currentLed++;
	return false;
}
