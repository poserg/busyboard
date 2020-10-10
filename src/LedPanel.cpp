#include "LedPanel.h"
#include "SimpleStrategy.h"
#include <Arduino.h>

LedPanel::LedPanel(Led* leds, int ledsSize) {
	this->strategiesSize = 1;
	LedSwitchingStrategy* strategies[this->strategiesSize] = { new SimpleStrategy(leds, ledsSize) };
	this->strategies = *strategies;
}

void LedPanel::processNextIteration() {
	Serial.println("Start led panel start process");
	bool isCompleted = strategies[currentStrategyIndex].processNextIteration();
	if (isCompleted) {
		Serial.print("isComoleted");
		currentStrategyIndex++;
		if (currentStrategyIndex >= strategiesSize) {
			currentStrategyIndex = 0;
		}
	}
}
