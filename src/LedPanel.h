#ifndef SRC__LEDS_LEDPANEL_H_
#define SRC__LEDS_LEDPANEL_H_
#include "LedSwitchingStrategy.h"

class LedPanel {
private:
	int strategiesSize;
	int currentStrategyIndex = 0;
	LedSwitchingStrategy* strategies;
public:
	LedPanel(LedSwitchingStrategy* strategies, int strategiesSize);
	void processNextIteration();
};

#endif /* SRC__LEDS_LEDPANEL_H_ */
