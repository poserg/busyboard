#include "LedPanel.h"
#include <Arduino.h>

LedPanel::LedPanel(LedSwitchingStrategy* strategies, int strategiesSize) {
	this->strategies = strategies;
	this->strategiesSize = strategiesSize;
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
