#ifndef SRC_CAROUSELSTRATEGY_H_
#define SRC_CAROUSELSTRATEGY_H_

#include "LedSwitchingStrategy.h"

class CarouselStrategy: public LedSwitchingStrategy {
	int ledsSize;
	int currentLed = 0;
	Led** leds;
	bool isSwitchOnCycle = true;
public:
	CarouselStrategy(Led** leds, int ledsSize);
	~CarouselStrategy() {};
	bool processNextIteration();
};

#endif /* SRC_CAROUSELSTRATEGY_H_ */
