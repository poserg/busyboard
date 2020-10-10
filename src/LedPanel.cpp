#include "LedPanel.h"

LedPanel::LedPanel(Led* leds, int ledsSize) {
	this->strategiesSize = 2;
	auto ss = new SimpleStrategy(leds, ledsSize);
	auto asos = new AllSwtichOnStrategy(leds, ledsSize, 3);
	this->strategies = new LedSwitchingStrategy*[this->strategiesSize];
	this->strategies[0] = ss;
	this->strategies[1] = asos;
}

void LedPanel::processNextIteration() {
	bool isCompleted = strategies[currentStrategyIndex]->processNextIteration();
	if (isCompleted) {
		currentStrategyIndex++;
		if (currentStrategyIndex >= strategiesSize) {
			currentStrategyIndex = 0;
		}
	}
}
