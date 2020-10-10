#include "Led.h"
#include "Button.h"
#include "LedPanel.h"
#include "SimpleStrategy.h"

#define LEFT_BUTTON_PIN 39
#define RIGHT_BUTTON_PIN 38
#define UP_BUTTON_PIN 40
#define DOWN_BUTTON_PIN 41

#define YELLOW_BUTTON_PIN 37
#define GREEN_BUTTON_PIN 35
#define BLUE_BUTTON_PIN 34
#define RED_BUTTON_PIN 36

#define YELLOW_LED_PIN 33
#define GREEN_LED_PIN 32
#define BLUE_LED_PIN 31
#define RED_LED_PIN 30

const int tumblerLedCount = 4;
Led tumblerLeds[tumblerLedCount] = { Led(YELLOW_LED_PIN), Led(GREEN_LED_PIN), Led(BLUE_LED_PIN), Led(RED_LED_PIN) };

const int strategiesCount = 1;
auto ss = new SimpleStrategy(tumblerLeds, tumblerLedCount);
LedSwitchingStrategy** strategies[strategiesCount] = { &ss };
auto tumblerLedPanel = new LedPanel(**strategies, 1);

void setup() {
	// Serial.begin(115200);

	pinMode(YELLOW_LED_PIN, OUTPUT);
	pinMode(GREEN_LED_PIN, OUTPUT);
	pinMode(BLUE_LED_PIN, OUTPUT);
	pinMode(RED_LED_PIN, OUTPUT);

	pinMode(YELLOW_BUTTON_PIN, INPUT_PULLUP);
	pinMode(GREEN_BUTTON_PIN, INPUT_PULLUP);
	pinMode(BLUE_BUTTON_PIN, INPUT_PULLUP);
	pinMode(RED_BUTTON_PIN, INPUT_PULLUP);

	pinMode(LEFT_BUTTON_PIN, INPUT_PULLUP);
	pinMode(RIGHT_BUTTON_PIN, INPUT_PULLUP);
	pinMode(UP_BUTTON_PIN, INPUT_PULLUP);
	pinMode(DOWN_BUTTON_PIN, INPUT_PULLUP);

	for (int i = 0; i< tumblerLedCount; i++) {
		tumblerLeds[i].off();
	}
}

void loop() {
	tumblerLedPanel->processNextIteration();
	delay(400);
}
