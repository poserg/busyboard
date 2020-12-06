#ifndef SRC_ALLSWITCHONSTRATEGY_H_
#define SRC_ALLSWITCHONSTRATEGY_H_

#include "LedSwitchingStrategy.h"

class AllSwtichOnStrategy: public LedSwitchingStrategy {
private:
	int ledsSize;
	int currentCycleNumber;
	int countOfCycle;
	bool isTurnOff;
	Led** leds;
	void reset() {
		this->currentCycleNumber = 0;
		this->isTurnOff = true;
	}
public:
	AllSwtichOnStrategy(Led** leds, int ledsSize, int countOfCycle);
	~AllSwtichOnStrategy() {};
	bool processNextIteration();
};

#endif /* SRC_ALLSWITCHONSTRATEGY_H_ */
