#include "Led.h"
#include "Button.h"
#include "LedPanel.h"

#include "PoliceCar.h"

// управляющие пины матрицы
#define CLK   11
#define OE    9
#define LAT   10
#define A     A0
#define B     A1
#define C     A2
#define D     A3

// объявляем объект для работы с матрицей 64х32
// включаем двойную буферизацию
RGBmatrixPanel* matrix = new RGBmatrixPanel(A, B, C, D, CLK, LAT, OE, true, 64);

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

#define BIG_GREEN_LED 44
#define BIG_BLUE_LED 42

const int tumblerLedCount = 4;
Led tumblerLeds[tumblerLedCount] = { Led(YELLOW_LED_PIN), Led(GREEN_LED_PIN), Led(BLUE_LED_PIN), Led(RED_LED_PIN) };
auto tumblerLedPanel = new LedPanel(tumblerLeds, tumblerLedCount);

const int buttonLedCount = 2;
Led buttonLeds[buttonLedCount] = { Led(BIG_GREEN_LED), Led(BIG_BLUE_LED) };
auto buttonLedPanel = new LedPanel(buttonLeds, buttonLedCount);

auto car = new PoliceCar(matrix);
Button upButton(UP_BUTTON_PIN);

void setup() {
	matrix->begin();
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

	for (int i = 0; i < tumblerLedCount; i++) {
		tumblerLeds[i].off();
	}
	for (int i = 0; i < buttonLedCount; i++) {
		buttonLeds[i].off();
	}

	car->draw();
}

void loop() {
	car->setIsFlasherOn(!upButton.isPressed());
	tumblerLedPanel->processNextIteration();
	buttonLedPanel->processNextIteration();
	car->processNextIteration();
}
