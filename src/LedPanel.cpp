#include "LedPanel.h"

LedPanel::LedPanel(Led** leds, int ledsSize) {
	this->strategiesSize = 3;
	auto ss = new SimpleStrategy(leds, ledsSize);
	auto asos = new AllSwtichOnStrategy(leds, ledsSize, 3);
	auto cs = new CarouselStrategy(leds, ledsSize);
	this->strategies = new LedSwitchingStrategy*[this->strategiesSize];
	this->strategies[0] = ss;
	this->strategies[1] = asos;
	this->strategies[2] = cs;
}

void LedPanel::processNextIteration() {
	auto currentMillis = millis();
	if (currentMillis - this->previousMillis < this->delay) {
		return;
	}

	this->previousMillis = currentMillis;
	bool isCompleted = strategies[currentStrategyIndex]->processNextIteration();
	if (isCompleted) {
		currentStrategyIndex++;
		if (currentStrategyIndex >= strategiesSize) {
			currentStrategyIndex = 0;
		}
	}
}
