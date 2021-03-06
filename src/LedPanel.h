#ifndef SRC__LEDS_LEDPANEL_H_
#define SRC__LEDS_LEDPANEL_H_
#include "AllSwitchOnStrategy.h"
#include "SimpleStrategy.h"
#include "CarouselStrategy.h"

class LedPanel {
private:
	int strategiesSize;
	int currentStrategyIndex = 0;
	long previousMillis = 0;
	const long delay = 400;
	LedSwitchingStrategy** strategies;
public:
	LedPanel(Led** leds, int ledsSize);
	void processNextIteration();
};

#endif /* SRC__LEDS_LEDPANEL_H_ */
