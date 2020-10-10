#include "AllSwitchOnStrategy.h"

AllSwtichOnStrategy::AllSwtichOnStrategy(Led* leds, int ledsSize, int countOfCycle):LedSwitchingStrategy() {
	this->leds = leds;
	this->ledsSize = ledsSize;
	this->countOfCycle = countOfCycle;
	reset();
}

bool AllSwtichOnStrategy::processNextIteration() {
	if (this->isTurnOff) {
		for (int i = 0; i < this->ledsSize; i++) {
			this->leds[i].on();
		}
		this->isTurnOff = false;
	} else {
		for (int i = 0; i < this->ledsSize; i++) {
			this->leds[i].off();
		}
		this->isTurnOff = true;
		currentCycleNumber++;
	}

	if (currentCycleNumber >= countOfCycle) {
		reset();
		return true;
	} else {
		return false;
	}
}
