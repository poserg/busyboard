#include "SimpleStrategy.h"

SimpleStrategy::SimpleStrategy(Led* leds, int ledsSize):LedSwitchingStrategy() {
	this->leds = leds;
	this->ledsSize = ledsSize;
}

bool SimpleStrategy::processNextIteration() {
	if (currentLed == 0) {
		leds[ledsSize - 1].off();
	} else {
		leds[currentLed - 1].off();
	}
	leds[currentLed].on();

	if (currentLed >= ledsSize) {
		currentLed = 0;
		return true;
	} else {
		currentLed++;
		return false;
	}
}
