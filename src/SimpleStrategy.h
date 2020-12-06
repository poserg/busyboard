#ifndef SRC_LEDS_STRATEGIES_SIMPLESTRATEGY_H_
#define SRC_LEDS_STRATEGIES_SIMPLESTRATEGY_H_

#include "LedSwitchingStrategy.h"

class SimpleStrategy: public LedSwitchingStrategy {
private:
	int ledsSize;
	int currentLed = 0;
	Led** leds;
public:
	SimpleStrategy(Led** leds, int ledsSize);
	~SimpleStrategy() {};
	bool processNextIteration();
};

#endif /* SRC_LEDS_STRATEGIES_SIMPLESTRATEGY_H_ */
