#ifndef SRC_LEDS__STRATEGIES_LEDSWITCHINGSTRATEGY_H_
#define SRC_LEDS__STRATEGIES_LEDSWITCHINGSTRATEGY_H_

#include "Led.h"

class LedSwitchingStrategy {
public:
	virtual ~LedSwitchingStrategy() {};
	virtual bool processNextIteration() = 0;
};

#endif /* SRC_LEDS__STRATEGIES_LEDSWITCHINGSTRATEGY_H_ */
